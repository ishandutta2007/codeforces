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

const int MOD = 1000000007;
const int MAXN = 2000000;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int factorial[1 + MAXN], inverse[1 + MAXN];
int mPow[1 + MAXN], nPow[1 + MAXN];

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

void precompute(int n, int m) {
    factorial[0] = inverse[0] = mPow[0] = nPow[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
        mPow[i] = 1LL * m * mPow[i - 1] % MOD;
        nPow[i] = 1LL * n * nPow[i - 1] % MOD;
    }
    inverse[MAXN] = raiseToPower(factorial[MAXN], MOD - 2);
    for (int i = MAXN- 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int comb(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int main() {
    timeBegin();
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    precompute(n, m);
    int ans = 0;
    for (int mid = 1; mid <= m && mid <= n - 1; mid++) {
        int curr = 1LL * comb(n - 2, mid - 1) * factorial[mid - 1] % MOD;
        curr = 1LL * curr * comb(m - 1, mid - 1) % MOD;
        curr = 1LL * curr * mPow[n - 1 - mid] % MOD;
        curr = 1LL * curr * (mid + 1) % MOD * (mid == (n - 1) ? raiseToPower(n, MOD - 2) : nPow[n - mid - 2]) % MOD;
        add(ans, curr);
    }
    cout << ans << "\n";
    return 0;
}