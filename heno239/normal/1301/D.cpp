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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

void solve() {
	ll n, m, k; cin >> n >> m >> k;
	ll sup = 4 * n*m - 2 * n - 2 * m;
	if (sup < k) {
		cout << "NO" << endl; return;
	}
	vector<pair<ll, char>> v;
	rep(i, m - 1) {
		if (n > 1) {
			v.push_back({ n - 1,'D' });
			v.push_back({ n - 1,'U' });
		}
		v.push_back({ 1,'R' });
	}
	if (n > 1) {
		v.push_back({ n - 1,'D' });
	}
	rep(i, n - 1) {
		if (m > 1) {
			v.push_back({ m - 1,'L' });
			v.push_back({ m - 1,'R' });
		}
		v.push_back({ 1,'U' });
	}
	if (m > 1) {
		v.push_back({ m - 1,'L' });
	}
	ll sum = 0; rep(i, v.size())sum += v[i].first;
	//cout << sum << " " << sup << endl;
	ll rest = k;
	rep(i, v.size()) {
		if (v[i].first < rest) {
			rest -= v[i].first;
		}
		else {
			v[i].first = rest;
			v.resize(i + 1); break;
		}
	}
	cout << "YES" << endl;
	cout << v.size() << endl;
	rep(i, v.size()) {
		
		cout << v[i].first << " " << v[i].second << endl;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	stop
		return 0;
}