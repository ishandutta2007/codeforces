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
#include<chrono>
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


struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> ri(n);

	vector<int> va;
	rep(i, n)va.push_back(a[i]);
	sort(all(va));
	va.erase(unique(all(va)), va.end());
	rep(i, n) {
		a[i] = lower_bound(all(va), a[i]) - va.begin();
	}
	vector<vector<int>> loc(va.size());
	rep(i, n) {
		loc[a[i]].push_back(i);
	}

	int ma = 0;
	//one
	rep(i, va.size()) {
		ma = max(ma, (int)loc[i].size());
	}
	//two
	per(i, n) {
		int val = a[i];
		if (val + 1 == va.size())continue;
		int id = lower_bound(all(loc[val + 1]), i) - loc[val + 1].begin();
		if (id == loc[val + 1].size())continue;
		int sum = loc[val + 1].size() - id;
		sum += lower_bound(all(loc[val]), i) - loc[val].begin();
		sum++;
		ma = max(ma, sum);
	}

	vector<int> ans(n,0);

	per(i, n) {
		int val = a[i];

		int num;
		//i is last
		num = lower_bound(all(loc[val]), i) - loc[val].begin();
		num = loc[val].size() - num;
		ans[i] = max(ans[i], num);


	    //i is mid
		if (val + 1 != va.size()) {
			int id = lower_bound(all(loc[val + 1]), i) - loc[val + 1].begin();
			if (id == 0) {
				int to = loc[val + 1][id];
				if (loc[val][0] == i && loc[val].back() < to) {
					ans[i] = max(ans[i], ans[to] + (int)loc[val].size());
				}
			}
			//to is last
			if (loc[val][0] == i) {
				int las = loc[val].back();
				int toid = lower_bound(all(loc[val + 1]), las) - loc[val + 1].begin();
				ans[i] = max(ans[i], (int)loc[val + 1].size() - toid + (int)loc[val].size());
			}
		}

		//i is first
		if (val + 1 != va.size()) {
			int id = lower_bound(all(loc[val + 1]), i) - loc[val + 1].begin();
			if (id == 0) {
				int to = loc[val + 1][id];
				num = lower_bound(all(loc[val]), i) - loc[val].begin();
				ma = max(ma, ans[to] + num+1);
			}
		}

	}

	
	cout << n - ma << "\n";
}



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(6);
	//init_f();
	//init();
	int t; cin >> t;rep(i,t)
	solve();
	stop
		return 0;
}