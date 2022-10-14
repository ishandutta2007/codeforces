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

bool sorted(vi& a) {
    rep1(i, a.size()-1) if(a[i]<a[i-1]) return 0;
    return 1;
}

void solve(vi& a) {
    int n=a.size();
    multiset<int> s(all(a));
    vi c;
    const auto mex=[&]()->int {
        if(s.find(0)==s.end()) return 0;
        for(int it: s) if(s.find(it+1)==s.end()) return it+1;
    };
    const auto repl=[&](int id)->void {
        c.pb(id+1);
        int v=mex();
        s.erase(s.find(a[id]));
        a[id]=v;
        s.insert(a[id]);
    };
    rep(i, 2*n+1) {
        if(sorted(a)) break;
        if(mex()!=n) repl(mex());
        else {
            for(int i=n-1; i>=0; i--) if(a[i]!=i) {
                repl(i); break;
            }
        }
        assert(i!=2*n);
    }
    //rep(i, n) cout<<a[i]<<' '; cout<<endl;
    cout<<c.size()<<endl;
    for(int it: c) cout<<it<<' '; cout<<endl;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        vi a(n); rep(i, n) cin>>a[i];
        solve(a);
    }
}