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
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<int> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}

ll mod_pow(ll x, ll n) {
	ll ret = 1;
	while (n > 0) {
		if (n % 2)ret = ret * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return ret;
}

char query(int x,int y) {
	cout << "? " << x << " " << y << endl;
	char in; cin >> in;
	return in;
}

void solve() {
	string s; cin >> s;
	vector<int> v; v.push_back(0);
	rep(i, 30)v.push_back(1 << i);
	while (s == "start") {
		int le, ri;
		bool bl = false;
		rep(i, 30) {
			le = v[i], ri = v[i + 1];
			char z = query(le, ri);
			if (z == 'x') {
				bl = true;
				break;
			}
		}
		if (!bl) {
			le = (1 << 29), ri = (1 << 30);
		}
		while (ri - le > 1) {
			int mid = (le + ri) / 2;
			int z = query(le, mid);
			if (z == 'x') {
				ri = mid;
			}
			else {
				le = mid;
			}
		}
		cout << "! " << ri << endl;
		cin >> s;
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(17);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//stop
		return 0;
}