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
int tin[N], tout[N], ptr = 0, to[N][LG], h[N];
void calc(int u, int p) {
    to[u][0] = p;
    for (int i = 1; i < LG; ++i)
        to[u][i] = to[to[u][i-1]][i-1];
    tin[u] = ptr++;            
    for (int v : g[u])  
        if (v != p) {
            h[v] = h[u]+1;
            calc(v, u);
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
int dist(int u, int v) { return h[u] + h[v] - 2 * h[lca(u,v)]; }

ii dfs(int u, int p) {
    ii ans = mp(0, u);
    for (int v : g[u]) {
        if (v != p) {
            auto t = dfs(v, u);
            t.f++;
            ans = max(ans, t);
        }   
    }   
    return ans;
}

void solve() {
    int n, a, b, A, B;
    cin >> n >> a >> b >> A >> B;

    for (int i = 1; i <= n; ++i)
        g[i].clear();

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].app(v); g[v].app(u);
    }   
    calc(1, 1);
                           
    if (dist(a, b) <= A || B <= 2 * A) {
        cout << "Alice" << endl;
        return;
    }   

    auto t1 = dfs(1, 1);
    auto t2 = dfs(t1.s, t1.s);

    int diam = t2.f;
    if (diam <= 2 * A) {
        cout << "Alice" << endl;
    }   
    else {
        cout << "Bob" << endl;
    }   
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif
    int t;
    cin >> t;
    while (t--)
        solve();
}