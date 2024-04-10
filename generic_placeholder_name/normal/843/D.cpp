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

constexpr int N=1e5+5;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;
ll h[N], g[N];
int w[N];
bitset<N> in;
bitset<N> reachable;
vector<pii> adj[N];
int n, m;


constexpr int rt=0;
constexpr int T=300;
int c;
deque<int> q;
void calc(int tg, bool init=0) { //trying some more spfa opts
    in.reset();
    if(init) {
        memset(g, 0x3f, sizeof(g));
        reachable.reset();
    }
    else {
        rep1(i, n-1) if(g[i]!=INF) h[i]=g[i], g[i]+=c;
        c=0;
    }
    g[rt]=0; q.push_front(rt);
    ll sum=0, cnt=0;
    while(!q.empty()) {
        int u=q.front(); q.pop_front();
        if(g[u]*cnt>sum) { //LLL opt
            q.push_back(u);
            continue;
        }
        if(init) reachable[u]=1;
        in[u]=0; sum-=g[u]; cnt--;
        for(auto& [v, i]: adj[u]) {
            if(g[v]>g[u]+w[i]) {
                if(!in[v]) {
                    in[v]=1;
                    if(!q.empty()&&g[v]<g[q.front()]) q.push_front(v); //SLF opt
                    else q.push_back(v);
                    sum+=g[u]+w[i];
                    cnt++;
                }
                else sum-=g[v]-(g[u]+w[i]);
                g[v]=g[u]+w[i];
            }
        }
    }
}

int32_t main() {
    fastio;
    int q; cin>>n>>m>>q;
    rep1(i, m) {
        int u, v, _w; cin>>u>>v>>_w; --u, --v;
        w[i]=_w;
        adj[u].eb(v, i);
    }
    rep(i, n) shuffle(all(adj[i]), rng);
    calc(-1, 1);
    while(q--) {
        int type; cin>>type;
        if(type==1) {
            int x; cin>>x; --x;
            if(c&&reachable[x]) calc(x);
            cout<<(g[x]==INF?-1LL:g[x])<<endl;
        }
        else {
            int sz; cin>>sz; c+=sz;
            rep(i, sz) {
                int x; cin>>x;
                w[x]++;
            }
        }
    }
}