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

const int MAXN = 14;
const int MOD = 1000000007;

int raiseToPower(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

int v[MAXN];

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

int inv(int x) {
    return raiseToPower(x, MOD - 2);
}

int win(int i, int j) {
    return mul(v[i], inv(v[i] + v[j]));
}

int lose(int i, int j) {
    return mul(v[j], inv(v[i] + v[j]));
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

int beat[MAXN][1 << MAXN];

void precompute(int n) {
    for (int x = 0; x < n; x++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            beat[x][mask] = 1;
            for (int i = 0; i < n; i++) {
                if (((mask >> i) & 1) && i != x) {
                    beat[x][mask] = mul(beat[x][mask], win(x, i));
                }
            }
        }
    }
}

bool seen[1 << MAXN];
int pr[1 << MAXN], dp[1 << MAXN];

int sep(int s1, int s2, int n) {
    int p = 1;
    for (int i = 0; i < n; i++) {
        if ((s1 >> i) & 1) {
            p = mul(p, beat[i][s2]);
        }
    }
    return p;
}

void compute(int mask, int n) {
    if (seen[mask]) {
        return;
    }
    seen[mask] = true;
    if (__builtin_popcount(mask) == 1) {
        pr[mask] = dp[mask] = 1;
        return;
    }
    pr[mask] = 1;
    for (int s1 = (mask - 1) & mask; s1 != 0; s1 = (s1 - 1) & mask) {
        int s2 = mask ^ s1;
        assert((s1 & mask) == s1);
        assert((s2 & mask) == s2);
        assert((s1 & s2) == 0);
        assert((s1 | s2) == mask);
        compute(s1, n);
        compute(s2, n);
        int p = mul(sep(s1, s2, n), pr[s1]);
        sub(pr[mask], p);
        add(dp[mask], mul(p, __builtin_popcount(s1)));
    }
    add(dp[mask], mul(pr[mask], __builtin_popcount(mask)));
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    precompute(n);
    compute((1 << n) - 1, n);
    cout << dp[(1 << n) - 1] << "\n";
    return 0;
}