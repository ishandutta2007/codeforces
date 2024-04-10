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
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> a(n), b(n);
    for (int i = 1; i < n; i++) {
        a[i] = a[i-1], b[i] = b[i-1];
        if (s[i] == s[i-1] && s[i] == '0') a[i]++;
        if (s[i] == s[i-1] && s[i] == '1') b[i]++;
    }
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << 1+max(a[r]-a[l], b[r]-b[l]) << "\n";
    }
}