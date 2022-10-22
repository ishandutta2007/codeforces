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
#define lb lower_bound
#define ub upper_bound
#define Time (double)clock()/CLOCKS_PER_SEC
const int N = 2007;
vector <ii> a[N];
vector <int> y[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        a[u].app(mp(i + 1, 1 + 2 * i));
        a[v].app(mp(i + 1, 2 + 2 * i));
        y[u].app(1 + 2 * i);
        y[v].app(2 + 2 * i);
    }   
    int t = N * N;
    for (int i = 1; i <= n; ++i) {
        if (y[i].empty()) {
            cout << "1\n" << t << ' ' << t << '\n';
            ++t;
            continue;
        }   
        for (int e : y[i]) {
            a[i].app(mp(m + i, e));
        }   
        cout << a[i].size() << '\n';
        for (auto e : a[i])
            cout << e.f << ' ' << e.s << '\n';
    }   
}