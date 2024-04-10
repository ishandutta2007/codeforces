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

template<typename it1, typename it2, typename bin_op>
void sliding_window_fold(it1 first, it1 last, it2 result, int width, bin_op op) {
    int n = distance(first, last);
    vector p(first, last), s(first, last);
    for (int i = n-1; i >= 0; i--)
        if (i%width != width-1 && i != n-1) s[i] = op(s[i], s[i+1]);
    for (int i = 0; i < n; i++)
        if (i%width) p[i] = op(p[i], p[i-1]);
    for (int i = 0; i <= n-width; i++, result++)
        *result = i%width ? op(s[i], p[i+width-1]) : s[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(2*n);
        for (int i = 0; i < n; i++)
            cin >> a[i], a[n+i] = a[i];
        int x = 0;
        for (int i = 1<<20; i > 0; i >>= 1) {
            if (i+x <= n) {
                vector<ll> v;
                sliding_window_fold(all(a), back_inserter(v), i+x, [&](ll p, ll q){
                    return gcd(p, q);
                });
                bool ok = 0;
                for (ll y : v)
                    if (y != v[0]) ok = 1;
                if (ok) x += i;
            }
        }
        cout << x << "\n";
    }
}