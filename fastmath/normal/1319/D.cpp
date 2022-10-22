#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define f first
#define s second
#define bp __builtin_popcount
#define all(a) a.begin(),a.end()
#define ll long long
#define mp make_pair

const int N = 2e5 + 7;
vector <int> g[N], rg[N];
int dist[N];
int n, m;

void bfs(int s) {
    for (int i = 0; i < N; ++i)
        dist[i] = N;
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : rg[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }   
        }   
    }   
}

int cnt[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v);
        rg[v].app(u);
    }   
    int k;
    cin >> k;
    vector <int> p(k);
    for (int i = 0; i < k; ++i)
        cin >> p[i];
    bfs(p.back());

    for (int u = 1; u <= n; ++u) {
        for (int v : g[u]) {
            cnt[u] += dist[u] == dist[v] + 1;
        }   
    }   

    int l = 0, r = 0;
    for (int i = 0; i + 1 < k; ++i) {
        int u = p[i], v = p[i + 1];
        bool good = dist[u] == dist[v] + 1;
        if (!good)
            ++l;
        if (cnt[u] - good > 0)
            ++r;
    }   
    cout << l << ' ' << r << endl;
}