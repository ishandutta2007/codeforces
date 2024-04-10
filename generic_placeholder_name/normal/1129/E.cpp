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

constexpr int N=505;
int sz[N];
bool t[N];

int n;
vector<pii> edges;

int queries=0;
constexpr int LIM=11111;
int ask(const vi& s, const vi& t, int v) {
    queries++;
    //if(queries>LIM) while(1){}
    cout<<s.size()<<endl;
    for(int x: s) cout<<x<<' '; cout<<endl;
    cout<<t.size()<<endl;
    for(int x: t) cout<<x<<' '; cout<<endl;
    cout<<v<<endl;
    int ans; cin>>ans; return ans;
}

void answer() {
    cout<<"ANSWER\n";
    for(auto& [u, v]: edges) cout<<u<<' '<<v<<endl;
}

void solve() {
    if(n==2) return void(edges.eb(1, 2));
    vi a(n); iota(all(a), 1);
    int rt=a.back();
    a.pop_back();
    for(auto& v: a) sz[v]=ask(vi{rt}, a, v);
    sort(all(a), [](int x, int y) {return sz[x]<sz[y];});
    sz[rt]=n; a.pb(rt);
    vi lf{a[0]};
    rep1(i, n-1) {
        int k=ask(vi{rt}, lf, a[i]);
        for(auto& v: lf) t[v]=0;
        auto solve_comp = [&](vi& cand, int k) {
            auto divide = [&](vi& cand, int k, const auto& self) {
                shuffle(all(cand), rng);
                if(cand.size()<=3) {
                    for(int x: cand) t[x]=ask(vi{rt}, vi{x}, a[i]);
                    return;
                }
                if(k==cand.size()) {
                    for(int x: cand) t[x]=1;
                    return;
                }
                vi grps[2];
                rep(i, cand.size()) grps[i&1].pb(cand[i]);
                for(auto& grp: grps) {
                    int in_grp=ask(vi{rt}, grp, a[i]);
                    if(!in_grp) continue;
                    else self(grp, in_grp, self);
                }
            };
            divide(cand, k, divide);
        };
        solve_comp(lf, k);
        vi nxt;
        for(int v: lf) {
            if(t[v]) edges.eb(v, a[i]);
            else nxt.pb(v);
        }
        nxt.pb(a[i]);
        lf.swap(nxt);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin>>n;
    solve();
    answer();
}