/**
                      alex256                   
   
   Contest CodeForces Round 390 (Div. 2)         
   
   Task    ?                                     
   
   Date    06.01.2017                            
   **/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
//#define USE_LONGLONG
//#define USE_UNORDERED
//#define FILE_IO
//#undef LOCAL
#ifdef FILE_IO
	#define TASK_NAME "taskname"
	#define INPUT_FILE TASK_NAME".in"
	#define OUTPUT_FILE TASK_NAME".out"
#endif
/// Includes 
#include <bits/stdc++.h>
using namespace std;
/// Defines
#ifdef USE_UNORDERED
	#define set unordered_set
	#define map unordered_map
#endif
#if defined(FILE_IO) && (!defined(LOCAL))
	#define cin __new_cin
	#define cout __new_cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#endif
#ifdef USE_LONGLONG
	#define int ll
	#define inf llInf
#endif
#define endl "\n"
#define sz(a) (int)(a.size())
#define here dbg("here!")
#define endless for (;;)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
/// Types
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
struct ofl { ld value; int precision; inline ofl(ld value, int precision) : value(value), precision(precision) {} };
/// Constants
const int seed = hash<string>()("alex256");
#ifndef USE_LONGLONG
	const int inf = (int)1e9 + 7;
#endif
const ll llInf = (ll)2e18 + 256;
const int mod = (int)1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "";
const char* errText = "error :(";
/// Iostream extension
template<typename T1, typename T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) { return is >> p.F >> p.S; } 
template<typename T1, typename T2> inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.F << " " << p.S; } 
template<typename T> inline istream& operator>>(istream& is, vector<T>& v) { for (int i = 0; i < sz(v); i++) { is >> v[i]; } return is; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < sz(v); i++) { if (i) { os << " "; } os << v[i]; } return os; }
inline ostream& operator<<(ostream& os, const ofl& o) { return os << fixed << setprecision(o.precision) << o.value; }
inline bool iosOptimize() { ios_base::sync_with_stdio(false); return true; }
bool iosOptimized = iosOptimize();
/// Input
template<typename T> inline T get() { T value; cin >> value; return value; }
template<> inline char get() { char c = '\0'; while (c <= ' ') { cin >> c; } return c; }
inline string getLn() { string s; getline(cin, s); return s; }
template<typename T, size_t Count> struct VectorPacker { typedef vector< typename VectorPacker<T, Count-1>::Type > Type; };
template<typename T> struct VectorPacker<T, 0> { typedef T Type; };
template<typename T> inline vector<T> getVector(int size) { vector<T> res(size); cin >> res; return res; }
template<typename T, typename U, typename... Args> inline typename VectorPacker<T, sizeof...(Args)+1>::Type getVector(U size, Args... sizes) { typename VectorPacker<T, sizeof...(Args)+1>::Type res(size); for (int i = 0; i < (int)size; i++) { res[i] = getVector<T>(sizes...); } return res; }
/// Output
inline void put() {}
template<typename T, typename... Args> inline void put(const T& value, const Args&... vals) { cout << value; put(vals...); }
template<typename... Args> inline void putLn(const Args&... vals) { put(vals...); cout << endl; }
/// Debug
#ifdef LOCAL
	template<typename... Args> inline void dbg(const Args&... vals) { putLn(vals...); cout.flush(); }
#else
	#define dbg(...)
#endif
/// Hash overload for pairs
namespace std { template<typename T1, typename T2> struct hash<pair<T1, T2> > { inline size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.F) ^ hash<T2>()(p.S); } }; };
/// Helpful methods
mt19937_64 rnd(seed);
inline void error(const char* text = errText) { dbg(text); exit(256); }
template <typename T1, typename T2> inline void umax(T1& a, const T2& b) { if (a < b) { a = b; } }
template <typename T1, typename T2> inline void umin(T1& a, const T2& b) { if (a > b) { a = b; } }
ll gcd(ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll extGcd(ll a, ll b, ll& x, ll& y) { if (!a) { x = 0; y = 1; return b; } ll x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
inline int addMod(int a, int b, int m = mod) { return ((ll)a + b) % m; }
inline int subMod(int a, int b, int m = mod) { return ((ll)a + mod - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((ll)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { ll x, y; ll g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", mod); exit(42); }  x = (x % m + m) % m; return mulMod(a, x); }
/// End of The Template

#define messages _______msgs

int t = get<int>();
typedef pair<int, vector<int> > Message;

int n, m;
vector<string> users;
vector<Message> messages;
vector<string> messageStrs;

inline int findString(const string& s) {
	for (int i = 0; i < n; i++) {
		if (users[i] == s) {
			return i;
		}
	}
	return -1;
}

inline bool isLetter(char c) {
	if ('a' <= c && c <= 'z') {
		return true;
	}
	if ('A' <= c && c <= 'Z') {
		return true;
	}
	if ('0' <= c && c <= '9') {
		return true;
	}
	return false;
}

inline vector<string> parseToWords(string s) {
	vector<string> ans;
	int n = sz(s);
	for (int i = 0; i < n; ) {
		while (i < n && !isLetter(s[i])) {
			i++;
		}
		if (i >= n) {
			break;
		}
		int beg = i, len = 0;
		while (i < n && isLetter(s[i])) {
			i++;
			len++;
		}
		ans.pb(s.substr(beg, len));
	}
	return ans;
}

inline void addMessage() {
	string s = getLn();	
	vector<string> v = parseToWords(s);	
	Message res;
	int beg = 0;
	if (s[0] == '?') {
		res.F = -1;
	} else {
		res.F = findString(v[0]);
		beg++;
	}
	for (int i = beg; i < sz(v); i++) {
		res.S.pb(findString(v[i]));
	}
	messages.pb(res);
	messageStrs.pb(s);
}

inline bool canItBe(int pos, int usr) {
	for (int i = 0; i < sz(messages[pos].S); i++) {
		if (messages[pos].S[i] == usr) {
			return false;
		}
	}
	if (messages[pos].F >= 0) {
		return messages[pos].F == usr;
	}	
	return true;
}

int dp[500][500];

inline void restore(int i, int j) {
	if (i < 0) {
		return;
	}
	if (messages[i].F < 0) {
		messageStrs[i].erase(0, 1);
		messageStrs[i] = users[j] + messageStrs[i];
	}
	restore(i-1, dp[i][j]);
}

inline void newChat() {
	n = get<int>();
	users = getVector<string>(n);
	m = get<int>();
	messages.clear();
	messageStrs.clear();
	getLn();
	for (int i = 0; i < m; i++) {
		addMessage();
	}
	for (int i = 0; i < n; i++) {
		dp[0][i] = canItBe(0, i) ? 0 : -1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (canItBe(i, j)) {
				dp[i][j] = -1;
				for (int k = 0; k < n; k++) {
					if (j != k && dp[i-1][k] >= 0) {
						dp[i][j] = k;
					}
				}
			} else {
				dp[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[m-1][i] >= 0) {
			restore(m-1, i);
			for (int j = 0; j < sz(messageStrs); j++) {
				putLn(messageStrs[j]);
			}
			return;
		}
	}
	putLn("Impossible");
}

signed main() {
	for (int i = 0; i < t; i++) {
		newChat();
	}	
	return 0;
}