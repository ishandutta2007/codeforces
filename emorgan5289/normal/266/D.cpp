#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 205;
ll c[N][N];
tuple<int, int, double> e[N*N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = i == j ? 0 : inf_ll;
    for (int i = 0; i < m; i++) {
        ll u, v, w; cin >> u >> v >> w; u--, v--;
        c[u][v] = c[v][u] = w;
        e[i] = {u, v, w};
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
    double out = inf_ll;
    for (int i = 0; i < n; i++)
        out = min(out, (double)*max_element(c[i], c[i]+n));
    for (int i = 0; i < m; i++) {
        auto& [u, v, w] = e[i];
        vector<pair<double, double>> l;
        for (int j = 0; j < n; j++) {
            debug(c[u][j], c[v][j]);
            l.pb({-c[u][j], w+c[v][j]});
        }
        sort(all(l));
        double r = -inf_ll;
        for (auto& [x, y] : l) {
            if (y > r && (x+r)/2 >= 0 && (x+r)/2 <= w)
                out = min(out, (r-x)/2);
            r = max(r, y);
        }
    }
    cout << setprecision(25) << out << "\n";
}