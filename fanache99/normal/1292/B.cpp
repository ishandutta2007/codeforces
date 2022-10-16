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

const long long INF = 1e18;

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
    long long x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    long long xs, ys, t;
    cin >> xs >> ys >> t;
    vector<long long> x, y;
    x.push_back(x0);
    y.push_back(y0);
    while (x.back() <= (INF - bx) / ax && y.back() <= (INF - by) / ay) {
        x.push_back(x.back() * ax + bx);
        y.push_back(y.back() * ay + by);
    }
    int n = x.size(), answer = 0;
    for (int i = 0; i < n; i++) {
        if (dist(xs, ys, x[i], y[i]) <= t) {
            {
                int current = 1;
                long long l = t - dist(xs, ys, x[i], y[i]);
                for (int j = i + 1; j < n; j++) {
                    if (dist(x[j - 1], y[j - 1], x[j], y[j]) <= l) {
                        l -= dist(x[j - 1], y[j - 1], x[j], y[j]);
                        current++;
                    } else {
                        break;
                    }
                }
                answer = max(answer, current);
            }
            {
                int current = 1;
                long long l = t - dist(xs, ys, x[i], y[i]);
                for (int j = i - 1; j >= 0; j--) {
                    if (dist(x[j + 1], y[j + 1], x[j], y[j]) <= l) {
                        l -= dist(x[j + 1], y[j + 1], x[j], y[j]);
                        current++;
                    } else {
                        break;
                    }
                }
                answer = max(answer, current);
            }
        }
    }
    cout << answer << "\n";
    return 0;
}