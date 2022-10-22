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
const int N = 1e6 + 7;
vector <int> g[N];
set <ii> ms;
void add_edge(int u, int v) {
    if (v < u)
        swap(u, v);
    if (ms.find(mp(u, v)) != ms.end()) {
        cout << 2 << endl;
        exit(0);
    }   
    ms.insert(mp(u, v));
    g[u].app(v);
    g[v].app(u);
}   
int dist[N], son[N];
int ans = N;
void bfs(int S) {
    queue <int> q;
    q.push(S);
    dist[S] = 0;
    vector <int> who;
    while (q.size()) {
        int u = q.front(); q.pop(); who.app(u);
        for (int v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                if (u == S) 
                    son[v] = v;
                else
                    son[v] = son[u];
                q.push(v);
            }   
            else if (u != S && v != S && son[u] != son[v])
                ans = min(ans, dist[u] + dist[v] + 1);
        }   
    }   
    for (int u : who)
        dist[u] = N;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    vector <ii> ed;
    while (n--) {
        int x;
        cin >> x;
        vector <int> a;
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                int p = 0;
                while (x % i == 0) {
                    ++p;
                    x /= i;
                }   
                if (p & 1)
                    a.app(i);
            }   
        }   
        if (x > 1)
            a.app(x);
        if (a.empty()) {
            cout << 1 << endl;
            exit(0);
        }   
        else if (a.size() == 1) {
            ed.app(mp(1, a[0]));
        }   
        else if (a.size() == 2) {
            ed.app(mp(a[0], a[1]));
        }   
    }   
    for (auto e : ed)
        add_edge(e.f, e.s);
    for (int i = 0; i < N; ++i)
        dist[i] = N;
    for (int u = 1; u <= 1007; ++u)
        bfs(u);
    if (ans == N)
        cout << -1 << endl;
    else
        cout << ans << endl;
}