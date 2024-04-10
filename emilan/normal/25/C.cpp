#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n;
    cin >> n;
    vt<vt<int>> adj(n, vt<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int k;
    cin >> k;
    while (k--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        ll sumDist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int newDist = min(
                    adj[i][a] + c + adj[b][j],
                    adj[i][b] + c + adj[a][j]
                );
                if (newDist < adj[i][j]) {
                    adj[i][j] = adj[j][i] = newDist;
                }
                sumDist += adj[i][j];
            }
        }

        cout << sumDist << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}