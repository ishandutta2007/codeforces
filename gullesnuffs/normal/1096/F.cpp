#include <bits/stdc++.h>

#include <iostream>
#include <map>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> /** keep-include */
#include <ext/pb_ds/tree_policy.hpp> /** keep-include */
using namespace __gnu_pbds;

template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
          tree_order_statistics_node_update>;
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

const ll mod = (119 << 23) + 1, root = 3; // = 998244353

ll modpow(ll a, ll e) {
	if (e == 0) return 1;
	ll x = modpow(a * a % mod, e >> 1);
	return e & 1 ? x * a % mod : x;
}

ll inv(ll a) {
    return modpow(a, mod-2);
}

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> p(n);
    set<int> missing;
    Tree<int> present;
    rep(i,1,n+1)
        missing.insert(i);
    rep(i,0,n) {
        cin >> p[i];
        missing.erase(p[i]);
    }
    vector<int> missingList;
    for (auto it : missing)
        missingList.push_back(it);
    ll ans = 0;
    ll missingSeen = 0;
    ll presentSeen = 0;
    ll totMissing = sz(missing);
    rep(i,0,n) {
        if (p[i] == -1) {
            ++missingSeen;
        }
        else {
            ll presentInd = presentSeen - present.order_of_key(p[i]);//present.end() - lower_bound(all(present), p[i]);
            ans += presentInd;
            present.insert(p[i]);
            ll ind = lower_bound(all(missingList), p[i])-missingList.begin();
            ll numerator = (ind * (totMissing - missingSeen) + (totMissing - ind) * missingSeen);
            numerator %= mod;
            ans += (numerator * inv(totMissing))%mod;
            ans %= mod;
            presentSeen++;
        }
    }
    ans += (((totMissing*(totMissing-1)))%mod)*inv(4);
    ans %= mod;
    cout << ans << endl;
}