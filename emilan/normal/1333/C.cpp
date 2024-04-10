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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<ll> s(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        s[i] = s[i + 1] + a[i];
    }

    multiset<ll> ss;
    int l = 0;
    ll ans = 0;
    for (int r = 1; r <= n; r++) {
        ss.insert(s[r - 1]);
        while (ss.count(s[r])) {
            ss.erase(ss.find(s[l++]));
        }
        ans += r - l;
    }

    cout << ans;
}