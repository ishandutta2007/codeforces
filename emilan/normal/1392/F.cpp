#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define pb          push_back
#define eb          emplace_back
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<ll> a(n);
    rep(i, n) cin >> a[i];

    ll sum = accumulate(all(a), 0ll);
    sum -= n * (n - 1ll) / 2;
    rep(i, n) {
        ll cur = sum / (n - i);
        if (sum % (n - i)) cur++;
        sum -= cur;
        cout << cur + i << ' ';
    }
}