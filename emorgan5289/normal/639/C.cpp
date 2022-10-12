#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5;
ll a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    ll l = -1, r = 0;
    for (ll i = 0; i < n+200; i++) {
        b[i+1] += (a[i]+b[i])/2;
        b[i] = (a[i]+b[i])%2;
        if (b[i] != 0) {
            r = i+1;
            if (l == -1) l = i;
        }
    }
    ll t = 0;
    for (ll i = 0; i <= r; i++)
        t += (1ll<<i)*a[i];
    ll s = 0, c = 0;
    for (ll i = max(n, r); i >= 0; i--) {
        s = (2*s)+b[i];
        if (abs(s) > 4*k) break;
        if (i <= min(n, l) && abs(a[i]-s) <= k && (i != n || a[i]-s != 0)) c++;
    }
    cout << c << "\n";
}