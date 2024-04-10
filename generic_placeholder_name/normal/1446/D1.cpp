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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=2e5+5;
int a[N];
vi v[N];

int32_t main() {
    fastio;
    int n; cin>>n;
    rep(i, n) {
        cin>>a[i];
        v[a[i]].pb(i);
    }
    int mx=1;
    rep1(i, n) if(v[i].size()>v[mx].size()) mx=i;
    rep1(i, n) if(i!=mx&&v[i].size()==v[mx].size()) {
        cout<<n<<endl;
        return 0;
    }
    int ans=0;
    set<int> s(all(v[mx]));
    rep1(i, n) if(i!=mx) {
        vector<pii> cst;
        for(int x: v[i]) {
            cst.eb(x, 1);
            rep(_, 2) if(!s.empty()) {
                auto itr=s.upper_bound(x);
                int fr=-1, bk=-1;
                if(itr!=s.end()) fr=*itr;
                if(itr!=s.begin()) bk=*prev(itr);
                if(~fr) cst.eb(fr, -1), s.erase(fr);
                if(~bk) cst.eb(bk, -1), s.erase(bk);
            }
        }
        cst.eb(n, -n);
        cc_hash_table<int, int> m;
        int cur=0;
        int prv=0;
        auto upd = [&](int x, int i) {
            if(m.find(cur)!=m.end()) ans=max(ans, i-m[cur]);
            else m[cur]=prv;
            prv=i+1;
            cur+=x;
        };
        sort(all(cst));
        for(auto& [p, v]: cst) upd(v, p);
        for(auto& [x, v]: cst) if(!~v) s.insert(x);
    }
    cout<<ans<<endl;
}