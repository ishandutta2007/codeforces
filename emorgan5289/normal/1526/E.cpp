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

// returns b^r mod m, runs in O(logr) time.
template<typename T>
T powmod(T b, T r, T m) {
    T out = 1;
    for (T t = 1; t <= r; t <<= 1) {
        if (r&t) out = (out*b)%m;
        b = (b*b)%m;
    }
    return out;
}

// returns a unique number b s.t. ab = 1 mod m in O(logm) time.
template<typename T>
T inv(T a, T m) {
    T r = 1;
    for (T k = m-2; k; k >>= 1) {
        if (k&1) r = (r*a)%m;
        a = (a*a)%m;
    }
    return r%m;
}

// returns (n choose k) in O(k) time.
template<typename T>
T choose(T n, T k) {
    if (k < 0 || k > n) return 0;
    T a = 1, b = 1, r = n;
    for (T d = 1; d <= min(k, n-k); d++, r--)
        a *= r, b *= d;
    return a/b;
}

// returns (n choose k) mod m in O(k+logm) time.
template<typename T>
T choosemod(T n, T k, T m) {
    if (k < 0 || k > n) return 0;
    T a = 1, b = 1, r = n;
    for (T d = 1; d <= min(k, n-k); d++, r--)
        a = (a*r)%m, b = (b*d)%m;
    return (a*inv(b, m))%m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k; k--;
    vector<int> a(n), r(n+1), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], r[a[i]] = i+1;
    for (int i = 0; i < n; i++) {
        b[i] = r[a[i]+1];
        if (i > 0 && b[i] < b[i-1]) k--;
    }
    debug(b);
    debug(n, k);
    cout << choosemod(n+k, k, 998244353ll) << "\n";
}