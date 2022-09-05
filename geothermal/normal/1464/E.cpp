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
const int MX = 100001*2; //check the limits, dummy
 
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

    int N, M; cin >> N >> M;
    vector<vi> graph(N); 
    vector<vi> gr(N); 
    int in[N]; F0R(i, N) in[i] = 0;
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        graph[Y].pb(X);
        gr[X].pb(Y);
        in[X]++;
    }

    queue<int> q;
    F0R(i, N) if (in[i] == 0) q.push(i);
    int grun[N]; 
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        set<int> used;
        trav(a, gr[cur]) {
            used.ins(grun[a]);
        }
        int x = 0;
        while (used.count(x)) x++;
        grun[cur] = x;

        trav(a, graph[cur]) {
            in[a]--;
            if (in[a] == 0) q.push(a);
        }
    }

    vector<vmi> coef(512);
    F0R(i, 512) coef[i] = vmi(513);
    mi oneOver = inv(mi(N+1));
    F0R(i, 512) {
        if (i != 0) coef[i][512] = oneOver;
        coef[i][i] = 1;
        F0R(j, N) {
            coef[i][i ^ grun[j]] -= oneOver;
        }
    }
/*    F0R(i, N) {
        F0R(j, N) {
            cout << coef[i][j] << " ";
        }
        cout << coef[i][512] << nl;
    }*/
    int h = 0, k = 0;
    while (h < 512 && k < 513) {
        int i_max = h;
        FOR(j, h+1, 512) if (coef[j][k] != 0) i_max = j;
        if (coef[i_max][k] == 0) {
            k++;
        } else {
            F0R(i, 513) {
                swap(coef[h][i], coef[i_max][i]);
            }
            mi inVal = inv(coef[h][k]);
            F0R(i, 513) {
                coef[h][i] *= inVal;
            }
            F0R(i, 512) {
                if (i == h) continue;
                mi cur = coef[i][k];
                F0R(j, 513) {
                    coef[i][j] -= cur * coef[h][j];
                }
            }
            h++; k++;
        }
/*        F0R(i, N) {
            F0R(j, N) {
                cout << coef[i][j] << " ";
            }
        }*/
    }
    cout << coef[0][512] << nl;
/*    F0R(i, N) {
        F0R(j, N) {
            cout << coef[i][j] << " ";
        }
        cout << coef[i][512] << nl;
    }*/
/*    vi gruns; F0R(i, N) gruns.pb(grun[i]);
    sort(all(gruns));
    map<int, mi> cur;
    cur[0] = 1;
    mi oneThird = inv(mi(3));
    trav(g, gruns) {
        map<int, mi> nxt;
        trav(a, cur) {
            nxt[a.f] += a.s * oneThird * 2;
            nxt[a.f ^ g] += a.s * oneThird;
        }
        cur = nxt;
        trav(a, nxt) {
            cout << "TEST " << a.f << " " << a.s << nl;
        }
    }

    cout << 1 - cur[0] << nl;*/
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343