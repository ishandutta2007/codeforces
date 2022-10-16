#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
const int MOD = 998244353;

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

int factorial[1 + 2 * MAXN], inverse[1 + 2 * MAXN], dp[1 + 2 * MAXN], fact2[1 + 2 * MAXN];

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
    factorial[0] = inverse[0] = fact2[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
        fact2[i] = mul(fact2[i - 1], 2 * i - 1);
    }
    inverse[n] = power(factorial[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--)
        inverse[i] = (1LL * (i + 1) * inverse[i + 1]) % MOD;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        add(dp[i], mul(dp[i - 2], i - 1));
    }
}

int comb(int n, int k) {
    int answer = (1LL * inverse[n - k] * inverse[k]) % MOD;
    answer = (1LL * answer * factorial[n]) % MOD;
    return answer;
}

int compute(int n) {
    int ans = 0;
    for (int i = 0; 4 * i <= n; i++) {
        int rest = n - 4 * i, groups = 2 * i;
        int total = comb(groups + rest, groups);
        add(ans, mul(dp[rest], mul(total, mul(fact2[i], power(2, i)))));
    }
    return ans;
}

int p[1 + MAXN], pi[1 + MAXN];

int myAbs(int x) {
    return x < 0 ? -x : x;
}

int brute(int n) {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int ans = 0;
    do {
        for (int i = 1; i <= n; i++) {
            pi[p[i]] = i;
        }
        bool bad = false;
        for (int i = 1; i <= n; i++) {
            if (myAbs(p[i] - pi[i]) > 1) {
                bad = true;
            }
        }
        ans += !bad;
    } while (next_permutation(p + 1, p + n + 1));
    return ans;
}

int main() {
    // ifstream cin("/home/stefanb/work/platform/src/app/shm_clean/input.txt");
    precompute(2 * MAXN);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        cout << compute(n) << "\n";
    }
    return 0;
}