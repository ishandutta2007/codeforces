#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int v[MAXN];
map <int, int> cnt;
vector <int> dp[MAXN];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k;
    cin >> n >> l >> k;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        cnt[v[i]]++;
    }   

    for (int i = 1; i <= k; ++i) {
        dp[i].resize(cnt.size());
    }   

    vector <int> a, b;
    for (auto e : cnt) a.push_back(e.second);
    for (auto e : cnt) b.push_back(e.first);

    for (int i = 0; i < a.size(); ++i) {
        dp[1][i] = a[i];
    }   
    for (int i = 2; i <= k; ++i) {
        int curr = 0;
        for (int j = 0; j < a.size(); ++j) {
            curr = mod(curr + dp[i - 1][j]);
            dp[i][j] = mod(curr * a[j]);
        }   
    }   

    int bl = l / n;
    int pr = l % n;
    int ans = pr;    
    for (int t = 1; t <= min(bl, k); ++t) {
        int f = mod(bl - t + 1);
        int sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            sum = mod(sum + dp[t][i]);
        }   
        ans = mod(ans + f * sum);

        if (t == k) break;

        int add = 0;
        vector <int> p;
        for (int i = 0; i < pr; ++i) p.push_back(v[i]);
        sort(p.begin(), p.end());
        int u = 0;
        int curr = 0;
        for (int i = 0; i < pr; ++i) {
            while (u < a.size() && b[u] <= p[i]) {
                curr = mod(curr + dp[t][u]);
                ++u;
            }   
            add = mod(add + curr);
        }   

        ans = mod(ans + add);
    }   

    cout << ans << '\n';
    return 0;
}