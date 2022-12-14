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
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<ll> podd(n + 1), peven(n + 1);
    for (int i = 0; i < n; i++) {
        podd[i + 1] = podd[i];
        peven[i + 1] = peven[i];
        if (i & 1) peven[i + 1] += a[i];
        else podd[i + 1] += a[i];
    }

    ll ans = podd[n];
    for (int i = 1; i < n; i += 2) {
        ans = max({
            ans,
            podd[i] + peven[n] - peven[i],
            peven[i + 1] + podd[n] - podd[i + 1]
        });
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}