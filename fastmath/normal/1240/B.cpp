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
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 3e5 + 7;
int n, a[N], lp[N], rp[N];
void solve() {
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) { lp[i] = N; rp[i] = -N; }
    for (int i = 0; i < n; ++i) { lp[a[i]] = min(lp[a[i]], i); rp[a[i]] = max(rp[a[i]], i); }
    vector <int> c;
    for (int i = 0; i < n; ++i) c.app(a[i]);
    sort(all(c)); c.resize(unique(all(c)) - c.begin());
    int ptr = -1, mx = 0;
    for (int i = 0; i < c.size(); ++i) {
        ptr = max(ptr, i);
        while (ptr + 1 < c.size() && rp[c[ptr]] < lp[c[ptr + 1]]) ++ptr;
        mx = max(mx, ptr - i + 1);
    }   
    cout << c.size() - mx << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t; cin >> t; while (t--) solve();
}