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
    int T; cin>>T; while(T--) {
        auto solve = []() -> void {
            int n, l, r, s; cin>>n>>l>>r>>s; --l, --r;
            if(s>n*(n+1)/2-(n-(r-l+1))*(n-(r-l+1)+1)/2) return void(cout<<"-1\n");
            if(s<(r-l+1)*(r-l+2)/2) return void(cout<<"-1\n");
            vb vis(n+1);
            vi a(n);
            for(int i=l; i<=r; i++) a[i]=i-l+1, vis[i-l+1]=1, s-=i-l+1;
            for(int i=l; i<=r; i++) {
                for(int j=n; j>i-l+1; j--) if(!vis[j]&&s>=j-a[i]) {
                    vis[i-l+1]=0; vis[j]=1;
                    s-=j-a[i]; a[i]=j;
                    break;
                }
            }
            rep(i, n) if(i<l||i>r) {
                rep1(k, n) if(!vis[k]) {
                    vis[k]=1; a[i]=k;
                    break;
                }
            }
            rep(i, n) cout<<a[i]<<' '; cout<<endl;
        };
        solve();
    }
}