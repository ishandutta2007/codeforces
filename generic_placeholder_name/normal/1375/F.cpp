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

int32_t main() {
    vll a(3); cin>>a[0]>>a[1]>>a[2];
    cout<<"First\n";
    //make query 1
    vll q1=a; sort(all(q1));
    ll ask1=abs(2*q1[2]-q1[1]-q1[0]);
    cout<<ask1<<endl;
    int resp1; cin>>resp1; if(resp1==0) return 0; a[--resp1]+=ask1;
    //make query 2
    vll q2=a; sort(all(q2));
    ll ask2=abs(2*q2[2]-q2[1]-q2[0]);
    cout<<ask2<<endl;
    int resp2; cin>>resp2; if(resp2==0) return 0; a[--resp2]+=ask2;
    //make query 3
    vll q3=a; sort(all(q3));
    cout<<q3[1]-q3[0]<<endl;
    //win or get fucked
    int resp; cin>>resp; assert(resp==0);
    return 0;
}