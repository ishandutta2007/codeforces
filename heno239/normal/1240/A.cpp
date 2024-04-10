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
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;
const ld pi = acos(-1.0);

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	int n; cin >> n;
	vector<ll> p(n);
	rep(i, n) {
		cin >> p[i];
	}
	sort(p.begin(), p.end(), greater<ll>());
	ll x, a; cin >> x >> a;
	ll y, b; cin >> y >> b;
	if (x < y) {
		swap(x, y);
		swap(a, b);
	}
	ll k; cin >> k;
	int le = 0, ri = n + 1;
	while (ri - le > 1) {
		int m = (le + ri) / 2;
		/*vector<ll> u(m);
		rep(i, m)u[i] = p[i];
		sort(u.begin())*/
		ll g = gcd(a, b);
		ll cab = m / (a*b/g);
		ll ca = m / a - cab; ll cb = m / b - cab;
		ll sum = 0;
		rep(i, cab) {
			sum += (p[i] / 100)*(x + y);
		}
		rep(i, ca) {
			sum += (p[i + cab] / 100)*x;
		}
		rep(i, cb) {
			sum += (p[i + cab + ca] / 100)*y;
		}
		if (sum >= k)ri = m;
		else le = m;
	}
	//cout << "ans is ";
	if (ri == n + 1) {
		cout << -1 << endl;
	}
	else {
		cout << ri << endl;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(50);
	//init();
	int q; cin >> q;
	rep(i, q) {
		solve();
	}

	//cout << "finish" << endl;
	//stop
		return 0;
}