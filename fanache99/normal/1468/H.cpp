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

const int MAXN = 200000;

int v[1 + MAXN];
bool in[1 + MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //ifstream cin("input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, k, m;
        cin >> n >> k >> m;
        for (int i = 1; i <= m; i++) {
            cin >> v[i];
            in[v[i]] = true;
        }
        if ((n - m) % (k - 1) != 0) {
            cout << "NO\n";
        } else {
            bool found = false;
            for (int i = 1, x = 0; i <= n; i++) {
                if (in[i]) {
                    if (x >= (k - 1) / 2 && n - m - x >= (k - 1) / 2) {
                        found = true;
                        break;
                    }
                } else {
                    x++;
                }
            }
            if (found) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
        for (int i = 1; i <= n; i++) {
            in[i] = false;
        }
    }
    return 0;
}