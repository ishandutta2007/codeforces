#include<bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

string f[405];
int d[405][405], a[405], b[405];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        for (int j = 0; j < m; j++) d[i + 1][j + 1] = (f[i][j] == '0');
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i][j - 1];
        }
    }

    int ans = 100000;
    for (int l = 0; l < m; l++) {
        for (int r = l + 4; r <= m; r++) {
            int x = 0, y;
            for (int i = 1; i <= n; i++) {
                a[i] = x + d[i][r - 1] - d[i][l + 1];
                x += (r - l - 2) - (d[i][r - 1] - d[i][l + 1]);
                x += d[i][l + 1] - d[i][l];
                x += d[i][r] - d[i][r - 1];
                b[i] = x;

                //cout << a[i] << " " << b[i] << endl;
            }

            x = a[n];
            for (int i = n; i >= 5; i--) {
                x = min(x, a[i]);

                int j = i - 4;
                y = b[j] - d[j][r - 1] + d[j][l + 1];

                ans = min(ans, x - y);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}