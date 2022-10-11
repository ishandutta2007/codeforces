#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pi;
typedef pair<ll,ll> pl; 
typedef pair<ld,ld> pd; 

typedef vector<int> vi; 
typedef vector<ll> vl;
typedef vector<ld> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define mp make_pair
#define pb push_back
#define f first
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 998244353;
const ll INF = 1e18;
const int MX = 100005;

int N;
vi tree[MX];
ld treeSize[MX];
ld ans[MX];

void dfs1(int v) {
    treeSize[v] = 1;
    for(int u : tree[v]) {
        dfs1(u);
        treeSize[v] += treeSize[u];
    }
}

void dfs2(int v, ld S, ld T, ld R) {
    ld s, t;
    s = t = 0;
    for(int u : tree[v]) {
        s += treeSize[u];
        t++;
    }

    ans[v] = R;
    if (T > 1e-10) ans[v] += S / 2;
    ans[v]++;
    trav(u, tree[v]) {
        dfs2(u, s - treeSize[u], t - 1, ans[v]);
    }
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
    cin >> N;
    F0R(i, N - 1) {
        int x; cin >> x; x--;
        tree[x].pb(i + 1);
    }

    dfs1(0);
    dfs2(0, 0, 0, 0);

    F0R(i, N) cout << ans[i] << " ";
    return 0;
    // You should actually read the stuff at the bottom
}

/* Stuff to Look For
 * -----------------
 * Int overflow, array bounds
 * Initializing all variables, avoid weird behavior
 * Edge cases(n = 0, n = 1)
 * Just return 0 after result
 */