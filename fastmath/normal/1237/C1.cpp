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
const int N = 50001, INF = 1e9 + 7;
struct P { int x, y, z; } a[N];
ii get(set <ii> ms, int z) {
    auto t = ms.lower_bound(mp(z, -INF));
    if (t == ms.end()) --t;
    return *t;
}   
set <ii> ms[N], d[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <int> c;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].z;
        c.app(a[i].x);
    }   
    sort(all(c)); c.resize(unique(all(c)) - c.begin());
    vector <ii> cp;
    for (int i = 1; i <= n; ++i) {
        a[i].x = lower_bound(all(c), a[i].x) - c.begin();
        cp.app(mp(a[i].x, a[i].y));
    }
    sort(all(cp));
    for (int i = 1; i <= n; ++i) {
        ms[a[i].x].insert(mp(a[i].y, i));
        d[lower_bound(all(cp), mp(a[i].x, a[i].y)) - cp.begin()].insert(mp(a[i].z, i));
    }   
    int x = 0;
    for (int t = 0; t < n / 2; ++t) {
        while (ms[x].empty()) ++x;
        int i = ms[x].begin()->s;
        ms[x].erase(ms[x].begin());
        d[lower_bound(all(cp), mp(a[i].x, a[i].y)) - cp.begin()].erase(mp(a[i].z, i));

        while (ms[x].empty()) ++x;
        int y = get(ms[x], a[i].y).f;
        auto p = get(d[lower_bound(all(cp), mp(x, y)) - cp.begin()], a[i].z);
        int z = p.first, j = p.second;

        ms[x].erase(mp(y, j));
        d[lower_bound(all(cp), mp(x, y)) - cp.begin()].erase(mp(z, j));

        cout << i << ' ' << j << '\n';
    }   
}