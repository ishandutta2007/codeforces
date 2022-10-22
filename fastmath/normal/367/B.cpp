#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 * 1000 + 7;
const int N = 2e5 + 7;
const int C = N << 1;
mt19937 rnd(time(0));
int f[C];
int a[N], b[N];
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    for (int i = 0; i < C; ++i) {
        f[i] = rnd();
    }   
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    vector <int> c;
    for (int i = 0; i < n; ++i) c.push_back(a[i]);
    for (int i = 0; i < m; ++i) c.push_back(b[i]);
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    }   
    for (int i = 0; i < m; ++i) {
        b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
    }   
    int w = 0;
    for (int i = 0; i < m; ++i) {
        w = mod(w + f[b[i]]);
    }   
    vector <int> ans;
    for (int r = 0; r < p; ++r) {
        vector <int> t;
        for (int i = r; i < n; i += p) {
            t.push_back(a[i]);
        }   
        if (t.size() < m) continue;
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            cur = mod(cur + f[t[i]]);
        }   
        if (cur == w) ans.push_back(r);
        for (int i = 1; i + m - 1 < (int)t.size(); ++i) {
            cur = mod(cur + f[t[i + m - 1]] - f[t[i - 1]]);
            if (cur == w) {
                ans.push_back(r + i * p);
            }   
        }   
    }   
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int e : ans) cout << e + 1 << ' ';
    cout << '\n';
}