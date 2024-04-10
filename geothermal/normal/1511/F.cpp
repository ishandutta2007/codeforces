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
struct AhoCorasick {
    static const int K = 26;


    struct Vertex {
        int next[K];
        bool leaf = false;
        int p = -1;
        char pch;
        int link = -1;
        int go[K];
        ll value = -1;
        ll num = 0;
        string S;

        Vertex(int p=-1, char ch='$', string app = "") : p(p), pch(ch) {
            if (p == -1) {
                S = "";
            } else {
                S = app + ch;
            }
            fill(begin(next), end(next), -1);
            fill(begin(go), end(go), -1);
        }
    };

    vector<Vertex> t;


    void init() {
        Vertex v; t.pb(v);
    }



    void add_string(string const& s, int count) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[v].next[c] == -1) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch, t[v].S);
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
        t[v].num = count;
    }



    int safeGo(int v, int c) {
        if (v == -1) return -1;
        //bool err = false;
        if (t[v].go[c] == -1) {
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
        }
        return t[v].go[c];

    }
};



template<class T> struct Matrix {
    int R, C;
    vector<vector<T>> data;

    Matrix(int r, int c) {
        R = r; C = c;
        F0R(i, R) {
            vector<T> blank(c);
            data.pb(blank);
        }
    }

    Matrix(vector<vector<T>> dat) {
        data = dat; R = sz(data); C = sz(data[0]);
    }

    Matrix operator+(const Matrix& M) {
        Matrix res(R, C);
        F0R(i, R) {
            F0R(j, C) {
                res.data[i][j] = data[i][j] + M.data[i][j];
            }
        }
        return res;
    }

    Matrix operator-(const Matrix& M) {
        Matrix res(R, C);
        F0R(i, R) {
            F0R(j, C) {
                res.data[i][j] = data[i][j] - M.data[i][j];
            }
        }
        return res;
    }

    Matrix operator*(const Matrix& M) {
        Matrix res(R, M.C);
        F0R(i, R) F0R(j, M.C) res.data[i][j] = 0;
        F0R(i, R) {
            F0R(j, C) {
                F0R(k, M.C) {
                    res.data[i][k] += data[i][j] * M.data[j][k];
                }
            }
        }
        return res;
    }

    Matrix& operator+=(const Matrix& M) {
        return *this = (*this)+M;
    }

    Matrix& operator-=(const Matrix& M) {
        return *this = (*this)-M;
    }

    Matrix& operator*=(const Matrix& M) {
        return *this = (*this)*M;
    }

    friend Matrix exp(Matrix M, ll P) {
        Matrix res(M.R, M.C);
        F0R(i, M.R) {
            res.data[i][i] = 1;
        }
        for (; P; P /= 2, M *= M) if (P & 1) res *= M;
        return res;
    }
};

void solve() {

    int N, M; cin >> N >> M;
    string S[N];
    F0R(i, N) cin >> S[i];
    AhoCorasick ac; ac.init();
    F0R(i, N) {
        ac.add_string(S[i], 1);
    }
    
    int K = sz(ac.t);
    map<pi, int> states;
    vi dual;

    F0R(i, K) {
        F0R(j, sz(ac.t[i].S) + 1) {
            int v = 0;
            FOR(k, sz(ac.t[i].S) - j, sz(ac.t[i].S)) {
                v = ac.safeGo(v, ac.t[i].S[k]-'a');
            }
            if (v == -1) continue;
            //cout << i << " " << j << " " << sz(states) << nl;
            states[{i, j}] = sz(states);
            dual.pb(v);
        }
    }
    int ns = sz(states);
    Matrix<mi> trans(ns, ns);
    trav(a, states) {
        //cout << a.f.f << " " << a.f.s << " " << a.s << " state " << dual[a.s] << nl;
        F0R(i, 26) {
            int nv = ac.safeGo(a.f.f, i);
            if (!states.count({nv, a.f.s+1})) continue;
            //cout << a.f.f << " " << a.f.s << " " << nv << " " << i << " Transition" << nl;
            int nst = states[{nv, a.f.s+1}];
            trans.data[nst][a.s]++;
            if (ac.t[nv].num != 0) {
                trans.data[states[{dual[nst], 0}]][a.s]++;
                if (ac.t[dual[nst]].num != 0) {
                    trans.data[0][a.s]++;
                }
            }
            if (ac.t[dual[nst]].num != 0) {
                //cout << states.count({nst, 0}) << " " << nst << " count" << nl;
                trans.data[states[{nv, 0}]][a.s]++;
            }
        }
    }

    /*F0R(i, ns) {
        F0R(j, ns) {
            cout << trans.data[i][j] << " ";
        }
        cout << nl;
    }*/

    trans = exp(trans, M);
    
    cout << trans.data[0][0];

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