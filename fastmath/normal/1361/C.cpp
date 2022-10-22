#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

const int N = 1 << 20;

struct Graph {
ii ed[N];
vector <int> g[N];
vector <int> path;
int ptr[N];
bool del[N], used[N];

void clear() {
    path.clear();
    for (int i = 0; i < N; ++i) {
        g[i].clear();
        ptr[i] = 0;
    }   
    memset(del, 0, sizeof del);
    memset(used, 0, sizeof used);
}   

void dfs(int u) {
    while (ptr[u] < g[u].size()) {
        int i = g[u][ptr[u]];
        ++ptr[u];
        if (del[i])
            continue;
        del[i] = 1;
        int v = ed[i].f ^ ed[i].s ^ u;
        dfs(v);
    }   
    path.app(u);
}   

int comp(int u) {
    int ans = 1;
    used[u] = 1;
    for (int i : g[u]) {
        int v = ed[i].f^ed[i].s^u;
        if (!used[v])
            ans += comp(v);
    }   
    return ans;
}

} d;

int n;
int a[N], b[N];

vector <int> who[N];
bool have[N];

void solve(int w) {
    d.clear();

    memset(have, 0, sizeof have);

    int add = (1 << w) - 1;
    for (int i = 0; i < n; ++i) {
        int u = a[i] & add, v = b[i] & add;

        if (v < u)
            swap(u, v);

        d.ed[i] = mp(u, v);
        d.g[u].app(i); d.g[v].app(i);
        have[u] = have[v] = 1;
    }   

    for (int i = 0; i < n; ++i) {
        int u = a[i] & add, v = b[i] & add;
        if (d.g[u].size()&1)
            return;
        if (d.g[v].size()&1)
            return;
    }   

    int dif = 0;
    for (int i = 0; i < N; ++i) 
        dif += have[i];
        
    int start = 0;
    for (int i = 0; i < N; ++i)
        if (d.g[i].size()) 
            start = i;
    
    if (d.comp(start) != dif)
        return;

    d.dfs(start);

    if (d.path.size() != n + 1 || d.path[0] != d.path.back()) {
        return;
    }

    vector <ii> c;
    for (int i = 0; i < n; ++i) {
        c.app(d.ed[i]);
    }   
    sort(all(c));
    c.resize(unique(all(c)) - c.begin());

    for (int i = 0; i < n; ++i) {
        who[lower_bound(all(c), d.ed[i]) - c.begin()].app(i);
    }   

    /*
    cout << "path : ";
    for (auto e : d.path)
        cout << e << ' ';
    cout << endl;
    */

    cout << w << endl;
    for (int i = 0; i + 1 < d.path.size(); ++i) {

        auto p = mp(d.path[i], d.path[i + 1]);
        if (p.s < p.f)
            swap(p.f, p.s);
        int num = lower_bound(all(c), p) - c.begin();

        if (who[num].empty()) {
            cout << "LMAO" << endl;
            exit(0);
        }   

        int e = who[num].back();
        who[num].pop_back();

        if ((a[e]&add) == d.path[i]) {
            cout << 2 * (e+1) - 1 << ' ' << 2 * (e+1) << ' ';
        }   
        else {
            cout << 2 * (e+1) << ' ' << 2 * (e+1) - 1 << ' ';
        }   
    }   
    cout << endl;
    exit(0);
}

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }   
    for (int ans = 20; ans >= 0; --ans) {
        solve(ans);
    }   
}