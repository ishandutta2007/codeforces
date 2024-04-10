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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    multiset<ll> s;
    ll x = 0;
    while (n--) {
        ll a; cin >> a;
        if (s.upper_bound(a) != s.begin()) {
            x += a-*s.begin();
            s.erase(s.begin());
            s.insert(a);
        }
        s.insert(a);
    }
    cout << x << "\n";
}