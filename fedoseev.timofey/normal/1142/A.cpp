#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

int n, k, a, b;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll get(ll st) {
    ll ln = (ll)n * k;
    ll cr = lcm(ln, st);
    return cr / st;
}

ll mn = 2e18, mx = -2e18;

void upd(ll st) {
    for (ll i = st; i <= n * k; i += k) {
        if (i <= 0) continue;
        mn = min(mn, get(i));
        mx = max(mx, get(i));
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k >> a >> b;
    upd(abs(a - b));
    upd(k - a - b);
    cout << mn << ' ' << mx << '\n';
}