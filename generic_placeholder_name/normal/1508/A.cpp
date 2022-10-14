#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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

string bld(const string& a, const string& b, char tg) {
    char p=tg^1;
    vi posa, posb;
    rep(i, a.size()) if(a[i]==tg) posa.pb(i);
    rep(i, b.size()) if(b[i]==tg) posb.pb(i);
    string s;
    int sz=min(posa.size(), posb.size());
    rep(i, sz) {
        int df=max(posa[i]-(i?posa[i-1]:-1), posb[i]-(i?posb[i-1]:-1))-1;
        rep(j, df) s.pb(p);
        s.pb(tg);
    }
    for(int i=posa[sz-1]+1; i<a.size(); i++) s.pb(a[i]);
    for(int i=posb[sz-1]+1; i<b.size(); i++) s.pb(b[i]);
    assert(s.size()<=a.size()/2*3);
    return s;
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        string s[3]; rep(i, 3) cin>>s[i];
        int cnt[3][2];
        rep(i, 3) rep(j, 2) cnt[i][j]=count(all(s[i]), j+'0');
        vi lg[2];
        rep(i, 3) lg[cnt[i][1]>cnt[i][0]].pb(i);
        if(lg[0].size()>=2) {
            int fi=lg[0][0], se=lg[0][1];
            cout<<bld(s[fi], s[se], '0')<<endl;
        }
        else {
            int fi=lg[1][0], se=lg[1][1];
            cout<<bld(s[fi], s[se], '1')<<endl;
        }
    }
}