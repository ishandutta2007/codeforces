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

const int LOG = 30;

bool ask(long long y) {
    cout << y << "\n";
    cout.flush();
    int r;
    cin >> r;
    return r;
}

vector<long long> toBase(long long x, long long k) {
    vector<long long> ans;
    for (int i = 0; i < LOG; i++) {
        ans.push_back(x % k);
        x /= k;
    }
    return ans;
}

long long fromBase(vector<long long> v, long long k) {
    long long ans = 0;
    for (long long i = LOG - 1; i >= 0; i--) {
        ans = ans * k + v[i];
    }
    return ans;
}

vector<long long> add(vector<long long> a, vector<long long> b, long long k) {
    vector<long long> c(LOG);
    for (int i = 0; i < LOG; i++) {
        c[i] = (a[i] + b[i]) % k;
    }
    return c;
}

vector<long long> sub(vector<long long> a, vector<long long> b, long long k) {
    vector<long long> c(LOG);
    for (int i = 0; i < LOG; i++) {
        c[i] = (a[i] - b[i] + k) % k;
    }
    return c;
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
        long long n, k;
        cin >> n >> k;
        for (long long x = 0, accum = 0; x < n; x++) {
            long long y;
            if (x % 2 == 0) {
                y = fromBase(add(toBase(accum, k), toBase(x, k), k), k);
            } else {
                y = fromBase(sub(toBase(accum, k), toBase(x, k), k), k);
            }
            if (ask(y)) {
                break;
            }
            accum = fromBase(sub(toBase(y, k), toBase(accum, k), k), k);
        }
    }
    return 0;
}