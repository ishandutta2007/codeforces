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

inline namespace Helpers {
	//////////// is_iterable
	// https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
	// this gets used only when we can call begin() and end() on that type
	template<class T, class = void> struct is_iterable : false_type {};
	template<class T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
	                                  decltype(end(declval<T>()))
	                                 >
	                       > : true_type {};
	template<class T> constexpr bool is_iterable_v = is_iterable<T>::value;

	//////////// is_readable
	template<class T, class = void> struct is_readable : false_type {};
	template<class T> struct is_readable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cin >> declval<T&>()), istream&>
	        >
	    > : true_type {};
	template<class T> constexpr bool is_readable_v = is_readable<T>::value;

	//////////// is_printable
	// // https://nafe.es/posts/2020-02-29-is-printable/
	template<class T, class = void> struct is_printable : false_type {};
	template<class T> struct is_printable<T,
	        typename std::enable_if_t<
	            is_same_v<decltype(cout << declval<T>()), ostream&>
	        >
	    > : true_type {};
	template<class T> constexpr bool is_printable_v = is_printable<T>::value;
}

inline namespace Input {
	template<class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
	template<class T, class ...U> void re(T& t, U&... u);
	template<class T, class U> void re(pair<T,U>& p); // pairs

	// re: read
	template<class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
	template<class T> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
	template<class T> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
	template<class T, class U> void re(pair<T,U>& p) { re(p.f,p.s); }
	template<class T> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
		trav(x,i) re(x); }
	template<class T, class ...U> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

	// rv: resize and read vectors
	void rv(size_t) {}
	template<class T, class ...U> void rv(size_t N, vector<T>& t, U&... u);
	template<class...U> void rv(size_t, size_t N2, U&... u);
	template<class T, class ...U> void rv(size_t N, vector<T>& t, U&... u) {
		t.resize(N); re(t);
		rv(N,u...); }
	template<class...U> void rv(size_t, size_t N2, U&... u) {
		rv(N2,u...); }
}

inline namespace ToString {
	template<class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

	// ts: string representation to print
	template<class T> typename enable_if<is_printable_v<T>,string>::type ts(T v) {
		stringstream ss; ss << fixed << setprecision(15) << v;
		return ss.str(); } // default
	template<class T> string bit_vec(T t) { // bit vector to string
		string res = "{"; F0R(i,sz(t)) res += ts(t[i]);
		res += "}"; return res; }
	string ts(vector<bool> v) { return bit_vec(v); }
	template<size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
	template<class T, class U> string ts(pair<T,U> p); // pairs
	template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v); // vectors, arrays
	template<class T, class U> string ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
	template<class T> typename enable_if<is_iterable_v<T>,string>::type ts_sep(T v, string sep) {
		// convert container to string w/ separator sep
		bool fst = 1; string res = "";
		for (const auto& x: v) {
			if (!fst) res += sep;
			fst = 0; res += ts(x);
		}
		return res;
	}
	template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v) {
		return "{"+ts_sep(v,", ")+"}"; }

	// for nested DS
	template<int, class T> typename enable_if<!needs_output_v<T>,vector<string>>::type
	  ts_lev(const T& v) { return {ts(v)}; }
	template<int lev, class T> typename enable_if<needs_output_v<T>,vector<string>>::type
	  ts_lev(const T& v) {
		if (lev == 0 || !sz(v)) return {ts(v)};
		vector<string> res;
		for (const auto& t: v) {
			if (sz(res)) res.back() += ",";
			vector<string> tmp = ts_lev<lev-1>(t);
			res.ins(end(res),all(tmp));
		}
		F0R(i,sz(res)) {
			string bef = " "; if (i == 0) bef = "{";
			res[i] = bef+res[i];
		}
		res.back() += "}";
		return res;
	}
}

inline namespace Output {
	template<class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
	template<class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
		pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
	// print w/ no spaces
	template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); }
    template<class ...T> void prn(const T&... t) { pr_sep(cout,"",t...); pr('\n'); }
	// print w/ spaces
	template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); }
    template<class ...T> void psn(const T&... t) { pr_sep(cout," ",t...); pr('\n'); }
	// debug to cerr
	template<class ...T> void dbg_out(const T&... t) {
		pr_sep(cerr," | ",t...); cerr << endl; }
	void loc_info(int line, string names) {
		cerr << "Line(" << line << ") -> [" << names << "]: "; }
	template<int lev, class T> void dbgl_out(const T& t) {
		cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
	#ifdef LOCAL
		#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
		#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
	#else // don't actually submit with this
		#define dbg(...) 0
		#define dbgl(lev,x) 0
	#endif
}

inline namespace FileIO {
	void setIn(string s)  { (void)!freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { (void)!freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
		cin.exceptions(cin.failbit);
		// throws exception when do smth illegal
		// ex. try to read letter into int
		if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
	}
    void setIO(string s, string t) {
        cin.tie(0)->sync_with_stdio(0);
        setIn(s); setIn(t);
    }
}
 
int MOD = 1000000007;
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
    F0Rd(i, MX-1) {
        facInvs[i] = facInvs[i+1] * (i+1);
    }
}
void solve() {

    int N; re(N, MOD);
    initFacs();
    mi dp[N+1][N+1], nxt[N+1][N+1]; 
    dp[1][1] = 1;
    mi pows[N+1]; pows[0] = 1; FOR(i, 1, N+1) pows[i] = pows[i-1] * 2;
    F0R(i, N-1) {
        F0R(j, N) {
            F0R(k, N) {
                nxt[j+1][k+1] += dp[j][k];
                if (j != 0) {
                    nxt[0][k] += dp[j][k] * pows[j-1] * choose(k, j);
                }
            }
        }
        F0R(i, N+1) F0R(j, N+1) {
            dp[i][j] = nxt[i][j]; nxt[i][j] = 0;
        }
    }
    mi ans = 0;
    FOR(i, 1, N+1) {
        F0R(j, N+1) {
            ans += dp[i][j] * pows[i-1] * choose(j, i);
        }
    }
    prn(ans);
    /*F0R(i, N) {
        F0R(j, N+1) {
            F0R(k, N+1) {
                dbg(i, j, k, dp[i][j][k]);
            }
        }
    }*/
}
 
int main() {
    setIO();

    int T = 1;
//    re(T);
    while(T--) {
        solve();
    }

	return 0;
}