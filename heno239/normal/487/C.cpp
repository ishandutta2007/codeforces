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
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;



ll mod_pow(ll x, ll n, ll p) {
	ll ret = 1;
	while (n) {
		if (n % 2)ret = ret * x%p;
		x = x * x%p; n >>= 1;
	}
	return ret;
}
bool isp(int x) {
	vector<int> v;
	rep1(i, 1000) {
		if (x%i == 0) {
			v.push_back(i);
			v.push_back(x / i);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());
	return v.size() == 2;
}
void solve() {
	int n; cin >> n;
	if (n == 1) {
		cout << "YES" << endl;
		cout << 1 << endl;
		return;
	}
	else if (n == 4) {
		cout << "YES" << endl;
		vector<int> ans = { 1,3,2,4 };
		rep(i, 4)cout << ans[i] << endl;
		return;
	}
	else if (!isp(n)) {
		cout << "NO" << endl; return;
	}
	else {
		vector<ll> ans;
		ans.push_back(1);
		for (int i = 1; i <= n - 2; i++) {
			ll s = i, t = mod_pow(i + 1, n - 2, n);
			ans.push_back(s*t%n);
		}
		ans.push_back(n);
		cout << "YES" << endl;
		rep(i, n) {
			cout << ans[i] << endl;
		}
	}
}

void sear(int n) {
	vector<int> v;
	Rep1(i, 2, n - 1)v.push_back(i);
	vector<int> b;
	rep(i, n)b.push_back(i);
	while (true) {
		vector<int> u;
		u.push_back(1);
		rep(i, v.size())u.push_back(v[i]);
		u.push_back(n);
		vector<int> nex;
		int r = 1;
		rep(i, n) {
			r = r * u[i] % n;
			nex.push_back(r);
		}
		sort(nex.begin(), nex.end());
		if (nex == b) {
			rep(i, n) {
				cout << u[i] << endl;
			}
			return;
		}
		if (!next_permutation(v.begin(), v.end()))break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//sear(9);
	solve();
	//stop
	return 0;
}