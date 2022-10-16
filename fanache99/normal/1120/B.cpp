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

const int MAXN = 100000;
const int LIMIT = 100000;
const int BASE = 10;

int n;
char a[1 + MAXN], b[1 + MAXN];
long long x[1 + MAXN], y[1 + MAXN];
vector<pair<int, int> > sol;
void inc(int i);
void dec(int i);

int myAbs(int x) {
    return x > 0 ? x : -x;
}

void addOp(int i, int a) {
    assert(i < n);
    x[i] += a;
    x[i + 1] += a;
    sol.push_back({i, a});
    if (sol.size() == LIMIT) {
        for (auto it : sol) {
            cout << it.first << " " << it.second << "\n";
        }
        exit(0);
    }
}

void inc(int i) {
    assert(i < n && x[i] < BASE - 1);
    if (x[i + 1] == BASE - 1) {
        dec(i + 1);
    }
    addOp(i, 1);
}

void dec(int i) {
    assert(i < n && x[i] > 0);
    if (x[i + 1] == 0) {
        inc(i + 1);
    }
    addOp(i, -1);
}

void solve(int i) {
    if (i == n) {
        assert(x[i] == y[i]);
        return;
    }
    while (x[i] != y[i]) {
        if (x[i] < y[i]) {
            inc(i);
        } else {
            dec(i);
        }
    }
    solve(i + 1);
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> n >> (a + 1) >> (b + 1);
    for (int i = 1; i <= n; i++) {
        x[i] = a[i] - '0';
        y[i] = b[i] - '0';
    }
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        long long d = y[i] - x[i];
        sum += myAbs(d);
        x[i] += d;
        x[i + 1] += d;
    }
    if (x[n] != y[n]) {
        cout << "-1\n";
    } else {
        cout << sum << "\n";
        for (int i = 1; i <= n; i++) {
            x[i] = a[i] - '0';
            y[i] = b[i] - '0';
        }
        solve(1);
        assert(sol.size() == sum);
        for (auto it : sol) {
            cout << it.first << " " << it.second << "\n";
        }
    }
    return 0;
}