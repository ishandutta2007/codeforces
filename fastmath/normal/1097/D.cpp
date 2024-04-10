#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int fp(int n, int p) {
    if (p == 0) return 1;
    int t = fp(n, p >> 1);
    if (p & 1) return mod(mod(t * t) * n);
    else return mod(t * t);
}   
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
pair <int, int> sum(pair <int, int> a, pair <int, int> b) {
    return {mod(a.first * b.second + b.first * a.second), mod(a.second * b.second)};
}   
pair <int, int> mul(pair <int, int> a, pair <int, int> b) {
    return {mod(a.first * b.first), mod(a.second * b.second)};
}   
const int N = 50;
const int K = 10001;
pair <int, int> dp[K][N];    
vector <pair <int, int> > get(int n, int k) {
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) dp[i][j] = {0, 1};
    }   
    dp[0][n] = {1, 1};
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int t = j; t <= n; ++t) {
                dp[i][j] = sum(dp[i][j], mul(dp[i - 1][t], {1, t + 1}));
            }   
        }   
    }
    vector <pair <int, int> > ans;
    for (int i = 0; i <= n; ++i) ans.push_back(dp[k][i]);
    return ans;
}   
vector <int> v, cnt;
vector <vector <pair <int, int> > > p;
pair <int, int> ans = {0, 1};
void gen(int i, pair <int, int> cp, int f) {
    f = mod(f);
    if (i == v.size()) {
        //cout << cp.first << ' ' << cp.second << '\n';
        //cout << f << '\n';
        cp.first = mod(cp.first * f);
        ans = sum(ans, cp);
        return;
    }   
    int cf = 1;
    for (int pw = 0; pw <= cnt[i]; ++pw) {
        gen(i + 1, mul(cp, p[i][pw]), f * cf);
        cf *= v[i];
    }   
}   
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    int n, k;
    cin >> n >> k;
    for (int d = 2; d * d <= n; ++d) {
        while (n % d == 0) {
            v.push_back(d);
            n /= d;
        }   
    }   
    if (n != 1) v.push_back(n);
    map <int, int> d;
    for (auto e : v) d[e]++;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto e : v) {
        cnt.push_back(d[e]);
        p.push_back(get(d[e], k));
    }
    gen(0, {1, 1}, 1);
    cout << mdiv(ans.first, ans.second) << '\n';
}