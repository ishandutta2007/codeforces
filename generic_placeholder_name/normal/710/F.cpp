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

int32_t main() {
    //You have 2 choices
    //1. Elegant Aho-Corasick solution that uses good new ideas
    //2. Brute force hashing
    //Obviously 2 is better lmao
    constexpr int MOD=1e9+123;
    constexpr int p=31;
    int pw[300005];
    pw[0]=1; rep1(i, 300004) pw[i]=(1LL*pw[i-1]*p)%MOD;
    unordered_set<ll> occ[300005];
    unordered_map<int, int> len;
    int q; cin>>q; while(q--) {
        int t; string s; cin>>t>>s;
        int n=s.length(), h[n+1]={0};
        rep1(i, n) h[i]=(1LL*h[i-1]*p+s[i-1]-'a'+1)%MOD;
        if(t==1) occ[n].insert(h[n]), len[n]++;
        else if(t==2) {
            occ[n].erase(occ[n].find(h[n]));
            if(len[n]==1) len.erase(len.find(n));
            else len[n]--;
        }
        else {
            ll ans=0;
            for(auto& it: len) {
                int l=it.fi;
                for(int i=l; i<=n; i++) {
                    if(occ[l].find((MOD+h[i]-(1LL*h[i-l]*pw[l]%MOD))%MOD)!=occ[l].end()) ans++;
                }
            }
            printf("%d\n", ans);
            fflush(stdout);
        }
    }
}