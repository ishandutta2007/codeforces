#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

enum Type {add, query, sub};

struct Event {
    int p, q, v; Type t;
    Event() {}
    Event(int p, int q, int v, Type t): p(p), q(q), v(v), t(t) {}
    inline bool operator < (const Event& oth) {
        if(p!=oth.p) return p<oth.p;
        else if(t!=oth.t) return t<oth.t;
        else return 0;
    }
};

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    vector<Event> events;
    rep(i, n) {
        int x, r, q;
        cin>>x>>r>>q;
        events.eb(x-r, q, x, add);
        events.eb(x+r, q, x, sub);
        events.eb(x, q, r, query);
    }
    sort(all(events));
    ll ans=0;
    gp_hash_table<int, ordered_set<pii>> m;
    int cnt=0;
    for(Event& cur: events) {
        if(cur.t==add) m[cur.q].insert({cur.v, ++cnt});
        else if(cur.t==sub) m[cur.q].erase(m[cur.q].lower_bound({cur.v, 0}));
        else {
            for(int i=cur.q-k; i<=cur.q+k; i++) if(m.find(i)!=m.end()) {
                ans+=m[i].order_of_key({cur.p+cur.v, INT_MAX})-m[i].order_of_key({cur.p-cur.v, INT_MIN});
            }
            ans--;
        }
    }
    ans/=2;
    cout<<ans<<endl;
}