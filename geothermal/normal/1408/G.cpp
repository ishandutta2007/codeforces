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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy


struct mi {
	ll v; explicit operator ll() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
    mi operator++(int) { mi temp; temp.v = v++; return temp; }
    mi operator--(int) { mi temp; temp.v = v--; return temp; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
    friend ostream& operator<<(ostream& os, const mi& m) {
        os << m.v; return os;
    }
    friend istream& operator>>(istream& is, mi& m) {
        ll x; is >> x;
        m.v = x;
        return is;
    }
};


typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;

vmi mul(vmi& A, vmi& B) {
    vmi res(sz(A) + sz(B));
    F0R(i, sz(A)) {
        F0R(j, sz(B)) {
            res[i+j+1] += A[i] * B[j];
        }
    }
    res[0] = 0;
    return res;
}

ll parent[MX], sz[MX], cnt[MX];
vi comps[MX];
int nc = 0;
vector<vi> graph;
vector<vmi> dp;

void dfs(int v, int p) {
    trav(a, graph[v]) {
        dfs(a, v);
        if (sz(dp[v]) != 0) {
            dp[v] = mul(dp[v], dp[a]);
        } else {
            dp[v] = dp[a];
        }
    }
    if (sz(dp[v]) == 0) {
        dp[v] = {1};
    }
    dp[v][0] = 1;
}

void init() {
    F0R(i, MX) {
        parent[i] = i; sz[i] = 1;  cnt[i] = 0; comps[i].pb(i);
    }
}

int get(int x) {
    if (parent[x] != x) parent[x] = get(parent[x]);
    return parent[x];
}

void unify(int x, int y) {
    x = get(x); y = get(y);
    if (sz[x] < sz[y]) swap(x, y);

    cnt[x]++;
    if (x != y)  {
        cnt[x] += cnt[y];
        trav(a, comps[y]) {
            comps[x].pb(a);
        }
        sz[x] += sz[y];
        parent[y] = x;
    }
    if (cnt[x] == (sz[x] * (sz[x] - 1)) / 2) {
        graph.pb(vi());
        trav(a, comps[x]) {
            graph[nc].pb(a);
        }
        comps[x].clear();
        comps[x].pb(nc);
        nc++;
    }

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    pi ed[(N*(N-1))/2];
    init();
    F0R(i, N) graph.pb(vi());
    nc = N;
    F0R(i, N) {
        F0R(j, N) {
            int X; cin >> X;
            if (i <= j) continue;
            ed[X-1] = {i, j};
        }
    }
    F0R(i, N*(N-1)/2) {
        unify(ed[i].f, ed[i].s);
    }
    F0R(i, nc) dp.pb(vmi());
    nc--;
    dfs(nc, -1);
    F0R(i, sz(dp[nc])) {
        cout << dp[nc][i] << " ";
    }
    cout << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343