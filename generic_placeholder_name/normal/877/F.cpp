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

//standard stuff
//just what is that flow tag about though
//would be interesting to find out

constexpr int N=1e5+1;
constexpr int BLOCKSIZE=300;
struct query {
    int l, r, idx;
    query() {}
    query(int l, int r, int idx): l(l), r(r), idx(idx) {}
    bool operator < (const query& oth) const {
        if(l/BLOCKSIZE!=oth.l/BLOCKSIZE) return l<oth.l;
		return l/BLOCKSIZE&1?r<oth.r:r>oth.r;
    }
};

ll a[N], t[N], pf[N], res[N];
gp_hash_table<ll, int> cnt;
ll k, ans;

void addr(int i) {
    ans+=cnt[pf[i]-k];
    cnt[pf[i]]++;
}

void addl(int i) {
    ans+=cnt[pf[i]+k];
    cnt[pf[i]]++;
}

void subr(int i) {
    cnt[pf[i]]--;
    ans-=cnt[pf[i]-k];
}

void subl(int i) {
    cnt[pf[i]]--;
    ans-=cnt[pf[i]+k];
}

int32_t main() {
    fastio;
    int n; cin>>n>>k;
    rep1(i, n) cin>>t[i], t[i]=t[i]==1?1:-1;
    rep1(i, n) cin>>a[i];
    rep1(i, n) pf[i]=pf[i-1]+t[i]*a[i];
    int m; cin>>m;
    query q[m];
    rep(i, m) {
        int l, r; cin>>l>>r;
        q[i]=query(l-1, r, i);
    }
    sort(q, q+m);
    int l=0, r=-1;
    rep(i, m) {
        while(r<q[i].r) addr(++r);
		while(r>q[i].r) subr(r--);
		while(l>q[i].l) addl(--l);
		while(l<q[i].l) subl(l++);
		res[q[i].idx]=ans;
    }
    rep(i, m) cout<<res[i]<<endl;
}