#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    vector<ll> a(n);
    for (auto& x : a) fin >> x;
    for (auto& x : a) {
        ll y; fin >> y; x -= y;
    }
    sort(all(a));
    debug(a);
    ll out = 0;
    for (ll i = 1; i < n; i++) {
        ll x = 0, y = i;
        while (x < y) {
            ll m = (x+y)/2;
            if (a[m] > -a[i]) y = m;
            else x = m+1;
        }
        debug(i, x);
        out += i-x;
    }
    cout << out << "\n";
}