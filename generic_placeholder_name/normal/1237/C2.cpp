#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

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

struct pt {
    int x, y, z, idx;
    pt(int x, int y, int z, int idx): x(x), y(y), z(z), idx(idx) {}
    bool operator < (const pt& oth) const {
        return mp(mp(x, y), z)<mp(mp(oth.x, oth.y), oth.z);
        //ok that was galaxy-level stupid
    }
};

int32_t main() {
    fastio;
    //for the sake of completeness
    //also, things look significantly easier when you're orange than when you're cyan
    int n; cin>>n;
    vector<pt> pts; pts.reserve(n);
    rep1(i, n) {
        int x, y, z; cin>>x>>y>>z;
        pts.eb(x, y, z, i);
    }
    sort(all(pts));
    vector<pt> rem;
    rep(i, pts.size()) {
        if(i==pts.size()-1||pts[i].x!=pts[i+1].x||pts[i].y!=pts[i+1].y) rem.pb(pts[i]);
        else cout<<pts[i].idx<<' '<<pts[i+1].idx<<endl, i++;
    }
    //thank god this code is scalable
    pts=rem; rem.clear();
    rep(i, pts.size()) {
        if(i==pts.size()-1||pts[i].x!=pts[i+1].x) rem.pb(pts[i]);
        else cout<<pts[i].idx<<' '<<pts[i+1].idx<<endl, i++;
    }
    for(int i=0; i<rem.size(); i+=2) cout<<rem[i].idx<<' '<<rem[i+1].idx<<endl;
}