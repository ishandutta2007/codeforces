#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
const int N = 1e6 + 7, INF = 1e18 + 7;
int n, m, a[N], ans[N];
int mx[N << 2];
void build(int v, int l, int r) {
    if (l == r) { mx[v] = a[l]; return; }
    int m = (l + r) >> 1;
    build(v * 2 + 1, l, m); build(v * 2 + 2, m + 1, r);
    mx[v] = max(mx[v * 2 + 1], mx[v * 2 + 2]);
}   
int get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl) return -INF;
    if (l <= tl && tr <= r) return mx[v];
    int tm = (tl + tr) >> 1;
    return max(get(v * 2 + 1, tl, tm, l, r), get(v * 2 + 2, tm + 1, tr, l, r));
}   
int add[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    while (n--) {
        int len; cin >> len;
        int max_a = 0;
        for (int i = 0; i < len; ++i) { cin >> a[i]; max_a = max(max_a, a[i]); }
        build(0, 0, len - 1);
        vector <int> c;
        for (int i = 1; i <= len; ++i) c.app(i);
        for (int i = m - len + 1; i <= m; ++i) c.app(i);
        sort(all(c)); c.resize(unique(all(c)) - c.begin());
        for (int i : c) {
            int t = get(0, 0, len - 1, len - 1 - (m - i), i - 1);
            if (i > len || m - i >= len) t = max(0ll, t);
            ans[i] += t;
        }
        if (len + 1 <= m - len) {
            add[len + 1] += max_a; add[m - len + 1] -= max_a;            
        }
    }
    for (int i = 1; i <= m; ++i) {
        add[i] += add[i - 1];
        ans[i] += add[i];        
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
    cout << '\n';
}