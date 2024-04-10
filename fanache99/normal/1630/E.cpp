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
const int MOD = 998244353;

int v[1 + MAXN], f[1 + MAXN], dp[1 + MAXN], sum[1 + MAXN];
int factorial[1 + MAXN], inverse[1 + MAXN];

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

void precompute(int n) {
    factorial[0] = inverse[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    inverse[n] = raiseToPower(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
}

int combinations(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int myGcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

int add(int x, int y) {
    return (x + y) % MOD;
}

int sub(int x, int y) {
    return (x - y + MOD) % MOD;
}

int main() {
    timeBegin();
    // ifstream cin("input.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    precompute(MAXN);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        bool allEqual = true;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            if (v[i] != v[1]) {
                allEqual = false;
            }
        }
        if (allEqual) {
            cout << "1\n";
        } else {
            vector<int> act;
            for (int i = 1; i <= n; i++) {
                f[v[i]]++;
            }
            int rep = 0;
            for (int i = 1; i <= n; i++) {
                rep = myGcd(rep, f[i]);
                if (f[i] > 0) {
                    act.push_back(i);
                }
            }

            for (int i = 1; i <= rep; i++) {
                int n0 = n / rep * i;
                int curr = factorial[n0];
                int temp = 0;
                for (auto x : act) {
                    int f0 = f[x] / rep * i;
                    curr = mul(curr, inverse[f0]);
                    if (f0 > 1) {
                        temp = add(temp, mul(f0, f0 - 1));
                    }
                }

                dp[i] = add(dp[i], curr);
                sum[i] = add(sum[i], mul(curr, mul(inverse[n0], mul(factorial[n0 - 2], mul(temp, n0)))));

                for (int j = 2 * i; j <= rep; j += i) {
                    dp[j] = sub(dp[j], dp[i]);
                    sum[j] = sub(sum[j], mul(sum[i], j / i));
                }
            }

            int tot = 0, ans = 0;
            for (int i = 1; i <= rep; i++) {
                if (rep % i == 0) {
                    int n0 = n / rep * i, div = raiseToPower(n0, MOD - 2);
                    int totSum = mul(sum[i], rep / i);
                    totSum = mul(totSum, div);
                    int totDp = mul(dp[i], div);
                    tot = add(tot, totDp);
                    ans = add(ans, sub(mul(n, totDp), totSum));
                }
            }
            ans = mul(ans, raiseToPower(tot, MOD - 2));
            cout << ans << "\n";
            for (int i = 1; i <= n; i++) {
                f[i] = dp[i] = sum[i] = 0;
            }
        }
    }
    return 0;
}