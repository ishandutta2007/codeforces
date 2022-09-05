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
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
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
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N, M; ll Q; cin >> N >> M >> Q;
    vector<vpl> graph(N);
    F0R(i, M) {
        int A, B, C; cin >> A >> B >> C;
        A--; B--;
        graph[A].pb({B, C});
        graph[B].pb({A, C});
    }

    ll dist[N][N];
    F0R(i, N) {
        F0R(j, N) {
            dist[i][j] = -1e10;
        }
    }
    dist[0][0] = 0;
    F0R(iter, N-1) {
        F0R(i, N) {
            F0R(j, sz(graph[i])) {
                int x = graph[i][j].f;
                ll d = graph[i][j].s + dist[i][iter];
                dist[x][iter+1] = max(dist[x][iter+1], d);
            }
        }
    }

    vpl funs;
    F0R(i, N) {
        ll mx = 0;
        F0R(j, sz(graph[i])) {
            mx = max(mx, graph[i][j].s);
        }
        funs.pb({mx, dist[i][N-1] - mx*(N-1)});
    }
    sort(all(funs));

    mi ans = 0;
    FOR(i, 1, N) {
        ll mx = 0;
        F0R(j, N) {
            mx = max(mx, dist[j][i]);
        }
        ans += mx;
    }

    int cur = 0;
    F0R(i, N) {
        if (funs[i].s + funs[i].f * N >= funs[cur].s + funs[cur].f * N) {
            cur = i;
        }
    }

    ll T = N;
    mi half = 500000004;
    while (T <= Q && cur < N) {
        int nxt = N;
        ll time = 1e18;

        FOR(i, cur+1, N) {
            ll nt = funs[cur].s - funs[i].s + funs[i].f - funs[cur].f - 1;
            nt /= funs[i].f - funs[cur].f;
            if (nt <= time) {
                time = nt;
                nxt = i;
            }
        }
        time = min(time, Q+1);
        mi lo = funs[cur].f * T + funs[cur].s;
        mi hi = funs[cur].f * (time-1) + funs[cur].s;
        mi cnt = time - T;
//        cout << time << " " << lo << " " << hi << " " << cnt << " " << ans << nl;
        ans += cnt * (hi + lo) * half;
        cur = nxt; T = time;
    }

    cout << ans << nl;


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343