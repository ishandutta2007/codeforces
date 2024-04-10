#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, a[200200];
vector<int> g[200200];
int d[2][200200];

void bfs(int c, int v) {
    queue<pii> q;
    q.emplace(v, 0);
    while (!q.empty()) {
        int curd = q.front().second;
        int curv = q.front().first;
        q.pop();
        if (d[c][curv] != -1) continue;
        d[c][curv] = curd;
        ++curd;
        for (int to : g[curv])
            q.emplace(to, curd);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(d, -1, sizeof d);
    bfs(0, 1);
    bfs(1, n);

    int mx = -1e9;
    vector<pii> v;
    multiset<pii> st;
    for (int i = 0; i < k; ++i) {
        v.emplace_back(d[0][a[i]] - d[1][a[i]], i);
        st.emplace(d[1][a[i]], -d[0][a[i]]);
    }
    sort(all(v));
    for (int i = 0; i + 1 < k; ++i) {
        st.erase(st.find(make_pair(d[1][a[v[i].second]], -d[0][a[v[i].second]])));
        mx = max(mx, st.rbegin()->first + d[0][a[v[i].second]] + 1);
    }
    mx = min(mx, d[0][n]);
    cout << mx << endl;
}
/**
6 5 2
3 4
1 2 2 3 4 5 5 6 1 6
*/