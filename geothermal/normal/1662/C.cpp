#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
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

template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif


const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; 

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
    mi operator++(int) { v++; if (v == MOD) v = 0; return mi(v); }
    mi operator--(int) { v--; if (v < 0) v = MOD-1; return mi(v); }
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

void __print(mi X) {
    cout << X.v;
}


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
    int N, M, K; cin >> N >> M >> K;
    Matrix<mi> m(2*N, 2*N);
    F0R(i, N) {
        m.data[i+N][i] = 1;
    }
    F0R(i, M) {
        int X, Y; cin >> X >> Y; X--; Y--;
        F0R(x, 2) {
            m.data[X][Y]++;
            m.data[X][X+N]--;
            swap(X, Y);
        }
    }

    Matrix<mi> m2(2*N, 2*N);
    F0R(i, 2*N) {
        F0R(j, 2*N) {
            m2.data[i][j] = m.data[i][j];
        }
    }
    F0R(X, N) {
        if (m2.data[X][X+N].v != 0) {
            m2.data[X][X+N] += 1;
        }
    }
    /*FOR(p, 1, 5) {
        cout << p << ":" << nl;
        Matrix mm = exp(m, p);
        F0R(i, 2*N) {
            F0R(j, 2*N) {
                if (mm.data[i][j].v > 20) {
                    cout << "-" << MOD-mm.data[i][j] << " ";
                } else cout << mm.data[i][j] << " ";
            }
            cout << nl;
        }
        cout << nl;
    }*/


    m = m * exp(m2, K-1);
    mi ans = 0;
    F0R(i, N) {
        ans += m.data[i][i];
    }
    cout << ans << nl;

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