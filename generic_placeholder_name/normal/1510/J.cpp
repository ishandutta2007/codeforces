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

int32_t main() {
    fastio;
    string s; cin>>s;
    int n=s.size(); 
    vb t(n);
    rep(i, n) t[i]=(s[i]=='#');
    if(all_of(all(t), [](bool x) {return !x;})) return puts("0"), 0;
    auto eval = [&n](vb t, int d) -> optional<vb> {
        if(d>=n) return {};
        for(int i=n-1; i>=n-d; i--) if(t[i]) return {};
        int lst=-2;
        rep(i, n) if(t[i]) {
            if(lst+1==i) {
                lst=i;
                continue;
            }
            for(int j=i-1; j>=i-d; j--) {
                if(j<0||t[j]) return {};
                t[j]=1;
            }
            int s=lst+2, e=i-d; //bounds [s, e)
            if(s<e&&!d) return {};
            for(; e-s>4; s+=2) t[s]=1;
            if(e-s==4) t[s]=t[s+2]=1;
            else if(e-s==3) {
                if(d<2) return {};
                else t[s]=t[s+1]=1;
            }
            else if(e-s==2) t[s]=1;
            else if(e-s==1) return {};
            lst=i;
        }
        int s=lst+2, e=n-d+1; //bounds [s, e)
        if(s<e&&!d) return {};
        for(; e-s>4; s+=2) t[s]=1;
        if(e-s==4) t[s]=t[s+2]=1;
        else if(e-s==3) {
            if(d<2) return {};
            else t[s]=t[s+1]=1;
        }
        else if(e-s==2) t[s]=1;
        else if(e-s==1) return {};
        return t;
    };
    rep(d, 4) {
        auto res=eval(t, d);
        if(!res.has_value()) continue;
        vi ans; int run=0;
        rep(i, n) {
            if((*res)[i]) run++;
            else {
                if(run) ans.pb(run);
                run=0;
            }
        }
        if(run) ans.pb(run);
        cout<<ans.size()<<endl;
        for(int v: ans) cout<<v<<' '; cout<<endl;
        return 0;
    }
    puts("-1");
}