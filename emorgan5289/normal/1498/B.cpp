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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, w; cin >> n >> w;
        vector<ll> a(n);
        multiset<ll, greater<>> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(all(a), greater<>());
        for (ll x : a) {
            bool ok = 0;
            if (s.empty()) {
                s.insert(w-x); continue;
            }
            ll y = *s.begin();
            if (x <= y)
                s.erase(s.begin()), s.insert(y-x);
            else
                s.insert(w-x);
        }
        cout << s.size() << "\n";
    }
}