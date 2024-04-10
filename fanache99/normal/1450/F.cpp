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

const int MAXN = 1000000;

int v[1 + MAXN], fr[1 + MAXN];

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
            fr[v[i]]++;
        }
        int most = 0;
        for (int i = 1; i <= n; i++) {
            most = max(most, fr[i]);
        }
        if (most - 1 > n - most) {
            cout << "-1\n";
        } else {
            for (int i = 1; i <= n; i++) {
                fr[i] = 0;
            }
            int total = 0;
            for (int i = 1, j; i <= n; i = j + 1) {
                j = i;
                while (j < n && v[j + 1] != v[j]) {
                    j++;
                }
                fr[v[i]]++;
                fr[v[j]]++;
                total += 2;
            }
            most = 0;
            int which;
            for (int i = 1; i <= n; i++) {
                if (fr[i] > most) {
                    most = fr[i];
                    which = i;
                }
            }
            int distinct = 0, one = 0, two = 0;
            for (int i = 1; i < n; i++) {
                if (v[i] != v[i + 1]) {
                    distinct++;
                    if (v[i] != which && v[i + 1] != which) {
                        two++;
                    } else {
                        one++;
                    }
                }
            }
            while (most - 2 > total - most) {
                if (two) {
                    total += 2;
                    two--;
                } else {
                    total += 2;
                    most++;
                    one--;
                }
                distinct--;
            }
            cout << n - 1 - distinct << "\n";
        }
        for (int i = 1; i <= n; i++) {
            fr[i] = 0;
        }
    }
    return 0;
}