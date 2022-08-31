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
typedef pair<int, int>P;
typedef pair<int, bool> sP;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

ll calc2(vector<LP> &v, ll x) {
	ll res = 0;
	rep(i, v.size()) {
		ll dif = abs(v[i].first - x)*v[i].second;
		res += dif;
	}
	return res;
}
ll calc(vector<LP> &v, ll d) {
	ll sum = 0;
	ll x = 0;

	rep(i, v.size()) {
		sum += v[i].first*v[i].second;
	}
	ll le = sum / d; ll ri = le + 1;
	return min(calc2(v, le), calc2(v, ri));
}
void solve() {
	int n; cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	rep(i, n) {
		cin >> a[i]; sum += a[i];
	}
	if (sum == 1) {
		cout << -1 << endl; return;
	}
	vector<ll> ps;
	for (int i = 2; i <= 1000000; i++) {
		if (sum%i == 0) {
			ps.push_back(i);
			while (sum%i == 0)sum /= i;
		}
	}
	if (sum > 1)ps.push_back(sum);
	ll ans = INF;
	rep(j, ps.size()) {
		ll d = ps[j];
		vector<LP> v;
		ll s = 0;
		ll csum = 0;
		ll mid; ll dd = (1 + d) / 2;
		rep(i, n) {
			if (s + a[i] >= d) {
				if (s < dd)mid = i;
				ll dif = d - s;
				v.push_back({ i,dif });
				csum += calc2(v,mid);
				v.clear();
				ll rest = a[i] - dif;
				rest %= d;
				s = rest; v.push_back({ i,rest });
				if (s >= dd)mid = i;
			}
			else {
				if (s < dd&&s + a[i] >= dd)mid = i;
				s += a[i]; v.push_back({ i,a[i] });
			}
		}
		ans = min(ans, csum);
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(9);
	//init();
	solve();
	//stop
		return 0;
}