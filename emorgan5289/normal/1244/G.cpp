#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    ll x = 0;
    for (ll i = 1; i <= n; i++)
        x += max(i, n-i+1);
    k = min(k, x)-n*(n+1)/2;
    if (k < 0)
        return cout << "-1\n", 0;
    cout << k+n*(n+1)/2 << "\n";
    ll p = 1;
    for (ll r = n-1; r > 1; r -= 2) {
        if (r <= k) p++, k -= r;
        else break;
    }
    for (ll i = 1; i <= n; i++)
        cout << i << " \n"[i == n];
    for (ll i = 1; i <= n; i++) {
        if (i < p+k)
            x = i+p;
        else if (i == p+k)
            x = p;
        else if (i > n-p+1)
            x = n-i+1;
        else if (i > p+k)
            x = i+p-1;
        cout << x << " ";
    }
}