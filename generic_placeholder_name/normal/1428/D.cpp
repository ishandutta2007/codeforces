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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

int32_t main() {
    fastio;
    int n; cin>>n;
    int a[n]; rep(i, n) cin>>a[i];
    set<int> pos[4];
    bool vis[n]={0};
    vector<pii> ans;
    rep(i, n) pos[a[i]].insert(i);
    int prv=-1, h=1;
    rep(i, n) if(a[i]==3) {
        if(~prv) {
            pos[3].erase(prv);
            ans.eb(i+1, h++);
            ans.eb(i+1, h);
        }
        else ans.eb(i+1, h);
        prv=i;
    }
    if(~prv) {
        auto nxt=pos[2].upper_bound(prv);
        if(nxt==pos[2].end()||pos[1].upper_bound(*nxt)==pos[1].end()) {
            nxt=pos[1].upper_bound(prv);
            if(nxt==pos[1].end()) return cout<<"-1\n", 0;
            int p=*nxt;
            ans.eb(p+1, h++);
            ans.eb(p+1, h++);
            pos[1].erase(p);
        }
        else {
            int p2=*nxt; 
            pos[2].erase(p2);
            int p1=*pos[1].upper_bound(p2);
            pos[1].erase(p1);
            ans.eb(p2+1, h++);
            ans.eb(p2+1, h);
            ans.eb(p1+1, h++);
        }
    }
    rep(i, n) {
        if(a[i]==1) {
            if(pos[1].find(i)==pos[1].end()) continue;
            pos[1].erase(i);
            ans.eb(i+1, h++);
        }
        else if(a[i]==2) {
            if(pos[2].find(i)==pos[2].end()) continue;
            auto nxt=pos[1].upper_bound(i);
            if(nxt==pos[1].end()) return cout<<"-1\n", 0;
            int p=*nxt;
            ans.eb(i+1, h);
            ans.eb(p+1, h++);
            pos[1].erase(p);
        }
        else if(a[i]==3) continue;
    }
    if(h>n+1) return cout<<"-1\n", 0;
    cout<<ans.size()<<endl;
    for(auto& it: ans) cout<<it.se<<' '<<it.fi<<endl;
}