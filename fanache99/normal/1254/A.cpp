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

const int MAXN = 100;
const int SIGMA = 26;

char a[1 + MAXN][1 + MAXN], sol[1 + MAXN][1 + MAXN + 1];

char code(int x) {
    if (x < SIGMA) {
        return 'a' + x;
    } else if (x < 2 * SIGMA) {
        return 'A' + x - SIGMA;
    } else {
        return '0' + x - 2 * SIGMA;
    }
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
        int n, m, k, rice = 0;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
            for (int j = 1; j <= m; j++) {
                rice += (a[i][j] == 'R');
            }
        }
        for (int p = 0, x = 1, y = 1, dy = 1; p < k; p++) {
            int t = 0, r = rice / k + (p < rice % k);
            while (x <= n) {
                if (a[x][y] == 'R' && t == r) {
                    break;
                }
                sol[x][y] = code(p);
                t += (a[x][y] == 'R');
                y += dy;
                if (y < 1 || y > m) {
                    x++;
                    y -= dy;
                    dy *= -1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            sol[i][m + 1] = 0;
            cout << (sol[i] + 1) << "\n";
        }
    }
    return 0;
}