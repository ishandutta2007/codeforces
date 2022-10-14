#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=305;
char c[N][N];
bool vis[N][N];
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
int n;

bool in(int x, int y) {
    return 0<x&&x<=n&&0<y&&y<=n&&c[x][y]!='.';
}

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        cin>>n;
        rep1(i, n) rep1(j, n) cin>>c[i][j];
        rep1(i, n) rep1(j, n) vis[i][j]=0;
        rep1(i, n) rep1(j, n) {
            if(!vis[i][j]&&in(i, j)) {
                queue<pii> q;
                vector<pii> x[3], o[3];
                q.emplace(i, j);
                vis[i][j]=1;
                while(!q.empty()) {
                    pii p=q.front(); q.pop();
                    if(c[p.fi][p.se]=='X') x[(p.fi+p.se)%3].pb(p);
                    else o[(p.fi+p.se)%3].pb(p);
                    rep(i, 4) if(in(p.fi+dx[i], p.se+dy[i])&&!vis[p.fi+dx[i]][p.se+dy[i]]) {
                        q.emplace(p.fi+dx[i], p.se+dy[i]);
                        vis[p.fi+dx[i]][p.se+dy[i]]=1;
                    }
                }
                int xid=0, oid=1;
                int mxs=x[0].size()+o[1].size()+x[2].size()+o[2].size();
                rep(i, 3) rep(j, 3) if(i!=j) {
                    if(mxs<x[i].size()+o[j].size()+x[3-i-j].size()+o[3-i-j].size()) {
                        mxs=x[i].size()+o[j].size()+x[3-i-j].size()+o[3-i-j].size();
                        xid=i;
                        oid=j;
                    }
                }
                for(pii& p: o[xid]) c[p.fi][p.se]='X';
                for(pii& p: x[oid]) c[p.fi][p.se]='O';
            }
        }
        rep1(i, n) rep1(j, n) {cout<<c[i][j]; if(j==n) cout<<endl;}
    }
}