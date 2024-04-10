#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pli = pair<ll, int>;

ll calc(int x, int d) {
    int y = x / d;
    int r = x % d;
    return r * ll(y + 1) * (y + 1) + ll(d - r) * y * y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    ll ans = 0;
    priority_queue<pli> q;
    vt<int> b(n, 1);
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i]) {
            q.emplace(calc(a[i], 1) - calc(a[i], 2), i);
        }
        ans += calc(a[i], 1);
    }

    k = k - n;
    while (k--) {
        ans -= q.top().fi;
        int i = q.top().se;
        q.pop();

        b[i]++;
        if (b[i] != a[i]) {
            q.emplace(calc(a[i], b[i]) - calc(a[i], b[i] + 1), i);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}