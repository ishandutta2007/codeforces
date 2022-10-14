#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
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

	ll n;
	cin >> n;
	vector<ll> c(n), b(n);
	int MV = 5;
	forn(i, n){
		cin >> c[i];
		MV += c[i]+1;
	}
	forn(i, n-1){
		cin >> b[i+1];
	}
	vector<ll> prefb(n), ppb(n);
	forn(i, n-1){
		prefb[i+1] = prefb[i] + b[i+1];
	}
	forn(i, n-1){
		ppb[i+1] = ppb[i] + prefb[i+1];
	}

	int q;
	cin >> q;
	vector<ll> qu(q);
	forn(i, q){
		cin >> qu[i];
	}

	vector<mi> ways(n+1);
	ways[n] = 1;
	for(int i=n-1; i>=0; i--){
		ways[i] = (c[i]+1)*ways[i+1];
	}

	mi ans = 0;

	vector<vector<mi>> dp(n, vector<mi>(MV));
	forn(j, c[0]+1){
		if(j < qu[0]){
			ans += ways[1];
		}
		else{
			dp[0][j] = 1;
		}
	}
	for(ll i=1; i<n; i++){
		for(ll j = 0; j<MV; j++){
			for(ll v=0; v <= c[i]; v++){
				if(j < v) continue;

				if(j-ppb[i] < qu[0]*(i+1)){
					ans += dp[i-1][j-v] * ways[i+1];
				}else{
					dp[i][j] += dp[i-1][j-v];
				}

				// if((j-v-ppb[i-1]) >= (v-prefb[i])*i){	//condition met
				// 	dp[i][j] += dp[i-1][j-v];
				// }else{
				// 	if((j-v-ppb[i-1]) >= qu[0]*i) ans += dp[i-1][j-v] * ways[i+1];
				// }
			}
		}
	}
	// forn(j, MV){
	// 	if(j-ppb[n-1] >= qu[0]*n) ans += dp[n-1][j];
	// }
	// cout << dp << "\n";
	cout << ways[0] - ans << "\n";


	// assert(n == 3);
	// int nans = 0;
	// for(int a0 = 0; a0 <= c[0]; a0++){
	// 	for(int a1 = 0; a1 <= c[1]; a1++){
	// 		for(int a2 = 0; a2 <= c[2]; a2++){
	// 			lld x = a0 - prefb[0], y = a1 - prefb[1], z = a2 - prefb[2];
	// 			lld X = x, Y = (x+y)/2, Z = (x+y+z)/3;
	// 			auto f = [&](){
	// 				if(X < y){
	// 					return X;
	// 				}
	// 				if(Y < z){
	// 					return Y;
	// 				}
	// 				return Z;
	// 			};
	// 			if(f() > qu[0] - 1e-9){
	// 				nans++;
	// 			}
	// 		}
	// 	}
	// }
	// cout << nans << "\n";
}