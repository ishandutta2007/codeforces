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
    int n; cin>>n;
    vi a(n); rep(i, n) cin>>a[i];
    int mx_dec=0; vi dec_chains;
    int mx_inc=0; vi inc_chains;
    int cur_dec=0;
    rep(i, n+1) {
        if(i==n||(i>0&&a[i]>=a[i-1])) {
            if(mx_dec<cur_dec) {
                mx_dec=cur_dec;
                dec_chains=vi{i-1};
            }
            else if(mx_dec==cur_dec) dec_chains.pb(i-1);
            cur_dec=1;
        }
        else cur_dec++;
    }
    int cur_inc=0;
    rep(i, n+1) {
        if(i==n||(i>0&&a[i]<=a[i-1])) {
            if(mx_inc<cur_inc) {
                mx_inc=cur_inc;
                inc_chains=vi{i-1};
            }
            else if(mx_inc==cur_inc) inc_chains.pb(i-1);
            cur_inc=1;
        }
        else cur_inc++;
    }
    if(mx_dec!=mx_inc) puts("0");
    else if(max(inc_chains.size(), dec_chains.size())>1) puts("0");
    else if(inc_chains.back()+mx_inc-1!=dec_chains.back()) puts("0");
    else if(mx_inc%2==0) puts("0");
    else puts("1");
}