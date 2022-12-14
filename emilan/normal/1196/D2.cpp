#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

int p[3][200001];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        rep(i, 3) fill(p[i], p[i] + n + 1, 0);

        rep(i, n) {
            rep(j, 3) p[j][i + 1] = p[j][i];
            if (s[i] == 'R') p[(-i % 3 + 3) % 3][i + 1]++;
            else if (s[i] == 'G') p[(-i % 3 + 4) % 3][i + 1]++;
            else p[(-i % 3 + 5) % 3][i + 1]++;
        }

        int mn = 1 << 30;
        rep(i, n - k + 1) {
            rep(j, 3) {
                mn = min(mn, k - p[j][i + k] + p[j][i]);
            }
        }
        
        cout << mn << '\n';
    }
}