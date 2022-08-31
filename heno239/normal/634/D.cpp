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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;


void solve() {
	int d, n, m; cin >> d >> n >> m;
	vector<P> v(m);
	rep(i, m) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	if (v[0].first > n) {
		cout << -1 << endl; return;
	}
	if (d - v.back().first > n) {
		cout << -1 << endl; return;
	}
	rep(i, m - 1) {
		if (v[i + 1].first - v[i].first > n) {
			cout << -1 << endl; return;
		}
	}
	if (d <= n) {
		cout << 0 << endl; return;
	}
	priority_queue<LP,vector<LP>,greater<LP>> q;
	ll ans = 0;
	ll dec = 0;
	int le = 0;
	while (le < m&&v[le].first <= n) {
		q.push({ v[le].second,v[le].first }); le++;
	}
	ll cur = n;
	while (le < m) {
		ll dif = v[le].first - cur;
		while (dif > 0) {
			LP p = q.top(); q.pop();
			ll num = p.second - dec;
			if (num <= 0)continue;
			ll mi = min(num, dif);
			dif -= mi; ans += p.first*mi;
			dec += mi;
			if (p.second-dec > 0)q.push(p);
		}
		cur = v[le].first;
		q.push({ v[le].second,n+dec });
		le++;
	}
	ll dif = d - cur;
	while (dif > 0) {
		LP p = q.top(); q.pop();
		ll num = p.second - dec;
		if (num <= 0)continue;
		ll mi = min(num, dif);
		dif -= mi; ans += p.first*mi;
		dec += mi;
		if (p.second-dec > 0)q.push(p);
	}
	cout << ans << endl;
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