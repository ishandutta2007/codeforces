#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n), c(n, 0); 
    for (auto& x : a) cin >> x;
    ll q; cin >> q;
    map<pair<ll, ll>, ll> m;
    ll out = 0;
    for (auto& x : a) out += x;
    while (q--) {
        ll s, t, u; cin >> s >> t >> u;
        u--;
        if (m.count({s, t})) {
            ll x = m[{s, t}];
            c[x]--;
            if (c[x] < a[x]) out++;
            m.erase(m.find({s, t}));
        }
        if (u != -1) {
            m[{s, t}] = u;
            c[u]++;
            if (c[u] <= a[u]) out--;
        }
        cout << out << "\n";
    }
}