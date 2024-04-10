#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, x, y, z;
vector<pii> g[100105];
ll d[100105];
priority_queue< pair<ll, int> > q;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    while (m--) {
        cin >> x >> y >> z;
        g[x].push_back(make_pair(y, z));
        g[y].push_back(make_pair(x, z));
    }

    for (int i = 1; i <= n; ++i)
        d[i] = (ll)1e18;

    while (k--) {
        cin >> x;
        q.push(make_pair(0, x));
    }

    while (q.size()) {
        ll curd = -q.top().first;
        int curv = q.top().second;
        q.pop();
        if (d[curv] <= curd)
            continue;
        d[curv] = curd;
        for (size_t i = 0; i < g[curv].size(); ++i)
            q.push(make_pair(-curd - g[curv][i].second, g[curv][i].first));
    }

    ll ans = (ll)1e18;
    for (int i = 1; i <= n; ++i)
        if (d[i])
            ans = min(ans, d[i]);
    if (ans == (ll)1e18)
        ans = -1;
    cout << ans << endl;

    return 0;
}