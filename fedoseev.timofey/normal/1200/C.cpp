#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n, m; int q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll szn = n / g, szm = m / g;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        --b, --d;
        ll n1 = (a == 1 ? b / szn : b / szm);
        ll n2 = (c == 1 ? d / szn : d / szm);
        if (n1 == n2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}