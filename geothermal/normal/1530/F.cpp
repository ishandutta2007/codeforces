#include <bits/stdc++.h>
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


const int MOD = 31607;
const char nl = '\n';

struct mi {
	int v; explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(int _v) { 
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
	friend mi pow(mi a, int p) {
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
        int x; is >> x;
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

const int MX = 450;

int N;
mi A[21][21];
mi iten = inv(mi(10000));
mi res[1 << 23];
//int cs = 0;

/*void dfs(int x, int p, int mask, mi cur) {
    //dbg(x, p, mask, cur);
    cs++;
    if (p == N) {
        res[mask] += cur; return;
    }

    vi canAdd;
    canAdd.pb(p);
    if (p == x) {
        canAdd.pb(N);
    }
    if (p == N-1-x) {
        canAdd.pb(N+1);
    }
    FOR(i, 0, (1<<sz(canAdd))-1) {
        int nm = mask;
        F0R(j, sz(canAdd)) {
            if (i & (1 << j)) {
                nm |= 1 << canAdd[j];
            }
        }
        dfs(x, p+1, nm, cur*(A[x][p]));
    }
    trav(a, canAdd) mask |= 1 << a;
    dfs(x, p+1, mask, cur);
}*/

void solve() {
    cin >> N;
    F0R(i, N) F0R(j, N) cin >> A[i][j];
    F0R(i, N) F0R(j, N) A[i][j] *= iten;
    mi ans[1 << (N+2)];
    F0R(i, 1 << (N+2)) ans[i] = 1;
    F0R(i, 1 << (N+2)) res[i] = 0;
    //dbg(A[0][0]);
    F0R(i, N) {
        //dfs(i, 0, 0, 1);
        res[0] = 1;
        F0R(j, N) {
            vi ca; ca.pb(j+2);
            if (j == i) ca.pb(0);
            if (j == N-1-i) ca.pb(1);
            vi cm;
            F0R(k, (1 << sz(ca))) {
                int cur = 0;
                F0R(b, sz(ca)) {
                    if (k & (1 << b)) cur |= 1 << ca[b];
                }
                cm.pb(cur);
            }
            F0Rd(k, 1 << (j+2)) {
                mi val = res[k]; res[k] = 0;
                mi val2 = val*A[i][j];
                //dbg(val*2, val2*2);
                F0R(i, sz(cm)-1) {
                    res[k|cm[i]] += val2;
                }
                res[k|cm[sz(cm)-1]] += val;
            }
            /*if (j == 1) {
                F0R(k, 16) {
                    cout << res[k] << nl;
                }
            }*/
        }

        mi cur = 1;
        F0R(j, N) cur *= A[i][j];
        F0R(j, 1 << (N+2)) {
            res[j] -= cur;
            //dbg(i, j, res[j]*4);
            ans[j] *= res[j];
            res[j] = 0;
        }
    }

    mi fin = 0;
    F0R(i, 1 << (N+2)) {
        if (__builtin_popcount(i) % 2 == N % 2) {
            fin += ans[i];
        } else fin -= ans[i];
    }


    F0R(i, 1 << (N+2)) {
        //dbg(i, ans[i]*16);
    }
    //dbg(fin);
    cout << 1-fin << nl;


}
 
int main() {
    cin.tie(0)->sync_with_stdio(0); 
    cin.exceptions(cin.failbit);

    int T = 1;
//    cin >> T;
    while(T--) {
        solve();
    }

	return 0;
}