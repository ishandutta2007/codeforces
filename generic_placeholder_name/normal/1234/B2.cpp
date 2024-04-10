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
    fastio;
    //hey i remember this one
    //this was when I didn't know std::set was a thing
    //and wasn't the #pragma junkie that I am today
    //a blast from the past
    //lmao
    set<int> id;
    int n, k; cin>>n>>k; int a[n]; for(int i=0; i<n; i++) cin>>a[i]; vector<int> curr;
    for(int i=0; i<n; i++) {
        if (id.find(a[i])==id.end()) {
            if (curr.size()<k) {
                curr.push_back(a[i]); id.insert(a[i]);
            }
            else {
                id.erase(curr[0]); curr.erase(curr.begin());
                curr.push_back(a[i]); id.insert(a[i]);
            }
        }
    }
    cout<<curr.size()<<endl;
    for(int i=curr.size()-1; i>=0; i--) cout<<curr[i]<<" "; cout<<endl;
}