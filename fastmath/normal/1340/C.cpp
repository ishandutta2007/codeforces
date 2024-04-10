#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("ssse3")

#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
const int C = 1e6 + 7, INF = 1e9 + 7;
int num[C];
int n, m;
vector <int> d, dist;
int G, R;

queue <int> q;
bitset <2007> l, r, p;
int s = 1000;
void relax(int u) {
    l &= 0;
    r &= 0;
    p &= 0;

    l[s] = r[s] = 1;
    for (int i = 0; i < 2007; ++i) {
        int x = d[u] - s + i;
        if (x >= 0 && x <= n && num[x] != -1) {
            p[i] = 1;
        }   
    }   

    for (int i = 0; i < G; ++i) {
        l >>= 1;
        r <<= 1;
        l |= r & p;
        r |= l & p;
    }   

    l |= r;
    for (int i = 0; i < 2007; ++i) {
        if (p[i] && l[i]) {
            int x = d[u] - s + i;
            int v = num[x];
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }   
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> m;
    d.resize(m);
    dist.resize(m, INF);
    for (int i = 0; i < m; ++i) 
        cin >> d[i];
    sort(all(d));
    cin >> G >> R;

    for (int i = 0; i < C; ++i)
        num[i] = -1;
    for (int i = 0; i < m; ++i)
        num[d[i]] = i;

    int ans = INF;
    q.push(0);
    dist[0] = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (d[u] + G >= n) {
            ans = min(ans, (n - d[u]) + dist[u] * (G + R));
        }   
        relax(u);
    }   
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}