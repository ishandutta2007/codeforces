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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

//idk where to start
//this problem is so ugly it hurts my soul
//anyway this is O((q+n) * n^(2/3))
//enjoy

struct Query {
    int l, r, k;
    int idx; //index
    int t; //edit block

    Query() {}
    Query(int l, int r, int k, int idx, int t): l(l), r(r), k(k), idx(idx), t(t) {}

    static constexpr int T=2500;
    bool operator < (const Query& oth) const {
        if(t/T!=oth.t/T) return t/T<oth.t/T;
        else if(l/T!=oth.l/T) return (l/T<oth.l/T)^((t/T)&1);
        else return (l/T)&1?r>oth.r:r<oth.r;
    }
};

struct Change {
    int pos, prv, now;

    Change() {}
    Change(int pos, int prv, int now): pos(pos), prv(prv), now(now) {}
};

struct QueryHandler {
    int n;
    vector<int> a;
    vector<int> ans;
    vector<int> cnt;
    vector<int> f;
    vector<int> active;
    vector<bool> vis;
    vector<Query> queries;
    vector<Change> changes;

    int elements=0;
    int compress(int x) {
        static gp_hash_table<int, int> m;
        if(m.find(x)!=m.end()) return m[x];
        else return m[x]=elements++;
    }

    void input() {
        cin>>n;
        int q; cin>>q;
        a.resize(n);
        rep(i, n) cin>>a[i], a[i]=compress(a[i]);
        vi _cpy=a;
        rep(i, q) {
            int t; cin>>t;
            if(t==1) {
                int l, r, k; cin>>l>>r>>k;
                queries.eb(--l, --r, k, queries.size(), -1+(int)changes.size());
            }
            else {
                int p, x; cin>>p>>x;
                --p, x=compress(x);
                changes.eb(p, _cpy[p], x);
                _cpy[p]=x;
            }
        }
        ans.resize(queries.size());
        f.assign(n, 0);
        vis.assign(n, 0);
        cnt.assign(elements, 0);
    }

    void add(int x) {
        if(cnt[x]) f[cnt[x]]--;
        cnt[x]++;
        f[cnt[x]]++;
        active.pb(cnt[x]);
    }

    void sub(int x) {
        f[cnt[x]]--;
        cnt[x]--;
        if(cnt[x]) {
            f[cnt[x]]++;
            active.pb(cnt[x]);
        }
    }

    void addq(Change& q, int l, int r) {
        if(l<=q.pos&&q.pos<=r) sub(q.prv), add(q.now);
        a[q.pos]=q.now;
    }

    void subq(Change& q, int l, int r) {
        if(l<=q.pos&&q.pos<=r) sub(q.now), add(q.prv);
        a[q.pos]=q.prv;
    }

    int eval(int k) {
        vector<pii> op;
        for(int x: active) {
            if(f[x]&&!vis[x]) {
                op.eb(x, f[x]);
                vis[x]=1;
            }
        }
        active.clear();
        sort(all(op));
        int ans=INT_MAX, ptr=0, sum=0;
        for(auto& [v, c]: op) {
            vis[v]=0;
            active.pb(v);
            sum+=c;
            while(sum-op[ptr].se>=k) sum-=op[ptr++].se;
            if(sum>=k) ans=min(ans, v-op[ptr].fi);
        }
        return ans==INT_MAX?-1:ans;
    }

    void solve_queries() {
        sort(all(queries));
        int ql=0, qr=-1, qt=-1;
        for(auto& Q: queries) {
            while(qr<Q.r) add(a[++qr]);
            while(ql>Q.l) add(a[--ql]);
            while(qt<Q.t) addq(changes[++qt], ql, qr);
            while(ql<Q.l) sub(a[ql++]);
            while(qr>Q.r) sub(a[qr--]);
            while(qt>Q.t) subq(changes[qt--], ql, qr);
            ans[Q.idx]=eval(Q.k);
        }
    }

    void solve() {
        input();
        solve_queries();
        for(int v: ans) cout<<v<<endl;
    }
};

int32_t main() {
    fastio;
    QueryHandler q;
    q.solve();
}