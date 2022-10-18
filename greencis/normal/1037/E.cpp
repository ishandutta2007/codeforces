#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, a[200105], b[200105], ans[200105];
set<int> g[200105];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        g[a[i]].insert(b[i]);
        g[b[i]].insert(a[i]);
    }
    queue<int> q;
    set<int> st;
    for (int i = 1; i <= n; ++i)
        q.push(i), st.insert(i);
    for (int i = m - 1; i >= 0; --i) {
        while (q.size()) {
            int v = q.front();
            q.pop();
            if (!st.count(v) || g[v].size() >= k)
                continue;
            st.erase(v);
            for (int to : g[v])
                g[to].erase(v), q.push(to);
            g[v].clear();
        }
        ans[i] = st.size();
        g[a[i]].erase(b[i]);
        g[b[i]].erase(a[i]);
        q.push(a[i]);
        q.push(b[i]);
    }
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
}