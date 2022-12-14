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

const int maxn = 3001;
int cnt[maxn][maxn];

void solve(int tc) {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    for (int i = 0; i <= n; i++) fill(cnt[i], cnt[i] + n + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][a[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += cnt[i][a[j]] * (cnt[n][a[i]] - cnt[j + 1][a[i]]);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}