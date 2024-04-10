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
#include<array>
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
const ld eps = 1e-8;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (x >= m)x %= m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}

//x,yax+by=gcd(a,b)
ll extgcd(ll a, ll b, ll& x, ll& y) {
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}
//amod m
ll mod_inverse(ll a, ll m) {
	a %= m;
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}
ll rev(ll r1, ll r2, ll m1, ll m2) {
	ll b = (r2 - r1) * mod_inverse(m1, m2);
	b = (b % m2 + m2) % m2;
	return (r1 + b * m1) % (m1 * m2);
}

void solve() {
	int n; ll p; int l, r; cin >> n >> p >> l >> r;
	ll memo = p;
	if (p == 1) {
		cout << 0 << "\n"; return;
	}
	vector<LP> ms;
	for (ll i = 2; i * i <= p; i++) {
		if (p % i == 0) {
			int cnt = 0;
			while (p % i == 0) {
				cnt++; p /= i;
			}
			ms.push_back({ i,cnt });
		}
	}
	if (p > 1) {
		ms.push_back({ p,1 });
	}
	vector<ll> ps;
	rep(j, ms.size()) {
		ll z = 1; rep(i, ms[j].second)z *= ms[j].first;
		ps.push_back(z);
	}
	vector<vector<LP>> facts(ms.size(), vector<LP>(n + 1));
	rep(i, ms.size()){
		facts[i][0] = { 1,0 };
		rep1(j, n) {
			facts[i][j] = facts[i][j - 1];
			int cop = j;
			while (cop % ms[i].first == 0) {
				facts[i][j].second++;
				cop /= ms[i].first;
			}
			(facts[i][j].first *= cop) %= ps[i];
		}
	}
	//n!/i!j!(n-i-j)!
	auto calcid = [&](int id, int n, int i, int j)->ll {
		int c = facts[id][n].second - facts[id][i].second - facts[id][j].second - facts[id][n - i - j].second;
		c = min(c, (int)ms[id].second);
		ll s = facts[id][n].first;
		(s *= mod_inverse(facts[id][i].first, ps[id]))%=ps[id];
		(s *= mod_inverse(facts[id][j].first, ps[id]))%=ps[id];
		(s *= mod_inverse(facts[id][n-i-j].first, ps[id]))%=ps[id];
		rep(i, c) {
			(s *= ms[id].first) %= ps[id];
		}
		//cout << s << "\n";
		return s;
	};
	auto calcall = [&](int n, int i, int j)->ll {
		ll res = 0; ll pp = 1;
		rep(k, ms.size()) {
			ll r = calcid(k, n, i, j);
			res = rev(res, r, pp, ps[k]);
			pp *= ps[k]; 
			//cout << "?? "<<res<<" "<<pp << "\n";
		}
		//cout << i << " " << j << " " << res << "\n";
		return res;
	};
	auto calc = [&](int x)->ll {
		if (x > n)return 0;
		ll res = 0;
		rep(i, n + 1) {
			int c = (x + n - i);
			if (c % 2)continue;
			int j = c / 2;
			if (j<0 || i + j>n)continue;
			res += calcall(n, i, j);
		}
		res %= memo;
		return res;
	};
	//cout << calc(0) << " " << calc(1) << "\n";
	ll ans = calc(l) + calc(l + 1) - calc(r+1) - calc(r + 2);
	ans = (ans % memo + memo) % memo;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}