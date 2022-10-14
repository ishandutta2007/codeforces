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

//https://codeforces.com/contest/1473/problem/F
//basically same problem

namespace PushRelabel {
    template<typename T>
    struct Edge {
        int u, v, idx;
        T cap, flow;
        Edge(int u, int v, T cap, T flow, int idx): u(u), v(v), cap(cap), flow(flow), idx(idx) {}
    };
    template<typename T>
    struct PushRelabel {
        int n;
        vector<vector<Edge<T>>> adj;
        vector<T> excess;
        vi dist, cnt;
        vb active;
        vvi B;
        int b;
        queue<int> Q;
        PushRelabel(int n): n(n), adj(n) {}

        void add_edge(int u, int v, T cap) {
            adj[u].pb(Edge<T>(u, v, cap, 0, adj[v].size()));
            if(u==v) adj[u].back().idx++;
            adj[v].pb(Edge<T>(v, u, 0, 0, adj[u].size()-1));
        }

        void enqueue(int v) {
            if(!active[v]&&excess[v]>0&&dist[v]<n) {
                active[v]=1;
                B[dist[v]].pb(v);
                b=max(b, dist[v]);
            }
        }

        void push(Edge<T>& e) {
            T amt=min(excess[e.u], e.cap-e.flow);
            if (dist[e.u]==dist[e.v]+1&&amt>(T)0) {
                e.flow+=amt;
                adj[e.v][e.idx].flow-=amt;
                excess[e.v]+=amt;
                excess[e.u]-=amt;
                enqueue(e.v);
            }
        }

        void gap(int k) {
            rep(i, n) if(dist[i]>=k) {
                cnt[dist[i]]--;
                dist[i]=max(dist[i], n);
                cnt[dist[i]]++;
                enqueue(i);
            }
        }

        void relabel(int v) {
            cnt[dist[v]]--;
            dist[v]=n;
            for(auto e: adj[v]) if (e.cap-e.flow>0) {
                dist[v]=min(dist[v], dist[e.v]+1);
            }
            cnt[dist[v]]++;
            enqueue(v);
        }

        void discharge(int v) {
            for(auto& e: adj[v]) {
                if(excess[v]>0) push(e);
                else break;
            }
            if(excess[v]>0) {
                if(cnt[dist[v]]==1) gap(dist[v]);
                else relabel(v);
            }
        }

        T flow(int s, int t) {
            dist.assign(n, 0);
            excess.assign(n, 0);
            cnt.assign(n+1, 0);
            active.assign(n, 0),
            B.resize(n);
            b=0;
            for(auto &e: adj[s]) excess[s]+=e.cap;
            cnt[0]=n;
            enqueue(s);
            active[t]=1;
            while(b>=0) {
                if(!B[b].empty()) {
                    int v=B[b].back();
                    B[b].pop_back();
                    active[v]=0;
                    discharge(v);
                }
                else b--;
            }
            return excess[t];
        }
    };
}

int32_t main() {
    fastio;
    int n, m; cin>>n>>m;
    vi a(n);
    ll ans=0;
    PushRelabel::PushRelabel<ll> F(n+m+2);
    int s=n+m, t=n+m+1;
    rep(i, n) cin>>a[i], F.add_edge(i, t, a[i]);
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; --u, --v;
        ans+=w;
        F.add_edge(s, n+i, w);
        F.add_edge(n+i, u, w);
        F.add_edge(n+i, v, w);
    }
    ans-=F.flow(s, t);
    cout<<ans<<endl;
}