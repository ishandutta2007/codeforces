#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int calc(ll acnum, ll num) {
	if (acnum * 32 <= num) {
		return 3000;
	}
	else if (acnum * 16 <= num)return 2500;
	else if (acnum * 8 <= num)return 2000;
	else if (acnum * 4 <= num)return 1500;
	else if (acnum * 2 <= num)return 1000;
	else return 500;
}
int a[120][5];
void solve(){
	int n; cin >> n;
	rep(i, n) {
		rep(j, 5) {
			cin >> a[i][j];
		}
	}
	vector<int> ac(5);
	rep(i, n)rep(j, 5) {
		if (a[i][j] >= 0)ac[j]++;
	}
	
	vector<int> t;
	t.push_back(0);
	rep(j, 5)if (a[0][j] < 0 && a[1][j] >= 0) {
		for (int s = 2; s <= 32; s *= 2) {
			if (ac[j] * s > n) {
				t.push_back(ac[j] * s - n);
			}
		}
	}
	t.push_back(mod+1);
	sort(all(t));
	t.erase(unique(all(t)), t.end());
	
	auto canwin = [&](int x)->bool {
		int num = x + n;
		int s0 = 0, s1 = 0;
		rep(j, 5) {
			if (a[0][j] < 0) {
				if (a[1][j] >= 0) {
					int acnum = ac[j];
					int maxscore = calc(acnum, num);
					maxscore -= a[1][j] * maxscore / 250;
					s1 += maxscore;
				}
				else {
					//
				}
			}
			else {
				if (a[1][j] < 0) {
					int acnum = ac[j];
					int maxscore = calc(acnum, num);
					maxscore -= a[0][j] * maxscore / 250;
					s0 += maxscore;
				}
				else {
					if (a[0][j] == a[1][j]) {
						//
					}
					else if (a[0][j] < a[1][j]) {
						int acnum = ac[j];
						int maxscore = calc(acnum, num);
						int score = maxscore - a[0][j] * maxscore / 250;
						s0 += score;
						score = maxscore - a[1][j] * maxscore / 250;
						s1 += score;
					}
					else {
						int acnum = ac[j] + x;
						int maxscore = calc(acnum, num);
						int score = maxscore - a[0][j] * maxscore / 250;
						s0 += score;
						score = maxscore - a[1][j] * maxscore / 250;
						s1 += score;
					}
				}
			}
		}
		//cout << s0 << " " << s1 << "\n";
		return s0 > s1;
	};
	//cout<<canwin(3)<<"\n";
	int ans = -1;
	rep(i, t.size() - 1) {
		int le = t[i], ri = t[i + 1];
		while (ri - le > 1) {
			int m = (le + ri) / 2;
			//cout << m << " ? " << canwin(m) << "\n";
			if (canwin(m)) {
				ri = m;
			}
			else {
				le = m;
			}
		}
		if (canwin(le)) {
			ans = le; break;
		}
		else if (canwin(ri)) {
			ans = ri; break;
		}
	}
	cout << ans << "\n";
	
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
//	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}