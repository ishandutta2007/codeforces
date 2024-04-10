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

const int MAXN = 20;

char ans[1 + MAXN + 1][1 + MAXN + 1];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int di[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dj[8] = {1, 0, -1, 0, 1, -1, 1, -1};

bool out(int x, int y, int n, int m) {
    return (x < 0 || y < 0 || x >= n || y >= m);
}

bool ok(int x, int y, int n, int m) {
    for (int k = 0; k < 8; k++) {
        int x0 = x + di[k], y0 = y + dj[k];
        if (!out(x0, y0, n, m) && ans[x0][y0] == '1') {
            return false;
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
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = '0';
            }
        }
        for (int x = 0, y = 0, i = 0, d = 0; i < 2 * (m + n - 2); i++) {
            //cout << x << " " << y << " " << d << "\n";
            if (ok(x, y, n, m)) {
                ans[x][y] = '1';
            }
            x += dx[d];
            y += dy[d];
            if (out(x, y, n, m)) {
                x -= dx[d];
                y -= dy[d];
                d++;
                x += dx[d];
                y += dy[d];
            }
        }
        for (int i = 0; i < n; i++) {
            ans[i][m] = 0;
            cout << ans[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}