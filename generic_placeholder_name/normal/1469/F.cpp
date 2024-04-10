#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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

constexpr int N=0x3f3f3f3f; //i'm lazy and this is just fine
struct Node {
private:
    ll sum, lz;
    typedef unique_ptr<Node> NodePtr;
    NodePtr lc, rc;
    int L, R;

    void apply(ll val) {
        sum+=val*(R-L+1);
        lz+=val;
    }

public:
    Node(): sum(0), lz(0), lc(nullptr), rc(nullptr), L(0), R(N) {}
    Node(int L, int R): sum(0), lz(0), lc(nullptr), rc(nullptr), L(L), R(R) {}

    void push() {
        int M=(L+R)/2;
        if(!lc) lc=make_unique<Node>(L, M);
        if(!rc) rc=make_unique<Node>(M+1, R);
        if(lz) {
            lc->apply(lz);
            rc->apply(lz);
            lz=0;
        }
    }

    void upd(int ql, int qr, int val) {
        if(ql>R||qr<L) return;
        if(ql<=L&&qr>=R) apply(val);
        else {
            push();
            lc->upd(ql, qr, val);
            rc->upd(ql, qr, val);
            sum=lc->sum+rc->sum;
        }
    }

    ll get(int ql, int qr) {
        if(ql>R||qr<L) return 0;
        if(ql<=L&&qr>=R) return sum;
        else {
            push();
            return lc->get(ql, qr)+rc->get(ql, qr);
        }
    }

    int bs(int val) {
        if(L==R) return L;
        else {
            push();
            if(lc->sum>=val) return lc->bs(val);
            else return rc->bs(val-lc->sum);
        }
    }
};
typedef unique_ptr<Node> NodePtr;

int32_t main() {
    fastio;
    int n, k; cin>>n>>k;
    vi a(n); rep(i, n) cin>>a[i];
    sort(all(a), greater<int>());
    NodePtr t=make_unique<Node>();
    t->upd(0, 0, 1);
    int ans=INT_MAX;
    rep(i, n) {
        int p=t->bs(1);
        int& len=a[i];
        t->upd(p, p, -1);
        t->upd(p+2, p+(len+1)/2, 1);
        t->upd(p+2, p+(len/2+1), 1);
        if(t->get(0, N)>=k) ans=min(ans, t->bs(k));
    }
    if(ans!=INT_MAX) cout<<ans<<endl;
    else puts("-1");
}