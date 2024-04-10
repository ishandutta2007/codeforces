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
#include <bitset>
#include <unordered_map>
#include <complex>
#include <unordered_set>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
    timeEnd();
    double time_taken = double(timeFinish - timeStart) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
    cout << " sec " << endl;
}

class InputReader {
public:
    InputReader() {
        input_file = stdin;
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    InputReader(const char *file_name) {
        input_file = fopen(file_name, "r");
        cursor = 0;
        fread(buffer, SIZE, 1, input_file);
    }

    inline InputReader &operator>>(int &n) {
        while ((buffer[cursor] < '0' || buffer[cursor] > '9') && buffer[cursor] != '-') {
            advance();
        }
        int sign = 1;
        if (buffer[cursor] == '-') {
            sign = -1;
            advance();
        }
        n = 0;
        while ('0' <= buffer[cursor] && buffer[cursor] <= '9') {
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
        ++cursor;
        if (cursor == SIZE) {
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
    }
};

const int MAXN = 100000;
const int SIGMA = 26;

char s[1 + MAXN], t[1 + MAXN];
int go[1 + MAXN + 1][SIGMA][2];

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cin >> (s + 1) >> (t + 1);
        int n = strlen(s + 1), k = strlen(t + 1);
        if (k > n) {
            cout << "NO\n";
        } else {
            for (int j = 0; j < SIGMA; j++) {
                go[0][j][0] = go[0][j][1] = 0;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < SIGMA; j++) {
                    go[i][j][0] = go[i - 1][j][0];
                    go[i][j][1] = go[i - 1][j][1];
                }
                go[i][s[i] - 'a'][i % 2] = i;
            }
            for (int j = 0; j < SIGMA; j++) {
                go[n + 1][j][0] = go[n][j][0];
                go[n + 1][j][1] = go[n][j][1];
            }
            int p = n + 1;
            for (int i = k; i >= 1 && p > 0; i--) {
                p = go[p - 1][t[i] - 'a'][(p - 1) % 2];
            }
            cout << (p != 0 ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}