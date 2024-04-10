#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 500;
int adj[N][N], dist[N][N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    memset(dist, 31, sizeof(dist));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    vector<int> p(n);
    for (int &x : p) cin >> x, x--;
    reverse(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        for (int u = 0; u < i; u++) {
            for (int v = 0; v < i; v++) {
                dist[p[i]][p[v]] = min(
                    adj[p[i]][p[u]] + dist[p[u]][p[v]],
                    dist[p[i]][p[v]]
                );
                dist[p[v]][p[i]] = min(
                    dist[p[v]][p[u]] + adj[p[u]][p[i]],
                    dist[p[v]][p[i]]
                );
            }
        }

        for (int u = 0; u < i; u++) {
            for (int v = 0; v < i; v++) {
                dist[p[u]][p[v]] = min(
                    dist[p[u]][p[i]] + dist[p[i]][p[v]],
                    dist[p[u]][p[v]]
                );
            }
        }

        for (int u = 0; u <= i; u++) {
            for (int v = 0; v <= i; v++) {
                ans[i] += dist[p[u]][p[v]];
            }
        }
    }

    reverse(ans.begin(), ans.end());
    for (ll x : ans) cout << x << ' ';
}