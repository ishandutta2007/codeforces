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

void __print(mi X) {
    cout << X.v;
}
int K;
mi A, H;
mi vals[6];
int places[6];


map<int, map<mi, vi>> get(vi B) {
    int nm = (1 << (K-1)) - 1;
    map<int, map<mi, vi>> res;
    F0R(m, 1 << nm) {
        int p = 0;
        int v = K;
        vi cur; F0R(i, sz(B)) cur.pb(i);
        vi place(sz(B));
        mi value = 0;
        while (sz(cur) > 1) {
            vi nxt;
            F0R(i, sz(cur) / 2) {
                if (m & (1 << p)) {
                    nxt.pb(cur[i*2]);
                    place[cur[i*2+1]] = places[v];
                    value += B[cur[i*2+1]] * vals[v];
                } else {
                    nxt.pb(cur[i*2+1]);
                    place[cur[i*2]] = places[v];
                    value += B[cur[i*2]] * vals[v];
                }
                p++;
            }
            cur = nxt;
            v--;
        }
        place[cur[0]] = 2;
        value += B[cur[0]] * vals[1];
       /* vi tst = {5, 3, 5, 2};
        if (place == tst) {
            dbg(cur[0],value);
        }*/
        res[B[cur[0]]][value] = (place);
    }
    return res;
}

void solve() {
    cin >> K >> A >> H;
    vals[0] = A;
    FOR(i, 1, 6) {
        vals[i] = pow(mi(A), (pow(mi(2), i-1) +1).v);
    }
    places[0] = 1; places[1] = 2; places[2] = 3; places[3] = 5; places[4] = 9;
    places[5] = 17;
    vi A1, A2;
    F0R(i, 1 << (K-1)) {
        A1.pb(i+1);
        A2.pb(i+1+(1<<(K-1)));
    }

    map<int, map<mi, vi>> res1 = get(A1), res2 = get(A2);
    trav(a, res1) {
        trav(b, res2) {
            trav(x, a.s) {

                mi cur1 = x.f + a.f * vals[0] - a.f * vals[1];
                if (b.s.count(H-cur1)) {
                    vi ans1 = x.s, ans2 = b.s[H-cur1];
                    ans1[a.f-1] = 1;
                    trav(c, ans1) cout << c << " ";
                    trav(c, ans2) cout << c << " ";
                    return;
                }
                mi cur2 = x.f + b.f * vals[0] - b.f * vals[1];
                /*if (x.f.v == 706382488) {
                    dbg(cur2);
                }*/
               if (b.s.count(H-cur2)) {
                    vi ans1 = x.s, ans2 = b.s[H-cur2];
                    ans2[b.f-(1 << (K-1))-1] = 1;
                    trav(c, ans1) cout << c << " ";
                    trav(c, ans2) cout << c << " ";
                    return;
                }
            }
        }
    }

    cout << -1 << nl;




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