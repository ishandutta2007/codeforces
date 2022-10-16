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

const int MAXLOG = 30;
const int MAXN = 10000;

int v[1 + MAXN], w[1 + MAXN];

int askAnd(int i, int j) {
    cout << "and " << i << " " << j << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int askOr(int i, int j) {
    cout << "or " << i << " " << j << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void answer(int x) {
    cout << "finish " << x << "\n";
    cout.flush();
    exit(0);
}

//int askAnd(int i, int j) {
//    return w[i] & w[j];
//}
//
//int askOr(int i, int j) {
//    return w[i] | w[j];
//}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, k;
//    int n = 1000, k = 5;
//    for (int i = 1; i <= n; i++) {
//        w[i] = rand() % 1000000000;
//    }
    cin >> n >> k;
    int or12 = askOr(1, 2), and12 = askAnd(1, 2);
    int or23 = askOr(2, 3), and23 = askAnd(2, 3);
    int or13 = askOr(1, 3), and13 = askAnd(1, 3);
    for (int i = 0; i < MAXLOG; i++) {
        int o12 = ((or12 >> i) & 1), a12 = ((and12 >> i) & 1);
        int o13 = ((or13 >> i) & 1), a13 = ((and13 >> i) & 1);
        int o23 = ((or23 >> i) & 1), a23 = ((and23 >> i) & 1);
        int b1 = -1, b2 = -1, b3 = -1;
        if (o12 == 0 && o13 == 0) {
            b1 = b2 = b3 = 0;
        } else if (a12 == 1 && a13 == 1) {
            b1 = b2 = b3 = 1;
        } else if (o12 == 0) {
            b1 = b2 = 0;
            b3 = 1;
        } else if (o13 == 0) {
            b1 = b3 = 0;
            b2 = 1;
        } else if (o23 == 0) {
            b2 = b3 = 0;
            b1 = 1;
        } else if (a12 == 1) {
            b1 = b2 = 1;
            b3 = 0;
        } else if (a23 == 1) {
            b2 = b3 = 1;
            b1 = 0;
        } else {
            assert(a13 == 1);
            b1 = b3 = 1;
            b2 = 0;
        }
        assert(b1 != -1 && b2 != -1 && b3 != -1);
        v[1] += b1 * (1 << i);
        v[2] += b2 * (1 << i);
        v[3] += b3 * (1 << i);
    }
    for (int i = 4; i <= n; i++) {
        int ai = askAnd(1, i), oi = askOr(1, i);
        for (int j = 0; j < MAXLOG; j++) {
            int a = ((ai >> j) & 1), o = ((oi >> j) & 1), x = ((v[1] >> j) & 1);
            int b = -1;
            if (o == 0) {
                b = 0;
            } else if (a == 1) {
                b = 1;
            } else if (x == 1) {
                b = 0;
            } else {
                assert(x == 0);
                b = 1;
            }
            assert(b != -1);
            v[i] += b * (1 << j);
        }
    }
    sort(v + 1, v + n + 1);
    answer(v[k]);
//    for (int i = 1; i <= n; i++) {
//        if (v[i] != w[i]) {
//            for (int j = 1; j <= n; j++) {
//                cout << w[j] << " ";
//            }
//            cout << "\n";
//            for (int j = 1; j <= n; j++) {
//                cout << v[j] << " ";
//            }
//            cout << "\n";
//            return 0;
//        }
//    }
    return 0;
}