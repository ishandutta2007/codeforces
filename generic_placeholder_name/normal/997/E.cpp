#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
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

//so I was seeing if an O(n^2) optimized solution would get an AC, which it did
//but the thing is that solution uses a large amount of __mmi vomit
//so I am trying to do this without vomiting a whole lot of asm and/or mmi

constexpr int sz=8192;
//unroll const
//gcc is a good compiler but -funroll-all-loops suck
//if you want your loops unrolled you should do it this way
//the internal loops are const and thus unroll-able

constexpr int N=1.2e5+5;
int a[N], mx[N], mn[N], res[N];
ll ans[N];
vector<pii> query[N];
ll buf[sz];

int32_t main() {
	fastio;
	int n; cin>>n;
	rep(i, n) mx[i]=0, mn[i]=INT_MAX;
	rep(i, n) cin>>a[i];
	int q; cin>>q;
	rep(i, q) {
        int l, r; cin>>l>>r;
        query[--r].eb(--l, i);
	}
	rep(r, n) {
	    const int t=a[r];
	    int c=0;
        while(c+sz<=r) {
            #pragma GCC ivdep
            for(int i=c; i<c+sz; i++) { //gcc unrolls this
                mx[i]=mx[i]<t?t:mx[i];
                mn[i]=mn[i]>t?t:mn[i];
                res[i]+=mx[i]-mn[i]==r-i;
            }
            c+=sz;
        }
        for(int i=c; i<=r; i++) {
            mx[i]=mx[i]<t?t:mx[i];
            mn[i]=mn[i]>t?t:mn[i];
            res[i]+=mx[i]-mn[i]==r-i;
        }
        for(const pii& q: query[r]) {
            #define l q.fi
            #define idx q.se
            memset(buf, 0, sizeof(buf));
            int c=l;
            while(c+sz<=r) {
                #pragma GCC ivdep
                for(int i=c; i<c+sz; i++) {
                    buf[i-c]+=res[i];
                }
                c+=sz;
            }
            for(int i=c; i<=r; i++) {
                ans[idx]+=res[i];
            }
            rep(i, sz) ans[idx]+=buf[i];
            #undef l
            #undef idx
        }
	}
	rep(i, q) cout<<ans[i]<<endl;
}