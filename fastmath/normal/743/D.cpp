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

const int N = 5e5 + 7, INF = 1e18;
vector <int> g[N];
int n;
int a[N];

int l[N], r[N], ptr = 0;

void dfs(int u, int p) {
    l[u] = ++ptr;
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            a[u] += a[v];
        }   
    }                               
    r[u] = ++ptr;
}   

int post[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        g[u].app(v);
        g[v].app(u);
    }   
    dfs(1, 1);

    for (int i = 0; i < N; ++i)
        post[i] = -INF;
    for (int i = 1; i <= n; ++i) {
        //cout << l[i] << ' ' << a[i] << endl;
        post[l[i]] = a[i];
    }   
    for (int i = N - 2; i >= 0; --i) {
        post[i] = max(post[i], post[i + 1]);
    }   
    /*
    for (int i = 1; i <= 3 * n; ++i)
        cout << post[i] << ' ';
    cout << endl;
    */
    int ans = -INF;
    for (int i = 1; i <= n; ++i) {
        int add = post[r[i] + 1];
        if (add != -INF)
            ans = max(ans, a[i] + add);            

        //cout << i << ' ' << a[i] << ' ' << add << endl;
    }   
    if (ans == -INF)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
}