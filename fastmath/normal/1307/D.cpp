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
const int N = 5e5 + 7;
int n, m, k, a[N], dist1[N], distn[N];
vector <int> g[N];
void bfs(int S, int dist[N]) {
    for (int i = 0; i < N; ++i)
        dist[i] = N;
    queue <int> q;
    q.push(S);
    dist[S] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : g[u])
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }   
    }       
}
ii suff[N];
int get(int i, ii ban) {
    if (ban.f >= i && suff[i].f == ban.s)
        return suff[i].s;
    else
        return suff[i].f;
}   
void add(ii &a, int x) {
    if (x > a.f) {
        a.s = a.f;
        a.f = x;
    }   
    else if (x > a.s)
        a.s = x;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    bfs(1, dist1); bfs(n, distn);
    vector <ii> v;
    for (int i = 0; i < k; ++i)
        v.app(mp(dist1[a[i]], distn[a[i]]));
    
    for (int i = 0; i < N; ++i)
        suff[i] = {-N, -N};
    for (auto e : v) 
        add(suff[e.f], e.s);
    for (int i = N - 1; i; --i) {
        add(suff[i - 1], suff[i].f);
        add(suff[i - 1], suff[i].s);
    }   

    int mx = 0;                        
    for (auto e : v) {
        int l = -1, r = N;
        while (l < r - 1) {
            int mid = (l + r) >> 1;
            int min_f = max(0ll, mid - e.s);
            if (get(min_f, e) >= mid - e.f)
                l = mid;
            else
                r = mid;
        }   
        mx = max(mx, l);
    }   
    cout << min(dist1[n], mx + 1) << '\n';                            
}