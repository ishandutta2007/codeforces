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

const int N = 1007;

set <int> g[N];
int dist1[N], dist2[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    for (int i = 0; i < N; ++i) {
        dist1[i] = -1;
        dist2[i] = -1;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].insert(v);
        g[v].insert(u);
    }
    queue <int> q;
    q.push(s);
    dist1[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dist1[v] == -1) {
                dist1[v] = dist1[u] + 1;
                q.push(v);
            }
        }
    }
    dist2[t] = 0;
    q.push(t);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (dist2[v] == -1) {
                dist2[v] = dist2[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!g[i].count(j) && min(dist1[i] + 1 + dist2[j], dist1[j] + 1 + dist2[i]) >= dist1[t]) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}