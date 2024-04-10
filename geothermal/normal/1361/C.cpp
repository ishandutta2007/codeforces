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
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
 
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
const int MX = 500001; //check the limits, dummy

vpi A(MX);
vi res;
int N;
vi ans;

vpi eulerWalk(vector<vector<pi>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges); 
    vpi ret, s = {{src, -1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back().f, y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(s.back()); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

bool solve(int it, bool fin) {
    ans.clear();
    res.clear();
    int M = 1 << it;
    vector<vpi> graph(M);
    F0R(i, N) {
        int X = A[i].f % M, Y = A[i].s % M;
        graph[X].pb({Y, i});
        graph[Y].pb({X, i});
    }

    int sta = 0; F0R(i, M) if (sz(graph[i]) > 0) sta = i;
    vpi ans = eulerWalk(graph, N, sta);

    if (sz(ans) == 0 || ans[N].f != ans[0].f) return false;
    if (!fin) return true;

    FOR(i, 1, N+1) {
        int cur = ans[i].s;
        if (A[cur].f % M == ans[i-1].f) {
            res.pb(cur*2+1); res.pb(cur*2+2);
        } else {
            res.pb(cur*2+2); res.pb(cur*2+1);
        }
    }

/*    F0R(i, N) {
        set<pi> X = edges[{ans[i], ans[i+1]}];
        pi cur = *edges[{ans[i], ans[i+1]}].begin();
        res.pb(cur.f); res.pb(cur.s);
        edges[{ans[i], ans[i+1]}].erase(cur);
        if (ans[i] != ans[i+1]) edges[{ans[i+1], ans[i]}].erase({cur.s, cur.f});
    }*/
    return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N;
    F0R(i, N) cin >> A[i].f >> A[i].s;

    int lo = 0, hi = 20;
    while (lo < hi) {
        int mid = (lo+hi+1)/2;
        if (solve(mid, false)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }
    solve(lo, true);
    cout << lo << nl;
    F0R(i, sz(res)) {
        cout << res[i] << " ";
    }
    cout << nl;
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343