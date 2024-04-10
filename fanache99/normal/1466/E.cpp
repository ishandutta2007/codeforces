#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cassert>
#include <map>
#include <numeric>
#include <cstring>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <unordered_set>

using namespace std;

class InputReader {
public:
    InputReader() {}
    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }
    inline InputReader &operator >>(int &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
    inline InputReader &operator >>(long long &n) {
        while((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
            n = n * 10 + buffer[cursor] - '0';
            advance();
        }
        n *= sign;
        return *this;
    }
private:
    FILE *input_file;
    static const int SIZE = 1 << 17;
    int cursor;
    char buffer[SIZE];
    inline void advance() {
        ++ cursor;
        if(cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 500000;
const int MAXLOG = 60;
const int MOD = 1000000007;

long long v[1 + MAXN];
int have1[MAXLOG], have2[MAXLOG][MAXLOG], bits[MAXLOG];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            int b = 0;
            for (int j = 0; j < MAXLOG; j++) {
                if (v[i] & (1LL << j)) {
                    bits[b] = j;
                    b++;
                }
            }
            for (int b1 = 0; b1 < b; b1++) {
                have1[bits[b1]]++;
                for (int b2 = b1 + 1; b2 < b; b2++) {
                    have2[bits[b1]][bits[b2]]++;
                }
            }
        }
        int answer = 0;
        for (int b1 = 0; b1 < MAXLOG; b1++) {
            for (int b2 = 0; b2 < MAXLOG; b2++) {
                int product = ((1LL << b1) % MOD) * ((1LL << b2) % MOD) % MOD, howMany;
                if (b1 == b2) {
                    howMany = 1LL * have1[b1] * have1[b1] % MOD * n % MOD;
                } else {
                    int x = min(b1, b2), y = max(b1, b2);
                    howMany = (1LL * have2[x][y] * n + 1LL * (have1[b1] - have2[x][y]) * have1[b2]) % MOD * 1LL * have1[b1] % MOD;
                }
                answer = (1LL * product * howMany + answer) % MOD;
            }
        }
        cout << answer << "\n";
        for (int i = 0; i < MAXLOG; i++) {
            have1[i] = 0;
            for (int j = i + 1; j < MAXLOG; j++) {
                have2[i][j] = 0;
            }
        }
    }
    return 0;
}