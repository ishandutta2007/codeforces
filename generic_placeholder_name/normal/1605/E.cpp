#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 2e5 + 5;
int a[N], b[N];
ll c[N];
int mu[N], f[N];

int32_t main() {
    fastio;
    int n; cin >> n;
    mu[1] = 1;
    for(int i = 2; i * i <= n; i++) if(!f[i]) {
        for(int j = i * i; j <= n; j += i) if(!f[j]) f[j] = i;
    }
    for(int i = 2; i <= n; i++) {
        if(!f[i]) f[i] = i;
        if((i / f[i]) % f[i] == 0) mu[i] = 0;
        else mu[i] = -mu[i / f[i]];
    }
    rep1(i, n) cin >> a[i];
    rep1(i, n) cin >> b[i];
    rep1(i, n) c[i] = a[i] - b[i];
    ll sum = 0;
    vll p;
    for(int i = 2; i <= n; i++) {
        for(int j = i + i; j <= n; j += i) {
            c[j] -= c[i];
        }
        if(mu[i]) p.pb(mu[i] * c[i]);
        else sum += abs(c[i]);
    }
    vll pos, neg;
    for(auto& x: p) {
        if(x >= 0) pos.pb(x);
        else neg.pb(-x);
    }
    sort(all(pos));
    sort(all(neg));
    vll pfpos, pfneg;
    ll ss = 0; for(auto& x: pos) pfpos.eb(ss += x);
    ss = 0; for(auto& x: neg) pfneg.eb(ss += x);
    int ps = pos.size(), ns = neg.size();
    int q; cin >> q;
    while(q--) {
        int x; cin >> x; x = a[1] - x;
        ll ans = sum + abs(x);
        if(x >= 0) {
            if(!pos.empty()) ans += pfpos[ps - 1] + pos.size() * 1LL * x;
            if(!neg.empty()) {
                int p = upper_bound(all(neg), x) - neg.begin();
                if(p == 0) ans += pfneg[ns - 1] - neg.size() * 1LL * x;
                else {
                    ans += p * 1LL * x - pfneg[p - 1];
                    ans += pfneg[ns - 1] - pfneg[p - 1] - (ns - p) * 1LL * x;
                }
            }
        }
        else {
            x = -x;
            if(!neg.empty()) ans += pfneg[ns - 1] + neg.size() * 1LL * x;
            if(!pos.empty()) {
                int p = upper_bound(all(pos), x) - pos.begin();
                if(p == 0) ans += pfpos[ps - 1] - pos.size() * 1LL * x;
                else {
                    ans += p * 1LL * x - pfpos[p - 1];
                    ans += pfpos[ps - 1] - pfpos[p - 1] - (ps - p) * 1LL * x;
                }
            }
        }
        cout << ans << endl;
    }
}