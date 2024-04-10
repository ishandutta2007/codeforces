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

const ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, y, out = 0; cin >> n >> x >> y;
    multiset<pair<ll, bool>> s;
    priority_queue<ll> q;
    for (int i = 0; i < n; i++) {
        ll l, r; cin >> l >> r;
        out = (out+x+y*(r-l))%mod;
        s.insert({l, 0});
        s.insert({r, 1});
    }
    for (auto& [p, t] : s) {
        if (!t && !q.empty())
            out = (out+mod+min(0ll, y*(p-q.top())-x))%mod, q.pop();
        else if (t) q.push(p);
    }
    cout << out << "\n";
}