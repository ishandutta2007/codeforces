#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 300001; 

set<pi> rang;

pi sub(pi cur) {
    auto it = rang.lb({cur.f, -1});
    if (it != rang.end() && it->s <= cur.s) return *it;
    return {-1, -1};
}

pi sup(pi cur) {
    auto it = rang.lb({cur.f, -1});
    if (it == rang.begin()) return {-1, -1};
    it--;
    if (it->s >= cur.s) return *it;
    return {-1, -1};
}

vector<vi> g1(MX), g2(MX);
int ans, ct;

int tin[MX], tout[MX];

void dfs1(int v, int p) {
    tin[v] = ct++;
    trav(a, g2[v]) {
        if (a != p) dfs1(a, v);
    }
    tout[v] = ct;
}

void dfs2(int v, int p) {
    pi er = sup({tin[v], tout[v]});
    //cout << tin[v] << " " << tout[v] << " " << er.f << nl;
    if (er.f != -1) {
        rang.erase(er);
    }
    pi add = {-1, -1};
    if (sub({tin[v], tout[v]}).f == -1) {
        rang.ins({tin[v], tout[v]});
        add = {tin[v], tout[v]};
    }
    ckmax(ans, sz(rang));
    trav(a, g1[v]) {
        if (a != p) dfs2(a, v);
    }

    if (er.f != -1) rang.ins(er);
    if (add.f != -1) rang.erase(add);
}

void solve() {
    rang.clear();
    ans = 0;
    ct = 0;
    int N; cin >> N;
    F0R(i, N) {
        g1[i].clear(); g2[i].clear();
    }

    FOR(i, 1, N) {
        int X; cin >> X; X--;
        g1[X].pb(i); g1[i].pb(X);
    }
    FOR(i, 1, N) {
        int X; cin >> X; X--;
        g2[X].pb(i); g2[i].pb(X);
    }

    dfs1(0, 0); dfs2(0, 0);
    cout << ans << nl;

}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}