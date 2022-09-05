#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
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
const int MX = 100001; //check the limits, dummy
 
struct CentroidDecomposition {
	vector<set<int>> tree; // it's not vector<vector<int>>!
	vector<int> dad;
	vector<int> sub;
    vector<int> dep;
    vector<set<int> > ch;
    int oc = -1;

	CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
		int n = tree.size();
		dad.resize(n);
		sub.resize(n);
        dep.resize(n);
        ch.resize(n);
		build(0, -1);
	}
 
	void build(int u, int p) {
		int n = dfs(u, p); // find the size of each subtree
		int centroid = dfs(u, p, n); // find the centroid
        if (oc == -1) oc = centroid;
        if (p == -1) {
            dep[centroid] = 0;
        } else {
            dep[centroid] = dep[p] + 1;
            ch[p].ins(centroid);
        }
		if (p == -1) p = centroid; // dad of root is the root itself
		dad[centroid] = p;
		// for each tree resulting from the removal of the centroid
        while (!tree[centroid].empty()) {
            int v = *(tree[centroid].begin());
			tree[centroid].erase(v); // remove the edge to disconnect
			tree[v].erase(centroid); // the component from the tree
			build(v, centroid);
        }
 
	}
 
	int dfs(int u, int p) {
		sub[u] = 1;
 
		for (auto v : tree[u])
			if (v != p) sub[u] += dfs(v, u);
 
		return sub[u];
	}
 
	int dfs(int u, int p, int n) {
		for (auto v : tree[u])
			if (v != p and sub[v] > n/2) return dfs(v, u, n);
 
		return u;
	}
 
	int operator[](int i) {
		return dad[i];
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

vector<set<int> > graph(MX), cgraph;
vi cd;
mi ans = 0, prod = 1;
mi invs[200001];

mi solve(vector<pair<pmi, mi> >& A) {
    vector<pair<pair<mi, bool>, pmi> > E;
    trav(a, A) {
        pmi X = {a.f.s + 1 - a.f.f, a.s};
        E.pb({{a.f.f, true}, X});
        E.pb({{a.f.s + 1, false}, X});
    }
    sort(all(E));
    mi cur1 = 0, cur2 = 0;
    mi tot1 = 0, tot2 = 0;
    mi res = 0;
    F0R(i, sz(E)) {
        if (i > 0) {
            res += (tot1 + tot2) * (E[i].f.f - E[i-1].f.f);
        }
        if (E[i].f.s) {
            tot1 += E[i].s.s * cur1 * invs[(ll) E[i].s.f];
            tot2 += cur2 * invs[(ll) E[i].s.f];
            cur1 += invs[(ll) E[i].s.f];
            cur2 += invs[(ll) E[i].s.f] * E[i].s.s;
        } else {
            /*tot1 -= E[i].s.s * cur1 * invs[(ll) E[i].s.f];
            tot2 -= cur2 * invs[(ll) E[i].s.f];*/
            cur1 -= invs[(ll) E[i].s.f];
            cur2 -= invs[(ll) E[i].s.f] * E[i].s.s;
            tot1 -= E[i].s.s * cur1 * invs[(ll) E[i].s.f];
            tot2 -= cur2 * invs[(ll) E[i].s.f];
        }

    }
    return res;
}

set<int> curset;
int D[MX], P[MX], cp, cl;
mi L[MX], R[MX];

void dfs2(int v, int p, int d) {
    D[v] = d;
    P[v] = cp;
    curset.ins(v);
    trav(a, graph[v]) {
        if (a == p || cd[a] <= cl) continue;
        dfs2(a, v, d+1);
    }
}

void dfs1(int v) {
    
    vector<pair<pmi, mi> > A;
    A.pb({{L[v], R[v]}, 0});
    cl = cd[v];
    trav(c, graph[v]) {
        if (cd[c] <= cd[v]) continue;
        curset.clear();
        dfs2(c, v, 1);
        vector<pair<pmi, mi> > curv;
        trav(a, curset) {
            curv.pb({{L[a], R[a]}, D[a]});
        }
        ans -= solve(curv);
        trav(a, curv) A.pb(a);
//        cout << ans*prod << " " << v << " " << c << nl;
    }

    ans += solve(A);
//    cout << v << " " << ans*prod << nl;
    trav(c, cgraph[v]) {
        dfs1(c);
    }

}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);    
	
    FOR(i, 1, 200001) invs[i] = inv((mi) i);

    int N; cin >> N;
    F0R(i, N) {
        cin >> L[i] >> R[i];
        prod *= R[i] - L[i] + 1;
    }

    F0R(i, N-1) {
        int A, B; cin >> A >> B; A--; B--;
        graph[A].ins(B);
        graph[B].ins(A);
    }

    CentroidDecomposition ced(graph);

    cgraph = ced.ch;

    cd = ced.dep;

    dfs1(ced.oc);

    cout << ans*prod << nl;
	
	return 0;
}
 
// read the question correctly (ll vs int)
// template by bqi343