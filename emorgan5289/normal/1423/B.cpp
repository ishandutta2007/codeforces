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
 
template<int N, int M>
struct matcher {

    vector<int> adj[N];
    int ord[N], vis[N], R[N], t;

    // add an edge between i on the left, and j on the right
    void edge(int i, int j) {
        adj[i].push_back(j);
    }

    bool dfs(int i) {
        vis[i] = t;
        for (int j : adj[i])
            if (R[j] == -1)
                return R[j] = i, 1;
        for (int j : adj[i])
            if (vis[R[j]] < t && dfs(R[j]))
                return R[j] = i, 1;
        return 0;
    }

    // returns a list of edges {left, right}. runs in O(E \sqrt V) time.
    vector<pair<int, int>> solve() {
        iota(ord, ord+N, 0);
        random_shuffle(ord, ord+N);
        fill(R, R+M, -1); t = 0;
        for (int i = 0; i < N; i++)
            if (!dfs(i)) break;
            else t++;
        vector<pair<int, int>> out;
        for (int i = 0; i < N; i++)
            if (R[i] != -1)
                out.emplace_back(R[i], i);
        return out;
    }
};
 
matcher<10005, 10005> b;
array<int, 3> e[100005];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> e[i][1] >> e[i][2] >> e[i][0];
    sort(e, e+m);
    int l = 0, r = m+1;
    while (l < r) {
        int x = (l+r)/2;
        for (int i = 0; i < n; i++)
            b.adj[i].clear();
        for (int i = 0; i < x; i++)
            b.edge(e[i][1]-1, e[i][2]-1);
        if (b.solve().size() == n) r = x;
        else l = x+1;
    }
    cout << (l == m+1 ? -1 : e[l-1][0]) << "\n";
}