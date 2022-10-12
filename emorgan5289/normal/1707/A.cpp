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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll iq = 0;
        string s(n, '0');
        for (int i = n-1; i >= 0; i--) {
            if (a[i] > iq) {
                if (iq < q)
                    iq++, s[i] = '1';
            } else s[i] = '1';
        }
        cout << s << '\n';
    }
}