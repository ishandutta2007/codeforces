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
const int MX = 200001; //check the limits, dummy
int N, M; 
vector<vi> g(MX), gt(MX);

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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    cin >> N >> M;
    F0R(i, M) {
        int U, V; cin >> U >> V; U--; V--;
        g[U].pb(V);
        gt[V].pb(U);
    }

    ll distBrute[N][20];
    F0R(i, N) {
            F0R(k, 20) {
                distBrute[i][k] = 1e18;
        }
    }
    distBrute[0][0] = 0;
    priority_queue<pair<ll, pair<int, int> >, vector<pair<ll, pair<int, int>> >, greater<pair <ll, pair<int, int>> > > q;

    bool vis[N][20]; F0R(i, N) F0R(k, 20) vis[i][k] = false;
    q.push({0, {0, 0}});

    while (!q.empty()) {
        pair<int, int> cur = q.top().s;
        q.pop();
        int v = cur.f;
        int nf = cur.s;
        if (vis[v][nf]) {
            continue;
        }
        vis[v][nf] = true;
        if (nf < 19 && ckmin(distBrute[v][nf+1], distBrute[v][nf] +
                    (1 << nf))) {
            q.push({distBrute[v][nf+1], {v, nf+1}});
        }

        if (nf % 2 == 0) {
            trav(a, g[v]) {
                if (ckmin(distBrute[a][nf], distBrute[v][nf] + 1)) {
                    q.push({distBrute[a][nf], {a, nf}});
                }
            }
        } else {
            trav(a, gt[v]) {
                if (ckmin(distBrute[a][nf], distBrute[v][nf] + 1)) {
                    q.push({distBrute[a][nf], {a, nf}});
                }
            }
        }
    }

    priority_queue<pair<pi, pi>, vector<pair<pi, pi>>, greater<pair<pi, pi>>>
        q2;
    bool vis2[N][2]; F0R(i, N) F0R(j, 2)vis2[i][j] = false;
    pi dist2[N][2]; F0R(i, N) F0R(j, 2) dist2[i][j] = {1000000000, 1000000000};
    dist2[0][0] = {0, 0};
    q2.push({{0, 0}, {0, 0}});

    while (!q2.empty()) {
        int v = q2.top().s.f;
        int nf = q2.top().s.s;
        q2.pop();
        if (vis2[v][nf]) continue;
        vis2[v][nf] = true;

        if (ckmin(dist2[v][1-nf], {dist2[v][nf].f+1, dist2[v][nf].s})) {
            q2.push({dist2[v][1-nf], {v, 1-nf}});
        }

        if (nf % 2 == 0) {
            trav(a, g[v]) {
                if (ckmin(dist2[a][nf], {dist2[v][nf].f, dist2[v][nf].s+1})) {
                    q2.push({dist2[a][nf], {a, nf}});
                }
            }
        } else {
            trav(a, gt[v]) {
                if (ckmin(dist2[a][nf], {dist2[v][nf].f, dist2[v][nf].s+1})) {
                    q2.push({dist2[a][nf], {a, nf}});
                }
            }
        }
    }

    ll ans1 = 10000000;
    F0R(i, 20) {
        ckmin(ans1, distBrute[N-1][i]);
    }

    pi res = min(dist2[N-1][0], dist2[N-1][1]);
    mi ans2 = pow(mi(2), res.f) + res.s - 1;
    
    if (ans1 == 10000000) {
        cout << ans2 << nl;
    } else {
        cout << ans1 << nl;
    }



	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343