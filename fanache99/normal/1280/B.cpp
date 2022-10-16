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

const int MAXN = 60;

char a[1 + MAXN][1 + MAXN];

bool all(int r1, int c1, int r2, int c2, bool val) {
    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {
            if (a[r][c] != val) {
                return false;
            }
        }
    }
    return true;
}

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
        int n, m;
        cin >> n >> m;
        bool foundTrue = false, foundFalse = false;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++) {
                a[i][j] = (a[i][j] == 'A');
                foundTrue |= a[i][j];
                foundFalse |= (!a[i][j]);
            }
        }
        if (!foundTrue) {
            cout << "MORTAL\n";
        } else if (!foundFalse){
            cout << "0\n";
        } else if (all(1, 1, 1, m, true) || all(1, 1, n, 1, true) || all(1, m, n, m, true) || all(n, 1, n, m, true)) {
            cout << "1\n";
        } else {
            bool found = a[1][1] || a[1][m] || a[n][1] || a[n][m];
            for (int r = 1; r <= n; r++) {
                found |= all(r, 1, r, m, true);
            }
            for (int c = 1; c <= m; c++) {
                found |= all(1, c, n, c, true);
            }
            if (found) {
                cout << "2\n";
            } else if (!all(1, 1, 1, m, false) || !all(1, 1, n, 1, false) || !all(1, m, n, m, false) || !all(n, 1, n, m, false)) {
                cout << "3\n";
            } else {
                cout << "4\n";
            }
        }

    }
    return 0;
}