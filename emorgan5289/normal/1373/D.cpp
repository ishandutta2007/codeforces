#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 200005;
ll a[N], p[N];

ll solve(int n) {
    ll x = 0, r = 0, m = 0;
    for (int i = 0; i < n; i++)
        x += p[i], r = max(r, x-m), m = min(m, x);
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while (t--) {
        ll n, out = 0; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        fill(p, p+n, 0);
        for (int i = 0; i < n; i++)
            p[i/2] += a[i]*(i&1 ? 1 : -1);
        out = max(out, solve(n/2));
        fill(p, p+n, 0);
        for (int i = 1; i < n; i++)
            p[(i-1)/2] += a[i]*(i&1 ? 1 : -1);
        out = max(out, solve((n-1)/2));
        for (int i = 0; i < n; i += 2)
            out += a[i];
        cout << out << "\n";
    }
}