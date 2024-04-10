#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        ll a, b, q; cin >> a >> b >> q;
        ll n = a*b/__gcd(a, b);
        vector<ll> p(n);
        for (ll i = 0; i < n; i++)
            p[i] = ((i%a)%b != (i%b)%a ? 1 : 0) + (i == 0 ? 0 : p[i-1]);

        while (q--) {
            ll l, r; cin >> l >> r;
            ll j = (r-l)/n;
            ll out = j*p[n-1];
            r -= j*n;
            j = l/n;
            r = (r-j*n)%n; l -= j*n;
            if (l <= r)
                out += p[r] - (l == 0 ? 0 : p[l-1]);
            else
                out += p[r] - (l == 0 ? 0 : p[l-1]) + p[n-1];
            cout << out << " ";
        }
        cout << "\n";
    }
}