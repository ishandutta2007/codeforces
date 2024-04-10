#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 998244353
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vii;

//Printing pairs and vectors
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}

//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max

typedef std::decay<decltype(MOD)>::type mod_t;
struct mi {
    mod_t val;
    explicit operator mod_t() const { return val; }
    mi() { val = 0; }
    mi(const long long& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD; }
    friend std::istream& operator >> (std::istream& in, mi& a) {
        long long x; std::cin >> x; a = mi(x); return in; }
    friend std::ostream& operator << (std::ostream& os, const mi& a) { return os << a.val; }
    friend bool operator == (const mi& a, const mi& b) { return a.val == b.val; }
    friend bool operator != (const mi& a, const mi& b) { return !(a == b); }
    friend bool operator < (const mi& a, const mi& b) { return a.val < b.val; }
    friend bool operator > (const mi& a, const mi& b) { return a.val > b.val; }
    friend bool operator <= (const mi& a, const mi& b) { return a.val <= b.val; }
    friend bool operator >= (const mi& a, const mi& b) { return a.val >= b.val; }
    mi operator - () const { return mi(-val); }
    mi& operator += (const mi& m) {
        if ((val += m.val) >= MOD) val -= MOD;
        return *this; }
    mi& operator -= (const mi& m) {
        if ((val -= m.val) < 0) val += MOD;
        return *this; }
    mi& operator *= (const mi& m) { val = (long long) val * m.val % MOD;
        return *this; }
    friend mi pow(mi a, long long p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }
    mi& operator /= (const mi& m) { return (*this) *= inv(m); }
    friend mi operator + (mi a, const mi& b) { return a += b; }
    friend mi operator - (mi a, const mi& b) { return a -= b; }
    friend mi operator * (mi a, const mi& b) { return a *= b; }
    friend mi operator / (mi a, const mi& b) { return a /= b; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<mi> v(n);
	vector<bool> p(n);
	forn(i, n){
		char c;
		cin >> c;
		if(c == '+'){
			p[i] = true;
			cin >> v[i];
		}
	}

	mi ans = 0;
	vector<mi> dp(n);
	forn(i, n){
		if(!p[i]) continue;

		vector<mi> ways(n);
		ways[0] = 1;
		ll t2 = 0;
		forn(j, i){
			if(p[j] && v[j] <= v[i]){
				for(int k=n-2; k>=0; k--) ways[k+1] += ways[k];
			}
			if(p[j] && v[j] > v[i]){ t2++; }
			if(!p[j]){
				mi bef = ways[0];
				forn(k, n-1) ways[k] += ways[k+1];
				ways[0] += bef;
			}
		}
		for(int j=i+1; j<n; j++){
			if(p[j] && v[j] < v[i]){
				for(int k=n-2; k>=0; k--) ways[k+1] += ways[k];
			}
			if(p[j] && v[j] >= v[i]) t2++;
			if(!p[j]){
				forn(k, n-1) ways[k] += ways[k+1];
			}
		}
		// cout << ways << "\n";
		forn(j, n){
			ans += ways[j] * v[i] * pow((mi) 2, t2);
		}

		// if(p[i]){
		// 	for(int i=n-2; i>=0; i--){
		// 		dp[i+1] += dp[i];
		// 	}
		// 	dp[0] += v[i] * pow((mi) 2, i);
		// }else{
		// 	for(int i = 1; i<n; i++){
		// 		dp[i-1] += dp[i];
		// 	}
		// }
	}

	cout << ans << "\n";
}