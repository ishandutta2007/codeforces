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

struct state {
    ll left, rem, b;

    state() {}
    state(ll a, ll b): left(a/b), rem(a%b), b(b) {}

    void add(ll x) {
        left+=x/b;
        rem+=x%b;
        if(rem>=b) rem-=b, left++;
    }

    bool operator > (const state& oth) const {
        return mp(left, rem)>mp(oth.left, oth.rem);
    }
};

constexpr ll INF=1e13;
bool check(vector<pll>& a, int k, ll x) {
    priority_queue<state, vector<state>, greater<state>> pq;
    for(auto& it: a) pq.emplace(it.fi, it.se);
    rep(i, k-1) {
        state st=pq.top(); pq.pop();
        st.add(x);
        pq.push(st);
        if(pq.top().left<=i) return 0;
    }
    return 1;
}

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    vector<pll> a(n);
    rep(i, n) cin>>a[i].fi;
    rep(i, n) cin>>a[i].se;
    if(!check(a, k, INF)) return cout<<"-1\n", 0;
    ll l=0, r=INF;
    while(l<r) {
        ll m=(l+r)/2;
        if(check(a, k, m)) r=m;
        else l=m+1;
    }
    cout<<l<<endl;
}