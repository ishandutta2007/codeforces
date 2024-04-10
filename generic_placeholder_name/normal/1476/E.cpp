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

__attribute__((always_inline)) int conv(char c) {
    return c=='_'?26:c-'a';
}

vi get_hashes(const string& s) {
    int bs=1;
    vi ans={0};
    for(char c: s) {
        vi nxt;
        int v=conv(c);
        for(int x: ans) {
            if(v!=26) nxt.pb(x+v*bs);
            nxt.pb(x+26*bs);
        } 
        ans.swap(nxt);
        bs*=27;
    }
    return ans;
}

int get_hash(const string& s) {
    int bs=1, ans=0;
    for(char c: s) {
        int v=conv(c);
        ans+=v*bs;
        bs*=27;
    }
    return ans;
}

vi pos[531441];

optional<vi> toposort(const vvi& adj) { //returns nothing if not toposortable
    int n=adj.size();
    stack<int> st;
    vb vis(n, 0);
    auto dfs = [&](int u, const auto& self) -> void {
        vis[u]=1;
        for(int v: adj[u]) if(!vis[v]) self(v, self);
        st.push(u);
    };
    rep(i, n) if(!vis[i]) dfs(i, dfs);
    vi ans;
    while(!st.empty()) ans.pb(st.top()), st.pop();
    vi pos(n);
    rep(i, n) pos[ans[i]]=i;
    rep(i, n) {
        for(int j: adj[i]) {
            if(pos[j]<pos[i]) return {};
        }
    } 
    return ans;
}

int32_t main() {
    fastio;
    int n, m, _; cin>>n>>m>>_;
    vector<string> pat(n), str(m);
    vi hsh(n);
    vi mat(m);
    rep(i, n) cin>>pat[i], hsh[i]=get_hash(pat[i]);
    rep(i, m) {
        cin>>str[i]>>mat[i]; --mat[i];
        auto v=get_hashes(str[i]);
        if(find(all(v), hsh[mat[i]])==v.end()) return puts("NO"), 0;
        for(int x: v) pos[x].pb(i);
    }
    vvi adj(n);
    rep(i, n) {
        for(int p: pos[hsh[i]]) {
            if(mat[p]!=i) adj[mat[p]].pb(i);
        }
    }
    auto ans=toposort(adj);
    if(!ans.has_value()) return puts("NO"), 0;
    else {
        cout<<"YES\n";
        for(auto& v: *ans) cout<<v+1<<' '; cout<<endl;
    }
}