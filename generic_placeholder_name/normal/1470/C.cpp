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

int ask(int i) {
    static int q=0;
    q++; assert(q<=1000);
    cout<<"? "<<i+1<<endl;
    int ans; cin>>ans;
    return ans;
}

void answer(int i) {
    cout<<"! "<<i+1<<endl;
    exit(0);
}

int n;
int add(int a, int b) {return (a+=b)>=n?a-n:a;}
int sub(int a, int b) {return (a-=b)<0?a+n:a;}
int mul(int a, int b) {return (a*1ll*b)%n;}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int k; cin>>n>>k;
    for(int i=0, pos=rng()%n; ; i=add(i, 1), pos=add(pos, i)) {
        int ans=ask(pos);
        if(ans<k) {
            int p=pos;
            do {
                p=add(p, 1);
                ans=ask(p);
            } while(ans!=k);
            answer(p);
        }
        else if(ans>k) {
            int p=pos;
            do {
                p=sub(p, 1);
                ans=ask(p);
            } while(ans!=k);
            answer(p);
        }
    }
}