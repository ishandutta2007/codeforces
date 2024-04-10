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

template<typename T>
T choose(T n, T k) {
    T a = 1, b = 1, r = n;
    k = min(k, n-k);
    for (T d = 1; d <= k; d++, r--) {
        a = a*r;
        b = b*d;
    }
    return a/b;
}

const int N = 5005;
ll x[N], y[N];
long double a[N];
const long double pi = acos((long double)-1);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = 0; j < n; j++, k++) {
            if (j == i) k--;
            else a[k] = atan2((long double)(x[j]-x[i]), (long double)(y[j]-y[i]));
        }
        sort(a, a+n-1);
        for (int j = 0; j < n-1; j++)
            a[j+n-1] = a[j]+2*pi;
        int j = 0;
        for (int k = n-1; k < 2*n-2; k++) {
            while (a[j] < a[k]-pi) j++;
            if (k-j >= 3) ans += choose(ll(k-j), 3ll);
        }
    }
    cout << 5*choose(n, 5ll) - ans << "\n";
}