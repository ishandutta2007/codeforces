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

//first thoughts: "hey that's not so hard for a 3400"
//but then I thought that about Tokitsukaze and Powers too
//and that took 12 hours total

using pil=pair<int, ll>;
vector<pil> generate_gcd(vector<pil>& a) {
    gp_hash_table<int, ll> m;
    vector<gp_hash_table<int, ll>> cur(a.size());
    rep(i, a.size()) {
        cur[i][a[i].fi]=a[i].se*1LL*(a[i].se+1)/2;
        if(i) for(const auto& it: cur[i-1]) {
            cur[i][gcd(a[i].fi, it.fi)]+=it.se*a[i].se;
        }
        for(auto& it: cur[i]) m[it.fi]+=it.se;
    }
    vector<pil> ans;
    for(const auto& it: m) ans.pb(it);
    sort(all(ans));
    return ans;
}

//the gcd part is not hard if you realize that there is only O(n * d(a[i])) values in total
//now the sums
//is much harder

//Euclidean algorithm
// Counts x, y >= 0 such that Ax + By <= C.
ll cnt(ll A, ll B, ll C) {
    if (C<0) return 0;
    if (A>B) swap(A, B);
    ll p=C/B, k=B/A, d=(C-p*B)/A;
    return cnt(B-k*A, A, C-A*(k*p+d+1))+(p+1)*(d+1)+k*p*(p+1)/2;
}

// Counts 0 <= x < RA, 0 <= y < RB such that Ax + By <= C.
ll count_under(ll A, ll B, ll C, ll RA, ll RB) {
    if (C<0) return 0;
    if (C>=A*RA+B*RB) return RA*RB;
    if (RA<=0|| RB<=0) return 0;
    return cnt(A, B, C)-cnt(A, B, C-A*RA)-cnt(A, B, C-B*RB);
}

constexpr int M=100001;
ll test_under(vll& a, ll m) {
    int j=1; ll sum=0, cnt=0, ans=0;
    rep1(i, M-1){
        ll x=min(a[i], m/i), y=a[i]-x;
        ans+=a[i]*(a[i]+1)/2-y*(y+1)/2;
        sum-=i*a[i];
        cnt-=a[i];
        if(i<j) ans+=a[i]*cnt;
        while(j<M) {
            if (i<j) ans+=count_under(i, j, m-sum-i-j, a[i], a[j]);
            if (sum+j*a[j]<=m) {
                sum+=j*a[j];
                cnt+=a[j];
                j++;
            }
            else break;
        }
    }
    return ans;
}

ll get_median(vector<pil> a) {
    ll sz=0; for(auto& it: a) sz+=it.se;
    sz=(sz*(sz+1)/2-1)/2;
    //flatten the array for easier work
    vll flat(M+1, 0); for(auto& it: a) flat[it.fi]+=it.se;
    ll l=1, r=0;
    rep(i, a.size()) r+=a[i].fi*a[i].se;
    while(l<r) {
        ll m=(l+r)/2;
        if(test_under(flat, m)>sz) r=m;
        else l=m+1;
    }
    return l;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    vector<pil> a(n, {0, 1}); rep(i, n) cin>>a[i].fi;
    cout<<get_median(generate_gcd(a));
}