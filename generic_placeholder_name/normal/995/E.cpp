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

unordered_map<int, vi> s, t;
int x, y, p;

int exp(int a, int b) {
    if(!b) return 1;
    else {
        int x=exp(a, b/2);
        x=1LL*x*x%p;
        if(b&1) return 1LL*x*a%p;
        else return x;
    }
}

void bfs(unordered_map<int, vi>& m, int src, int TIME_LIMIT, int MEMORY_LIMIT) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    queue<int> Q; Q.push(src);
    m[src]=vi();
    while(!Q.empty()) {
        if(m.size() >= MEMORY_LIMIT) return;
        std::chrono::steady_clock::time_point cur = std::chrono::steady_clock::now();
        if (std::chrono::duration_cast<std::chrono::milliseconds>(cur - start).count() >= TIME_LIMIT) return;
        int u=Q.front(); Q.pop();
        if(m[u].size()<100){
            vi ins; //randomly insert
            int v[]={(u+1)%p, (u+p-1)%p, exp(u, p-2)};
            rep(i, 3) {
                if(m.find(v[i])==m.end()) {
                    m[v[i]]=m[u]; m[v[i]].pb(i+1);
                    ins.pb(v[i]);
                }
            }
            shuffle(all(ins), rng);
            for(int it: ins) Q.push(it);
        }
    }
}

int32_t main() {
    fastio;
    cin>>x>>y>>p;
    bfs(s, x, 2000, 5e5); //avg size somewhere around 20
    bfs(t, y, 2500, 6e5);
    ll total_size = 0, tot=0; for(auto& it: s) total_size+=it.se.size(), tot++;
    auto rev = [](int x) -> int {
        return x==1 ? 2 :
                x==2 ? 1 : 3;
    };
    for(auto& it: s) if(t.find(it.fi)!=t.end()) {
        cout<<it.se.size()+t[it.fi].size()<<endl;
        for(auto& x: it.se) cout<<x<<' ';
        reverse(all(t[it.fi])); for(auto& x: t[it.fi]) cout<<rev(x)<<' ';
        return cout<<endl, 0;
    }
    assert(0);
}