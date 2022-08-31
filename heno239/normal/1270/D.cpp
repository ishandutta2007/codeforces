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
typedef vector<ll> vec;

void debug(vec &v) {
	int n = v.size();
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
}

int n,l;
P query(vector<int> &v) {
	sort(v.begin(), v.end());
	cout << "?";
	rep(i, l) {
		cout << " " << v[i]+1;
	}
	cout << endl;
	int pos, val; cin >> pos >> val; pos--;
	return { pos,val };
}
void solve() {
	cin >> n >> l;
	vector<int> v;
	rep(i, l)v.push_back(i);
	P res = query(v);
	int k = res.first;
	int x = res.second;
	v.clear();
	rep(i, l + 1) {
		if (i == k)continue;
		v.push_back(i);
	}
	res = query(v);
	int k2 = res.first;
	int x2 = res.second;
	if (x > x2) {
		swap(x, x2);
		swap(k, k2);
	}
	v.clear();
	rep(i, l + 1) {
		if (i == k || i == k2)continue;
		v.push_back(i);
	}
	int le = 0;
	rep(i, l-1) {
		vector<int> u = v;
		u.erase(u.begin() + i);
		u.push_back(k); u.push_back(k2);
		res = query(u);
		if (res.second == x2) {
			le++;
		}
	}
	cout << "! "<<le + 1 << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}