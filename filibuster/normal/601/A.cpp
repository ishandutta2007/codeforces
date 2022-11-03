#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 400 + 13;

/*
2 1 9
1 2 1
*/

bool g[N][N];
int d[N];

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

        g[v][u] = g[u][v] = true;
    }

    bool fl = !g[0][n - 1];

    for(int i = 0; i < n; i++)
        d[i] = INF;
    d[0] = 0;

    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
//        cout << v << ' ' << d[v] << endl;

        for(int u = 0; u < n; u++) {
            if(g[v][u] == fl && d[u] > d[v] + 1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    cout << (d[n - 1] == INF ? -1 : d[n - 1]) << endl;
}