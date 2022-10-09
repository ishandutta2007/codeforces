#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 4e6 + 228;

int D[N];

vector<pair<int, int>> who(int n) {
    vector<pair<int, int>> ans;
    while (n > 1) {
        ans.emplace_back(D[n], 0);
        while (n % ans.back().first == 0) {
            ++ans.back().second;
            n /= ans.back().first;
        }
    }
    return ans;
}

void gen(int who, vector<pair<int, int>> &c, int ind, vector<int> &d) {
    if (ind == (int) c.size()) {
        d.push_back(who);
        return;
    }

    int z = 1;
    for (int i = 0; i <= c[ind].second; ++i) {
        gen(who * z, c, ind + 1, d);
        if (i != c[ind].second)
            z *= c[ind].first;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    long long mod1 = 1, mod2 = 0;
    vector<long long> dp(n + 1);
    dp[1] = 1;
    
    iota(D, D + N, 0);
    for (int i = 2; i < N; ++i) {
        if (D[i] == i) {
            for (int j = i; j < N; j += i)
                D[j] = min(D[j], i);
        }
    }

    for (int i = 2; i <= n; ++i) {
        vector<int> d;
        auto z = who(i);
        gen(1, z, 0, d);
        sort(all(d));
        for (auto j : d) {
            if (j == 1)
                continue;
            mod2 -= dp[i / j - 1];
            mod2 += dp[i / j];
            mod2 = (mod2 + m) % m;
        }
        dp[i] = (mod1 + mod2) % m;
        mod1 = (mod1 + dp[i]) % m;
    }
    cout << dp.back() << '\n';
}