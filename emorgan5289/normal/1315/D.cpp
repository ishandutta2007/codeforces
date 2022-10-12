#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000ll
#define inf_ull 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

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

pair<ll, ll> p[300005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    for (ll i = 0; i < n; i++) fin >> p[i].first;
    for (ll i = 0; i < n; i++) fin >> p[i].second;
    for (int i = 0; i < 15; i++) debug(i, p[i]);
    sort(p, p+n);

    multiset<ll> m; ll mcost = 0;
    ll cost = 0;
    for (ll i = 0; i < n; i++) {
        ll a = p[i].first, t = p[i].second;
        m.insert(-t); mcost += t;
        ll limit = (i == n-1 ? inf_ull : p[i+1].first);
        for (ll j = p[i].first; j < limit; j++) {
            if (m.empty()) break;
            auto it = m.begin();
            cost -= (j-p[i].first)**it;
            mcost += *it;
            m.erase(it);
        }
        cost += mcost*(limit-p[i].first);
    }
    assert(mcost == 0);
    cout << cost << "\n";
}