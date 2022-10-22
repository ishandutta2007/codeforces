#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define x first
#define y second
const int N = 1e6 + 7;
vector <ii> a[N], b[N], mem[N];
vector <int> res[N];
int f[N], pr[N], ans[N];
void add(int i, int x) { for (; i < N; i |= i + 1) f[i] += x; }
int get(int i) { int ans = 0; for (; i >= 0; i &= i + 1, --i) ans += f[i]; return ans; }
int get(int l, int r) { return get(r) - get(l - 1); }
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n; cin >> n;
    for (int i = 0; i < n; ++i) { int k; cin >> k; a[i].resize(k); b[i].resize(k); for (int j = 0; j < k; ++j) cin >> a[i][j].x >> a[i][j].y; }   
    vector <ii> c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < a[i].size(); ++j) b[i][j] = {a[i][j + 1].x - a[i][j].x, a[i][j + 1].y - a[i][j].y};
        int sz = a[i].size(); b[i][sz - 1] = {a[i][0].x - a[i][sz - 1].x, a[i][0].y - a[i][sz - 1].y};
        for (auto &e : b[i]) { int d = __gcd(abs(e.x), abs(e.y)); e.x /= d; e.y /= d; c.app(e); }   
    }   
    sort(c.begin(), c.end()); c.resize(unique(c.begin(), c.end()) - c.begin());
    for (int i = 0; i < n; ++i) { for (auto e : b[i]) res[i].app(lower_bound(c.begin(), c.end(), e) - c.begin()); }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) { int l, r; cin >> l >> r; --l; --r; mem[r].app({i, l}); }
    for (int i = 0; i < N; ++i) pr[i] = -1;
    for (int i = 0; i < n; ++i) {
        for (int e : res[i]) if (pr[e] != -1) add(pr[e], -1);
        for (int e : res[i]) pr[e] = i;
        add(i, res[i].size());
        for (auto qq : mem[i]) ans[qq.x] = get(qq.y, i);
    }   
    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
}   
//a))