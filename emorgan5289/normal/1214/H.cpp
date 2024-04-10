#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2e5+5;
int n, k;
vector<int> adj[N];
int p[N], v[N], c[N];
multiset<int, greater<>> s[N];

void shift(int i, int j) {
    s[i].erase(s[i].find(*s[j].begin()+1));
    s[j].insert(*s[i].begin()+1);
}

void dfs1(int i, int r) {
    s[i].insert(0);
    for (int j : adj[i])
        if (j != r)
            dfs1(j, i), s[i].insert(*s[j].begin()+1);
}

void dfs2(int i, int r) {
    if (adj[i].size() >= 3) {
        auto it1 = s[i].begin(), it2 = s[i].begin();
        ++it1, ++it2, ++it2;
        if (*it1 + *it2 >= k-1)
            cout << "No\n", exit(0);
    }
    for (int j : adj[i])
        if (j != r)
            shift(i, j), dfs2(j, i), shift(j, i);
}

int bfs(int x) {
    fill(v, v+N, 0);
    queue<int> q({x}); v[x] = 1;
    while (!q.empty()) {
        x = q.front(); q.pop();
        for (int j : adj[x])
            if (!v[j]) p[j] = x, v[j] = 1, q.push(j);
    }
    return x;
}

void dfs3(int i, int x, int d) {
    // debug(i, x, d);
    c[i] = x, v[i] = 1;
    for (int j : adj[i])
        if (!v[j]) dfs3(j, (x+d+k)%k, d);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y; x--, y--;
        adj[x].pb(y), adj[y].pb(x);
    }
    if (k != 2) dfs1(0, 0), dfs2(0, 0);
    int b = bfs(0);
    int a = bfs(b);
    debug(a, b);
    vector<int> path;
    int cnt = 1;
    fill(v, v+n, 0);
    for (int x = a; x != b; x = p[x])
        cnt++, v[x] = 1;
    cnt /= 2, v[b] = 1;
    int x = 0;
    while (cnt--) {
        dfs3(a, x, -1);
        a = p[a];
        x = (x+1)%k;
    }
    while (a != b) {
        dfs3(a, x, 1);
        a = p[a];
        x = (x+1)%k;
    }
    dfs3(a, x, 1);
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << c[i]+1 << " \n"[i==n-1];
}