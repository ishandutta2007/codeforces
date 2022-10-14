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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int M=1e6+5;
int f[M];

int32_t main() {
    fastio;
    for(int i=2; i*i<M; i++) if(!f[i]) {
        for(int j=i*i; j<M; j+=i) if(!f[j]) f[j]=i;
    }
    for(int i=2; i<M; i++) if(!f[i]) f[i]=i;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        cc_hash_table<int, int> cnt;
        rep(i, n) {
            int x; cin>>x;
            stack<int> st;
            while(x>1) {
                if(st.empty()||st.top()!=f[x]) st.push(f[x]);
                else st.pop();
                x/=f[x];
            }
            int norm=1;
            while(!st.empty()) norm*=st.top(), st.pop();
            cnt[norm]++;
        }
        int mx=0, even=0, odd=0;
        for(auto& [p, v]: cnt) {
            mx=max(mx, v);
            if(p==1||!(v&1)) even+=v;
            else odd=max(odd, v);
        }
        int q; cin>>q;
        while(q--) {
            ll w; cin>>w;
            if(!w) cout<<mx<<endl;
            else cout<<max(even, odd)<<endl;
        }
    }
}