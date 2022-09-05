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
const int MX = 401; //check the limits, dummy

template<int SZ> struct DSU {
    int parent[SZ], size[SZ];

    DSU() {
        F0R(i, SZ) parent[i] = i, size[i] = 0;
    }

    int get(int x) {
        if (parent[x] != x) parent[x] = get(parent[x]);
        return parent[x];
    }

    void unify(int x, int y) {
        x = get(x); y = get(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        if (size[x] == size[y]) size[x]++;
        parent[y] = x;

    }
};


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

void solve() {

    int N, M; cin >> N >> M;
    vector<vpi> graph(N);
    vpi ed(M);
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        ed[i] = {X, Y};
        graph[X].pb({Y, i}); graph[Y].pb({X, i});
    }

    bool valid[N][M]; 
    int dist[N][N];
    F0R(r, N) {
        F0R(i, M) valid[r][i] = false;
        F0R(i, N) dist[r][i] = N+1;
        dist[r][r] = 0;
        queue<int> q; q.push(r);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            trav(a, graph[cur]) {
                if (ckmin(dist[r][a.f], dist[r][cur]+1)) q.push(a.f);
                if (dist[r][a.f] == dist[r][cur]+1) {
                    valid[r][a.s] = true;
                }
            }
        }
    }

    F0R(a, N) {
        F0R(b, N) {
            int cnt[dist[a][b]+1]; F0R(i, dist[a][b]+1) cnt[i] = 0;
            F0R(i, N) {
                if (dist[a][i] + dist[i][b] == dist[a][b]) cnt[dist[a][i]]++;
            }
            int num[N];
            mi ans = 1;
            F0R(i, dist[a][b]+1) {
                if (cnt[i] != 1) {
                    cout << 0 << " "; goto done;
                }
            }

            F0R(i, N) num[i] = 0;
            F0R(i, M) {
                if (dist[a][ed[i].f] == dist[a][ed[i].s]+ 1 && dist[b][ed[i].f] == dist[b][ed[i].s]+1) {
                    num[ed[i].f]++;
                }
                if (dist[a][ed[i].s] == dist[a][ed[i].f] + 1 && dist[b][ed[i].s] == dist[b][ed[i].f]+1) {
                    num[ed[i].s]++;
                }
            }
            F0R(i, N) {
                if (dist[a][i] + dist[i][b] != dist[a][b]) ans *= num[i];
            }
            cout << ans << " ";
            done:
            ;
        }
        cout << nl;
    }

}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343