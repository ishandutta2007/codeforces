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

const int MAXN = 300000000;

bitset<2 * MAXN / 6> p;

int code(int x) {
    assert(x % 6 == 1 || x % 6 == 5);
    if (x % 6 == 1) {
        return 2 * (x / 6);
    } else {
        return 2 * (x / 6) + 1;
    }
}

void add(unsigned int &ans, unsigned int x, unsigned int n, unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned int v = a * x * x * x + b * x * x + c * x + d, y = x;
    while (y <= n) {
        ans += v * (n / y);
        if (y > n / x) {
            break;
        }
        y *= x;
    }
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    unsigned int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    unsigned int ans = 0;
    for (unsigned int i = 2; i <= n; i++) {
        if (i == 2 || i == 3 || ((i % 6 == 1 || i % 6 == 5) && p[code(i)] == 0)) {
            add(ans, i, n, a, b, c, d);
            if (1LL * i * i <= n) {
                for (unsigned int j = i * i; j <= n; j += i) {
                    if (j % 6 == 1 || j % 6 == 5) {
                        p[code(j)] = 1;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}