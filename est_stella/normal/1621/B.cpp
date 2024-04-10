#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define pb push_back
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define pre(x) cout<<fixed; cout.precision(x);

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 998244353;

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        ll n, l = inf, r = -inf;
        ll lcost = INF, rcost = INF, totcost = INF;
        cin >> n;

        for(int i=0; i<n; i++) {
            ll x, y, c;
            cin >> x >> y >> c;

            if(x < l) lcost = totcost = INF;
            if(y > r) rcost = totcost = INF;
            l = min(l, x);
            r = max(r, y);
            
            if(l == x) lcost = min(lcost, c);
            if(r == y) rcost = min(rcost, c);
            if(l == x && r == y) totcost = min(totcost, c);

            cout << min(totcost, lcost + rcost) << "\n";
        }
    }
}