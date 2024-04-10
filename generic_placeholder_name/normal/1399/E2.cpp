#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

struct edge {
    int v, w, c; //u is implicit
    edge() {}
    edge(int v, int w, int c): v(v), w(w), c(c) {}
};

vector<vector<edge>> adj;
vi s, w, c; //s = number of vertices in subtree; w = weight, c = cost to remove
int n; ll t;

void dfs(int u, int par=-1, int W=-1, int C=-1) {
    w[u]=W; s[u]=adj[u].size()==1; c[u]=C;
    for(auto& to: adj[u]) if(to.v!=par) {
        dfs(to.v, u, to.w, to.c);
        s[u]+=s[to.v];
    }
}

ll f(int w, int c) {
    return 1LL*(w-w/2)*c;
}

int32_t main() {
    fastio;
    //god fuck me
    //i thought the requirement was true for each
    //but no
    //i was just dumb and making the problem 100x harder
    //go me
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        //cleanup
        adj.assign(n, vector<edge>());
        s.assign(n, 0);
        w.assign(n, 0);
        c.assign(n, 0);
        //actually do sth
        ll t; cin>>t;
        rep(i, n-1) {
            int u, v, w, c;
            cin>>u>>v>>w>>c;
            adj[--u].eb(--v, w, c);
            adj[v].eb(u, w, c);
        }
        dfs(0);
        priority_queue<pair<ll, int>> pq[2];
        ll sum=0; int ans=0;
        rep1(i, n-1) pq[c[i]-1].emplace(f(w[i], s[i]), i), sum+=1LL*w[i]*s[i];
        while(sum>t) {
            if(!pq[0].empty()&&sum-pq[0].top().fi<=t) {ans++; break;}
            else if(!pq[1].empty()&&sum-pq[1].top().fi<=t) {ans+=2; break;}
            else if(pq[1].empty()) {
                ans++;
                auto x=pq[0].top(); pq[0].pop();
                ll red=x.fi, i=x.se;
                sum-=red;
                w[i]/=2;
                pq[0].emplace(f(w[i], s[i]), i);
            }
            else if(pq[0].empty()) {
                ans+=2;
                auto x=pq[1].top(); pq[1].pop();
                ll red=x.fi, i=x.se;
                sum-=red;
                w[i]/=2;
                pq[1].emplace(f(w[i], s[i]), i);
            }
            else {
                ll red[2];
                red[1]=pq[1].top().fi;
                //goddammit getting reduction for 1 is a fucking nightmare
                red[0]=pq[0].top().fi;
                auto pre=pq[0].top(); pq[0].pop();
                red[0]+=max(f(w[pre.se]/2, s[pre.se]), pq[0].empty()?-1:pq[0].top().fi);
                pq[0].push(pre);
                if(red[1]>red[0]) {\
                    ans+=2;
                    auto x=pq[1].top(); pq[1].pop();
                    ll red=x.fi, i=x.se;
                    sum-=red;
                    w[i]/=2;
                    pq[1].emplace(f(w[i], s[i]), i);
                }
                else {
                    ans++;
                    auto x=pq[0].top(); pq[0].pop();
                    ll red=x.fi, i=x.se;
                    sum-=red;
                    w[i]/=2;
                    pq[0].emplace(f(w[i], s[i]), i);
                }
            }
        }
        cout<<ans<<endl;
    }
}