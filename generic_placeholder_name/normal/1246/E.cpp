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

int a[16], b[16];
pii c[16];

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    auto f = [&k](int x) {while(x%k==0) x/=k; return x;};
    auto get_rnd = [](int l, int r) {
        uniform_int_distribution<int> engine(l, r);
        return engine(rng);
    };
    rep(i, n) cin>>a[i];
    auto start = chrono::steady_clock::now();
    auto cur=chrono::steady_clock::now();
    while(chrono::duration_cast<chrono::milliseconds>(cur - start).count()<1969) {
        memcpy(b, a, n*sizeof(int));
        shuffle(b, b+n, rng);
        for(int sz=n; sz>1; sz--) {
            int x=b[sz-1], y=b[sz-2];
            c[n-sz]={x, y};
            b[sz-2]=f(x+y);
            if(sz>2) swap(b[sz-2], b[get_rnd(0, sz-3)]);
        }
        if(b[0]==1) {
            cout<<"YES\n";
            rep(i, n-1) cout<<c[i].fi<<' '<<c[i].se<<endl;
            return 0;
        }
        cur=chrono::steady_clock::now();
    }
    puts("NO");
}