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

constexpr int N=8;
array<ll, N> a, t;
ll w;

int32_t main() {
    fastio;
    auto start = chrono::steady_clock::now();
    cin>>w; if(!w) return cout<<"0\n", 0;
    rep(i, N) cin>>a[i];
    ll s=0; rep(i, N) s+=a[i]*(i+1);
    if(s<=w) return cout<<s<<endl, 0;
    s=0;
    rep(i, N) {
        if(s+a[i]*(i+1)<=w) {
            s+=a[i]*(i+1);
            t[i]=a[i];
            a[i]=0;
        }
        else {
            ll x=(w-s)/(i+1);
            a[i]-=x;
            s+=x*(i+1);
            t[i]=x;
        }
    }
    ll ans=s;
    auto end=chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(end - start).count()<1969) {
        if(s<w) {
            int idx=rng()%N;
            while(!a[idx]) idx=rng()%N;
            a[idx]--; t[idx]++;
            s+=idx+1;
        }
        else {
            int idx=rng()%N;
            while(!t[idx]) idx=rng()%N;
            t[idx]--; a[idx]++;
            s-=idx+1;
        }
        if(s<=w) ans=max(ans, s);
        end=chrono::steady_clock::now();
    }
    cout<<ans<<endl;
}