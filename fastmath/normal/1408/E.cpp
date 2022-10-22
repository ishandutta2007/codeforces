#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 5e5+7;

int par[N];
int root(int u) {
    if (par[u] == u)
        return u;
    else
        return par[u] = root(par[u]);            
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    for (int i = 0; i < N; ++i)
        par[i] = i;

    int m, n;
    cin >> m >> n;
    vector <int> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    vector <int> b(n + 1);
    for (int i = 1; i <= n; ++i) 
        cin >> b[i];

    struct Edge {
        int u, v, c;
        bool operator < (Edge e) {
            return c > e.c;
        }   
    };  
    vector <Edge> ed;

    //vector <vector <int> > d(m);
    for (int i = 0; i < m; ++i) {
        int sz;
        cin >> sz;
        //d[i].resize(sz);
        for (int j = 0; j < sz; ++j) {
            int x;
            cin >> x;
            ed.app({i, m + x, a[i] + b[x]});
        }   
    }   
    sort(all(ed));

    int ans = 0;
    for (auto e : ed) {
        if (root(e.u) != root(e.v)) {
            par[root(e.u)] = root(e.v);
        }   
        else {
            ans += e.c;
        }   
    }   
    cout << ans << endl;
}