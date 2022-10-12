#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))
 
#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif
 
ll n, k;
 
ll qry(vector<ll> p) {
    // assert(p.size() == k);
    cout << "?";
    for (int i = 0; i < p.size(); i++)
        cout << " " << p[i]+1;
    cout << endl;
    ll r; cin >> r; return r;
}
 
void solve1() {
    vector<ll> x;
    ll l = 0, ans = 0;
    while (1) {
        if (n-l <= 2*k && (n-l)%2 == 0) break;
        x.clear();
        for (int i = l; i < l+k; i++)
            x.pb(i);
        ans ^= qry(x);
        l += k;
    }
    ll v = (n-l)/2;
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+i);
    ans ^= qry(x);
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+v+i);
    ans ^= qry(x);
    l = n;
    cout << "! " << ans << endl;
}
 
void solve2() {
    vector<ll> x;
    ll l = 0, ans = 0;
    x.clear();
    for (int i = l; i < l+k; i++)
        x.pb(i);
    ans ^= qry(x);
    l += k;
    ll v = (n-l)/2;
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+i);
    ans ^= qry(x);
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+v+i);
    ans ^= qry(x);
    l = n;
    cout << "! " << ans << endl;
}
 
vector<ll> invert(vector<ll> x) {
    vector<ll> y;
    vector<ll> f(n);
    for (int i : x) f[i]++;
    for (int i = 0; i < n; i++)
        if (!f[i]) y.pb(i);
    return y;
}
 
void solve3() {
    vector<ll> x;
    k = n-k;
    ll l = 0, ans = 0;
    while (1) {
        if (n-l <= 2*k && (n-l)%2 == 0) break;
        x.clear();
        for (int i = l; i < l+k; i++)
            x.pb(i);
        debug(x, invert(x));
        ans ^= qry(invert(x));
        l += k;
    }
    ll v = (n-l)/2;
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+i);
    ans ^= qry(invert(x));
    x.clear();
    for (int i = 0; i < k-v; i++)
        x.pb(i);
    for (int i = 0; i < v; i++)
        x.pb(l+v+i);
    ans ^= qry(invert(x));
    l = n;
    cout << "! " << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    if ((n%2 == 1) && (k%2 == 0)) {
        cout << "-1\n"; return 0;
    }
    if (n == k) {
        ll ans = 0;
        vector<ll> x;
        for (int i = 0; i < n; i++)
            x.pb(i);
        ans ^= qry(x);
        cout << "! " << ans << "\n";
    } else if (2*k <= n) {
        solve1();
    } else if (n%2 == k%2) {
        solve2();
    } else {
        // k odd, n even, k > n/2
        solve3();
    }
}