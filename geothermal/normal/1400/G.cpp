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
const int MX = 300001; //check the limits, dummy

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


mi facs[MX];
mi facInvs[MX];

mi choose(mi _a, mi _b) {
    ll a = (ll) _a, b = (ll) _b;
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    mi cur = facs[a];
    cur = cur * facInvs[b];
    cur = cur * facInvs[a-b];
    return cur;
}

void initFacs() {
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i);
	}
    facInvs[MX - 1] = inv(facs[MX-1]);
    FORd(i, 1, MX-1) {
        facInvs[i] = facInvs[i+1] * (i+1);
    }
    facInvs[0] = 1;
}

set<pi> ed;
set<int> ag;
vmi cnt(41);
void get() {
    vpi edges; trav(a, ed) edges.pb(a);
    mi cntNum[41];
    int total = sz(ag);
    F0R(m, (1 << sz(edges))) {
        set<int> must;
        F0R(i, sz(edges)) if (m & (1 << i)) {
            must.ins(edges[i].f);
            must.ins(edges[i].s);
        }
        if (__builtin_popcount(m) % 2 == 0) {
            cntNum[sz(must)]++;
        } else {
            cntNum[sz(must)]--;
        }
    }
    F0R(i, 41) cnt[i] = 0;
    F0R(i, total+1) {
        FOR(j, i, total+1) {
            cnt[j] += choose(total - i, j - i) * cntNum[i];
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    initFacs();

    int N, M; cin >> N >> M;
    vector<vi> graph(N);
    vpi ev;
    F0R(i, N) {
        int L, R; cin >> L >> R; 
        ev.pb({L, i});
        ev.pb({R+1, i});
    }
    F0R(i, M) {
        int A, B; cin >> A >> B; A--; B--; graph[A].pb(B); graph[B].pb(A);
    }

    bool in[N]; F0R(i, N) in[i] = false;
    mi ans = 0;
    int p = 0;
    int curIn = 0;
    cnt[0] = 1;
    sort(all(ev));
    FOR(i, 1, N+1) {
        while (p < sz(ev) && ev[p].f == i) {
            int x = ev[p].s;
            if (!in[x]) {
                in[x] = true;
                if (sz(graph[x]) > 0) {
                    trav(a, graph[x]) {
                        if (in[a]) ed.ins({min(a, x), max(a, x)});
                    }
                    ag.ins(x);
                    get();
                } else {
                    curIn++;
                }
            } else {
                in[x] = false;
                if (sz(graph[x]) > 0) {
                    trav(a, graph[x]) {
                        if (in[a]) ed.erase({min(a, x), max(a, x)});
                    }
                    ag.erase(x);
                    get();
                } else {
                    curIn--;
                }
            }
            p++;
        }
        F0R(c, min(41, i+1)) {
            mi curCnt = cnt[c];
            ans += curCnt * choose(curIn, i-c);
        }
    }

    cout << ans << nl;

	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343