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
#include <chrono>
#include <random>

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

    template<typename T>
    inline InputReader &operator>>(T &n) {
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

const int MAXN = 1000000;
const int MOD = 1000000007;

int div2[1 + MAXN], fact[1 + MAXN], inv[1 + MAXN];

int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

int add(int x, int y) {
    return (x + y) % MOD;
}

int sub(int x, int y) {
    return (x - y + MOD) % MOD;
}

int power(int base, int power) {
    int answer = 1;
    while (power) {
        if (power % 2)
            answer = (1LL * answer * base) % MOD;
        base = (1LL * base * base) % MOD;
        power /= 2;
    }
    return answer;
}

void precompute(int n) {
    div2[0] = 1;
    div2[1] = power(2, MOD - 2);
    for (int i = 2; i <= n; i++) {
        div2[i] = mul(div2[i - 1], div2[1]);
    }

    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    inv[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inv[i] = (1LL * (i + 1) * inv[i + 1]) % MOD;
}

int comb(int n, int k) {
    int answer = (1LL * inv[n - k] * inv[k]) % MOD;
    answer = (1LL * answer * fact[n]) % MOD;
    return answer;
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute(MAXN);
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0, sum = 0;
        for (int i = m; i >= 1; i--) {
            int curr = sub(comb(n - i, m - i), sum);
            ans = add(ans, mul(curr, mul(i, div2[n - i])));
            sum = add(sum, curr);
        }
        ans = mul(ans, k);
        cout << ans << "\n";
    }
    return 0;
}