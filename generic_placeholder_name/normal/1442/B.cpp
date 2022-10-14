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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int MOD=998244353;

int32_t main() {
    fastio;
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k;
        int p[n+1], a[k];
        rep1(i, n) {int x; cin>>x; p[x]=i;}
        rep(i, k) {
            cin>>a[i];
            a[i]=p[a[i]];
        }
        auto solve = [&]() -> int {
            rep(i, k) if(!a[i]) return 0;
            set<int> s{0, n+1};
            ordered_set<int> rm;
            rep(i, k) s.insert(a[i]);
            int ans=1;
            rep(i, k) {
                int free=0;
                auto itr=s.find(a[i]);
                int ls=rm.order_of_key(a[i])-rm.order_of_key(*prev(itr));
                int rs=rm.order_of_key(*next(itr))-rm.order_of_key(a[i]);
                if(s.find(a[i]-ls-1)==s.end()) free++;
                if(s.find(a[i]+rs+1)==s.end()) free++;
                if(!free) return 0;
                else if(free==2) {ans*=2; if(ans>=MOD) ans-=MOD;}
                s.erase(a[i]);
                rm.insert(a[i]);
            }
            return ans;
        };
        cout<<solve()<<endl;
    }
}