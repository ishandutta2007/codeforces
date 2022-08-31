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
const ll mod = 1000000087;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int ma = 0;
	rep(i, n) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	bool fin = false;
	rep(i, n) {
		if ((ma - 1) / 2 >= a[i])fin = true;
	}
	if (!fin) {
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << -1;
		}
		cout << endl;
		return;
	}


	set<int> pre;
	pre.insert(mod);
	set<int> rest;

	rep(i, 2 * n) {
		rest.insert(i);
	}
	rest.insert(mod);
	vector<int> ans(n);
	vector<P> v;
	rep(i, n) {
		v.push_back({ a[i],i });
	}
	sort(v.begin(), v.end(), greater<P>());
	int le = 0;
	rep(i, v.size()) {
		while (le < n && (v[i].first - 1) / 2 < v[le].first) {
			rest.erase(v[le].second);
			rest.erase(v[le].second + n);
			le++;
		}
		int id = v[i].second;
		pre.insert(id);
		auto itr = pre.find(id);
		itr++;
		int np = *itr;
		//pre.erase(id);
		rest.insert(id);
		auto itr2 = rest.find(id);
		itr2++;
		int nr = *itr2;
		rest.erase(id);
		//cout << id << " " << np << " " << nr << endl;
		if (np < nr) {
			ans[id] = ans[np%n] + np - id;
		}
		else {
			ans[id] = nr - id;
		}
		pre.insert(id + n);
	}
	rep(i, n) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init();
	solve();
	//stop
	return 0;
}