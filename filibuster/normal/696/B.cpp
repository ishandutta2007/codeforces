#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

vector<int> g[N];
ld ans[N];
int sz[N];

void dfs(int v, int par) {
    sz[v] = 1;
    for(auto u : g[v])
        if(u != par) {
            dfs(u, v);
            sz[v] += sz[u];
        }

    for(auto u : g[v]) {
        if(u != par) {
            ans[u] = ld(sz[v] - sz[u] - 1) / 2 + ans[v] + 1;
        }
    }
}

void dfs2(int v, int par) {
    for(auto u : g[v]) {
        if(u != par) {
            ans[u] = ld(sz[v] - sz[u] - 1) / 2 + ans[v] + 1;
            dfs2(u, v);
        }
    }


}


int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;

        g[p].push_back(i);
        g[i].push_back(p);
    }

    ans[0] = 1;
    dfs(0, 0);
    dfs2(0, 0);

    for(int i = 0; i < n; i++) {
        cout << setprecision(20) << fixed << ans[i] << ' ';
    }
}