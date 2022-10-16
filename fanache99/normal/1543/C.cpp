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

const float EPS = 1e-6;
const int LOG = 20;

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
        float x, y, z, v;
        cin >> x >> y >> z >> v;
        float ans = 0;
        for (int l = 0; l <= LOG; l++) {
            for (int mask = 0; mask < (1 << l); mask++) {
                float a = x, b = y, c = z, p = 1;
                for (int bit = 0; bit < l; bit++) {
                    if ((mask >> bit) & 1) {
                        if (a < EPS) {
                            p = 0;
                            break;
                        }
                        p *= a;
                        float r = min(a, v);
                        a -= r;
                        if (b >= EPS) {
                            b += r * 0.5;
                            c += r * 0.5;
                        } else {
                            c += r;
                        }
                    } else {
                        if (b < EPS) {
                            p = 0;
                            break;
                        }
                        p *= b;
                        float r = min(b, v);
                        b -= r;
                        if (a >= EPS) {
                            a += r * 0.5;
                            c += r * 0.5;
                        } else {
                            c += r;
                        }
                    }
                }
                p *= c;
                ans += (l + 1) * p;
            }
        }
        cout << fixed << setprecision(12) << ans << "\n";
    }
    return 0;
}