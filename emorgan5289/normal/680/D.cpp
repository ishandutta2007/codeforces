#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

map<ll, ll> magic = {{0, 0}, {2, 6}, {3, 15}, {4, 23}, {5, 50}, {7, 114}, {11, 330}, {22, 1330}, {60, 10591}, {269, 215970}, {2548, 19464802}, {74258, 16542386125}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll m, a = 0, b = 0; cin >> m;
    for (ll x = 1e5; x > 0; x--) {
        while (m >= (--magic.upper_bound(x))->second + x*x*x)
            a++, b += x*x*x, m -= x*x*x;
        m = min(m, x*x*x-1);
    }
    cout << a << " " << b << "\n";
}