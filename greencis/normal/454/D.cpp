#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    constexpr int MAX_C = 58;
    vector<int> lp(MAX_C + 1);
    iota(all(lp), 0);
    vector<int> primeIndex(MAX_C + 1, -1);
    int primes = 0;
    for (int i = 2; i <= MAX_C; ++i) {
        if (lp[i] == i) {
            primeIndex[i] = primes++;
            for (int j = 2 * i; j <= MAX_C; j += i)
                if (lp[j] == j)
                    lp[j] = i;
        }
    }
    vector<int> numMask(MAX_C + 1);
    for (int i = 1; i <= MAX_C; ++i) {
        int tmp = i;
        while (tmp > 1) {
            int divr = lp[tmp];
            int idx = primeIndex[divr];
            numMask[i] |= 1 << idx;
            while (tmp % divr == 0)
                tmp /= divr;
        }
    }
    vector<vector<int>> candidates(1 << primes);
    for (int mask = 0; mask < (1 << primes); ++mask) {
        for (int i = 1; i <= MAX_C; ++i) {
            if ((mask & numMask[i]) == 0)
                candidates[mask].push_back(i);
        }
    }

    constexpr int INF = 1e9;
    vector<vector<pair<int, pii>>> dp(n + 1, vector<pair<int, pii>>(1 << primes, {INF, {}}));
    dp[0][0] = {0, {}};
    for (int i = 0; i < n; ++i) {
        for (int mask = 0; mask < (1 << primes); ++mask) {
            if (dp[i][mask].first == INF) continue;
            for (int nxt : candidates[mask]) {
                int nextMask = mask | numMask[nxt];
                int nextSum = dp[i][mask].first + abs(a[i] - nxt);
                dp[i + 1][nextMask] = min(dp[i + 1][nextMask], {nextSum, {mask, nxt}});
            }
        }
    }

    vector<int> ans;
    int curMask = int(min_element(all(dp[n])) - dp[n].begin());
    for (int i = n; i >= 1; --i) {
        ans.push_back(dp[i][curMask].second.second);
        curMask = dp[i][curMask].second.first;
    }
    reverse(all(ans));
    for (int x : ans)
        cout << x << ' ';
}