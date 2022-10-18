#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll inf = 4.5e18;

int n;
ll x[2005], y[2005], c[2005], k[2005];
ll dp[2005];
ll d[2005][2005];
int u[2005], p[2005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 0; i < n; ++i) cin >> k[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            d[i][j] = dist * (k[i] + k[j]);
        }
        d[n][i] = d[i][n] = c[i];
    }

    fill_n(dp, n + 1, inf);
    fill_n(p, n + 1, -1);
    dp[n] = 0;
    vector<pii> edges;
    vector<int> stations;
    ll ans = 0;
    for (int iter = 0; iter <= n; ++iter) {
        ll mn = inf;
        int mni = -1;
        for (int i = 0; i <= n; ++i) {
            if (!u[i] && dp[i] < mn) {
                mn = dp[i];
                mni = i;
            }
        }
        u[mni] = 1;
        ans += mn;
        if (mni < 0)
            break;
        if (p[mni] != -1) {
            int a = p[mni];
            int b = mni;
            if (a > b) swap(a, b);
            if (b == n)
                stations.push_back(a);
            else
                edges.emplace_back(a, b);
        }
        for (int i = 0; i <= n; ++i) {
            if (u[i]) continue;
            if (dp[i] > d[mni][i]) {
                p[i] = mni;
                dp[i] = d[mni][i];
            }
        }
    }

    cout << ans << endl;
    cout << stations.size() << endl;
    sort(all(stations));
    for (int x : stations)
        cout << x + 1 << " ";
    cout << endl;
    cout << edges.size() << endl;
    sort(all(edges));
    for (auto& p: edges) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}