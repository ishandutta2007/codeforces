#include <bits/stdc++.h>

#define x first
#define y second
#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 3000 + 13;


/*

*/

vector<int> g[N];
int d[N][N];
vector<pii> in[N], out[N];

bool cmp(pii a, pii b) {
    if(a.f != b.f)
        return a.f > b.f;
    else
        return a.s > b.s;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            d[i][j] = INF;
        d[i][i] = 0;

        queue<int> q;
        q.push(i);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(auto u : g[v])
                if(d[i][u] == INF) {
                    d[i][u] = d[i][v] + 1;
                    q.push(u);
                }
        }
    }
//cout << "fdsfh" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(j != i && d[i][j] != INF)
                out[i].emplace_back(d[i][j], j);
        sort(out[i].begin(), out[i].end(), cmp);

        for(int j = 0; j < n; j++)
            if(j != i && d[j][i] != INF)
                in[i].emplace_back(d[j][i], j);
        sort(in[i].begin(), in[i].end(), cmp);
    }

    int mx = -1;
    vector<int> ans;
//cout << "fdsfh" << endl;
    for(int v = 0; v < n; v++)
        for(int u = 0; u < n; u++)
            if(v != u && d[v][u] != INF) {
                int res = d[v][u];
                for(int i = 0; i < min(3, int(in[v].size())); i++) {
                    if(in[v][i].s != u) {
                        for(int j = 0; j < min(3, int(out[u].size())); j++) {
                            if(out[u][j].s != v && out[u][j].s != in[v][i].s) {
                                int i1 = in[v][i].s, j1 = out[u][j].s;
                                if(d[i1][v] + d[v][u] + d[u][j1] > mx) {
                                    mx = d[i1][v] + d[v][u] + d[u][j1];
                                    ans = {i1, v, u, j1};
                                }
                            }
                        }
                    }
                }
            }

    for(auto x : ans)
        cout << x + 1 << ' ';
}