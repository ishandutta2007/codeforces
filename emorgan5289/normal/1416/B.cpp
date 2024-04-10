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

void solve() {
    int n; cin >> n;
    ll s = 0;
    vector<ll> a(n);
    for (auto& x : a)
        cin >> x, s += x;
    if (s%a.size() != 0) {
        cout << "-1\n"; return;
    }
    vector<array<ll, 3>> v;
    for (int i = 1; i < n; i++) {
        v.pb({1, i+1, (1-a[i])%(i+1)+i});
        v.pb({i+1, 1, (a[i]-1)/(i+1)+1});
    }
    for (int i = 1; i < n; i++)
        v.pb({1, i+1, ll(s/a.size())});
    cout << v.size() << "\n";
    for (auto& [i, j, x] : v)
        cout << i << " " << j << " " << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}