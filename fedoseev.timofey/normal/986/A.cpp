#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
vector <vector <int>> num;
vector <int> dist[N];
int n;

void bfs(int t) {
    queue <int> q;
    vector <int> d(n, -1);
    for (auto i : num[t]) {
        q.push(i);
        d[i] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dist[i].push_back(d[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int m, k, s;
    cin >> n >> m >> k >> s;
    num.resize(k);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        num[a].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < k; ++i) bfs(i);
    for (int i = 0; i < n; ++i) {
        ll res = 0;
        sort(dist[i].begin(), dist[i].end());
        for (int j = 0; j < s; ++j) {
            res += dist[i][j];
        }
        cout << res << ' ';
    }
}