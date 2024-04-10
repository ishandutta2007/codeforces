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
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 150001; //check the limits, dummy


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


const ll SZ = 262144; //set this to power of two
mi seg[2*SZ]; //segtree implementation by bqi343's Github

mi sum(int r) {
    mi res = 0;
    for (; r >= 0; r = (r & (r+1)) - 1) {
        res += seg[r];
    }
    return res;
}

mi query(int l, int r) {
    return sum(r) - sum(l-1);
}

void update(int pos, mi val) {
    for (; pos < SZ; pos = pos | (pos + 1)) {
        seg[pos] += val;
    }
}

const int K = 375, L = 800; 
map<int, int> heavyInd;
int ss[MX];
mi hr[L];
int hpar[L][MX];
int heavies[L];
vector<vi> graph(MX);
int in[MX], out[MX], ct = 0;
mi pcinvs[MX];

mi pcinv(mi X) {
    return pcinvs[(ll) X];
}


int preDFS(int v, int p) {
    in[v] = ct;
    ct++;
    ss[v] = 1;
    trav(a, graph[v]) {
        if (a == p) continue;
        ss[v] += preDFS(a, v);
    }

    out[v] = ct-1;
    return ss[v];
}

void preHeavyDFS(int v, int p, int ind, int pp) {
    hpar[ind][v] = pp;
    trav(a, graph[v]) {
        if (a == p) continue;
        preHeavyDFS(a, v, ind, pp);
    }
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    int N; cin >> N;
    int Q; cin >> Q;
    mi invN = inv((mi) N);
    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].pb(B);
        graph[B].pb(A);
    }
    preDFS(0, 0);
    F0R(i, N) {
        if (sz(graph[i]) > K) {
            int ci = sz(heavyInd);
            heavyInd.ins({i, ci});
            heavies[ci] = i;
            hr[ci] = 0;
            trav(a, graph[i]) {
                preHeavyDFS(a, i, ci, a);
            }
        }
    }

    F0R(i, 2*SZ) {
        seg[i] = 0;
    }

    while(Q--) {
        int T; cin >> T;
        int V; cin >> V; V--;

        if (T == 1) {
            mi D; cin >> D;
            if (heavyInd.count(V)) {
                hr[heavyInd[V]] += D;
            } else {
                update(in[V], D);
                update(in[V] + 1, -D);
                trav(a, graph[V]) {
                    if (ss[a] > ss[V]) continue;
                    update(in[a], D * (N - ss[a]) * invN);
                    update(out[a] + 1, -D * (N - ss[a]) * invN);
                }
                update(0, D * ss[V] * invN);
                update(in[V], D * ss[V] * invN * -1);
                update(out[V] + 1, D * ss[V] * invN);
            }
        } else {
            mi ans = query(0, in[V]);
            int P = -1; if (heavyInd.count(V)) P = heavyInd[V];
            F0R(i, sz(heavyInd)) {
                if (i == P) {
                    ans += hr[i];
                } else {
                    int p = hpar[i][V];
                    if (ss[p] > ss[heavies[i]]) {
                        ans += hr[i] * ss[heavies[i]] * invN;
                    } else {
                        ans += hr[i] * (N - ss[p]) * invN;
                    }
                }
            }
            cout << ans << nl;
        }
    }


	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343