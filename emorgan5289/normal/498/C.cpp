#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back
 
#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif
 
// computes maximum matching in a bipartite graph
// N vertices on the left, and M vertices on the right
template<int N, int M>
struct matcher {
 
    vector<int> adj[N];
    int ord[N], L[N], R[M];
    bool vis[N];
 
    // add an edge between i on the left, and j on the right
    void edge(int i, int j) {
        adj[i].push_back(j);
    }
 
    bool dfs(int i) {
        if (vis[i]) return 0;
        vis[i] = 1;
        for (int j : adj[i])
            if (R[j] == -1)
                return L[i] = j, R[j] = i, 1;
        for (int j : adj[i])
            if (dfs(R[j]))
                return L[i] = j, R[j] = i, 1;
        return 0;
    }
 
    // returns a list of edges {left, right}. runs in O(E \sqrt V) time.
    int solve() {
        iota(ord, ord+N, 0);
        random_shuffle(ord, ord+N);
        fill(L, L+N, -1), fill(R, R+M, -1);
        bool v = 1;
        while (v) {
            v = 0;
            fill(vis, vis+N, 0);
            for (int i : ord)
                if (!vis[i] && L[i] == -1)
                    v = v || dfs(i);
        }
        int out = 0;
        for (int i = 0; i < N; i++)
            if (L[i] != -1) out++;
        return out;
    }
};
 
// returns a sorted list of all prime factors of n in O(sqrt(n)) time.
template<typename T>
vector<T> primefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            n /= i; i--;
        }
    }
    return out;
}
 
matcher<50000, 50000> f;
vector<ll> a[500];
int b[500];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = primefactors(x);
        b[i] = (i < 2 ? 0 : b[i-2]) + a[i].size();
    }
    for (int i = 0; i < n; i++)
        b[i] -= a[i].size();
    while (m--) {
        int x, y; cin >> x >> y; x--, y--;
        if (x&1) swap(x, y);
        for (int i = 0; i < a[x].size(); i++)
            for (int j = 0; j < a[y].size(); j++)
                if (a[x][i] == a[y][j]) {
                    f.edge(b[x]+i, b[y]+j);
                }
    }
    cout << f.solve() << "\n";
}