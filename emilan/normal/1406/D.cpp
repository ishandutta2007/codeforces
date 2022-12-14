#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const ll inf = 1ll << 50;

void solve() {
    int n;
    cin >> n;
    vt<ll> a(n);
    for (ll &i : a) cin >> i;

    vt<ll> p(n);
    adjacent_difference(all(a), p.begin());

    ll plus = 0, head = a[0];
    for (int i = 1; i < n; i++) {
        if (p[i] > 0) plus += p[i];
    }

    cout << (plus + head + inf + 1) / 2 - inf / 2 << '\n';

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;

        if (!l) head += x;
        else {
            plus += max(0ll, p[l] + x) - max(0ll, p[l]);
            p[l] += x;
        }
        if (r != n - 1) {
            plus += max(0ll, p[r + 1] - x) - max(0ll, p[r + 1]);
            p[r + 1] -= x;
        }

        cout << (plus + head + inf + 1) / 2 - inf / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}