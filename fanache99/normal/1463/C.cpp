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

const int MAXN = 100000;
const long long INF = 1000000000000LL;

long long t[1 + MAXN + 1], x[1 + MAXN + 1];

long long absVal(long long x) {
    return x > 0 ? x : -x;
}

long long sign(long long x) {
    return x == 0 ? 0 : (x > 0 ? 1 : -1);
}

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
            cin >> t[i] >> x[i];
        }
        t[n + 1] = INF;
        long long xi = 0, ti = 0, xf = 0, tf = 0, answer = 0, sg;
        for (int i = 1; i <= n; i++) {
            if (t[i] >= tf) {
                xi = xf;
                ti = t[i];
                xf = x[i];
                tf = ti + abs(xf - xi);
                sg = sign(xf - xi);
                if (tf <= t[i + 1]) {
                    answer++;
                }
            } else {
                long long x1 = xi + sg * (t[i] - ti);
                long long x2 = xi + sg * (min(tf, t[i + 1]) - ti);
                if (x[i] >= min(x1, x2) && x[i] <= max(x1, x2)) {
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}