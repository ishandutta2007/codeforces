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

clock_t timeStart, timeFinish;

void timeBegin() {
    timeStart = clock();
}

void timeEnd() {
    timeFinish = clock();
}

void timeDuration() {
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

int v[1 + MAXN + 2];

bool check(int n, int l, long double middle) {
    long double t1 = middle, v1 = 1, d1 = 0;
    for (int i = 2; i <= n; i++) {
        if ((v[i] - v[i - 1]) / v1 <= t1) {
            t1 -= (v[i] - v[i - 1]) / v1;
            d1 += v[i] - v[i - 1];
            v1++;
        } else {
            d1 += t1 * v1;
            t1 = 0;
            break;
        }
    }
    long double t2 = middle, v2 = 1, d2 = 0;
    for (int i = n - 1; i >= 1; i--) {
        if ((v[i + 1] - v[i]) / v2 <= t2) {
            t2 -= (v[i + 1] - v[i]) / v2;
            d2 += v[i + 1] - v[i];
            v2++;
        } else {
            d2 += t2 * v2;
            t2 = 0;
            break;
        }
    }
    return d1 + d2 >= l;
}

int main() {
    timeBegin();
    //ifstream cin("input.txt");
    //ofstream cout("papagali.out");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n, l;
        cin >> n >> l;
        v[1] = 0;
        for (int i = 2; i <= n + 1; i++) {
            cin >> v[i];
        }
        v[n + 2] = l;
        n += 2;
        long double left = 0, right = l;
        for (int step = 0; step < 100; step++) {
            long double middle = (left + right) * 0.5;
            if (check(n, l, middle)) {
                right = middle;
            } else {
                left = middle;
            }
        }
        cout << fixed << setprecision(12) << left << "\n";
    }
    return 0;
}