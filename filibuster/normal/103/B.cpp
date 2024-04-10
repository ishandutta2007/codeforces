#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

vector<int> g[N];
int used[N];
int cnt = 0;

void dfs(int v) {
    used[v] = 1;
    cnt++;

    for(auto u : g[v])
        if(used[u] == 0)
            dfs(u);
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0);

    cout << (n == m && cnt == n ? "FHTAGN!" : "NO") << endl;
}