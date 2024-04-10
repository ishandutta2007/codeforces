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

const int N = 1e5+7;
vector <int> g[N];
const int LG = 20;
int tin[N], tout[N], ptr = 0, to[N][LG], h[N], dep[N], up[N];
ii down[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i)
        to[u][i] = to[to[u][i-1]][i-1];
    tin[u] = ptr++;
    down[u] = mp(0, u);
    dep[u] = 0;
    for (int v : g[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
            dep[u] = max(dep[u], dep[v] + 1);
            auto t = down[v];
            t.f++;
            down[u] = max(down[u], t);
        }
    tout[u] = ptr++;
}   
bool anc(int u, int v) { return tin[u] <= tin[v] && tout[v] <= tout[u]; }
int lca(int u, int v) {
    if (anc(u,v))   
        return u;
    for (int i = LG - 1; i >= 0; --i)
        if (!anc(to[u][i], v))
            u = to[u][i];
    return to[u][0];
}   
int goup(int u, int k) {
    for (int i = 0; i < LG; ++i)
        if ((k >> i) & 1)
            u = to[u][i];
    return u;
}   
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }
void calc_up(int u, int p) {
    vector <int> a = {-1};
    for (int v : g[u]) {
        if (v != p) {
            a.app(dep[v]);
        }   
    }   
    sort(all(a));
    reverse(all(a));
    for (int v : g[u]) {
        if (v != p) {
            up[v] = max(up[u], a[dep[v] == a[0]] + 1) + 1;
            calc_up(v, u);
        }   
    }   
}   
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        g[i].clear();
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    h[1] = up[1] = 0;
    calc(1, 1);
    calc_up(1, 1);
    int len = dist(a, b);
    int root = -1;
    for (int u = 1; u <= n; ++u) {
        vector <int> a = {up[u]};
        for (int v : g[u]) {
            if (v != to[u][0])
                a.app(dep[v] + 1);
        }   
        sort(all(a));
        reverse(all(a));
        if (a.size() >= 3 && a[2] >= len) {
            root = u;
        }   
    }       
    if (root == -1) {
        cout << "NO" << endl;
        return;
    }   
    else {      
        h[root] = 0;
        calc(root, root);
        set <ii> was;
        while (!anc(a, b) && !anc(b, a)) {
            if (was.count(mp(a,b)))
                break;
            was.insert(mp(a, b));
            int to = down[a].s;
            int d = h[to] - h[a];
            if (dist(lca(a, b), b) <= d) {
                cout << "YES" << endl;
                return;
            }   
            else {
                a = to;
                b = goup(b, d);
            }   
            swap(a, b);
        }   
        if (anc(a, b) || anc(b, a)) {
            cout << "YES" << endl;
        }   
        else {
            cout << "NO" << endl;
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
    int t;
    cin >> t;
    while (t--)
        solve();
}