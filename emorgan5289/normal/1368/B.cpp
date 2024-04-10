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

const string cf = "codeforces";

pair<ll, string> solve(int t) {
    ll w = t/10;
    ll x = 1;
    string s = "";
    for (ll i = 0; i < 10; i++) {
        ll y = w;
        if (i < (t%10))
            y++;
        for (ll j = 0; j < y; j++)
            s += cf[i];
        x *= y;
    }
    return {x, s};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k; cin >> k;
    string s;
    ll a = 10, b = 800;
    while (a < b) {
        int m = (a+b)/2;
        auto [x, weioytweir] = solve(m);
        if (x >= k)
            b = m;
        else
            a = m+1;
    }
    debug(a);
    cout << solve(a).second << "\n";
}