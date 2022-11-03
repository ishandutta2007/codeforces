#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vvi = vector<vector<int>>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e5 + 13;


/*

*/

vector<int> g[N];
int col[N];
int a = 0;

void dfs(int v, int cl) {
    col[v] = cl;
    if(col[v] == 1)
        a++;

    cl = (cl == 1 ? 2 : 1);

    for(auto u : g[v])
        if(col[u] == 0)
            dfs(u, cl);
        else if(col[u] == col[v]) {
            cout << -1 << endl;
            exit(0);
        }
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
        g[u].push_back(v);
    }

    for(int i = 0; i < n; i++)
        if(col[i] == 0)
            dfs(i, 1);

    cout << a << endl;
    for(int i = 0; i < n; i++)
        if(col[i] == 1)
            cout << i + 1 << ' ';

    cout << endl << n - a << endl;
    for(int i = 0; i < n; i++)
        if(col[i] == 2)
            cout << i + 1 << ' ';

}