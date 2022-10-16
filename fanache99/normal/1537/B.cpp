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

long long myAbs(long long x) {
    return x < 0 ? -x : x;
}

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return myAbs(x1 - x2) + myAbs(y1 - y2);
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
        long long n, m, x, y, ans = -1, i1, j1, i2, j2;
        cin >> n >> m >> x >> y;
        for (long long x1 = 1; x1 <= n; x1 += (n == 1 ? 2 : n - 1)) {
            for (long long x2 = 1; x2 <= n; x2 += (n == 1 ? 2 : n - 1)) {
                for (long long y1 = 1; y1 <= m; y1 += (m == 1 ? 2 : m - 1)) {
                    for (long long y2 = 1; y2 <= m; y2 += (m == 1 ? 2 : m - 1)) {
                        long long d = dist(x, y, x1, y1) + dist(x1, y1, x2, y2) + dist(x2, y2, x, y);
                        if (d > ans) {
                            ans = d;
                            i1 = x1;
                            i2 = x2;
                            j1 = y1;
                            j2 = y2;
                        }
                    }
                }
            }
        }
        cout << i1 << " " << j1 << " " << i2 << " " << j2 << "\n";
    }
    return 0;
}