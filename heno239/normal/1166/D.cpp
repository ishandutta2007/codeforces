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

void solve() {
	int q; cin >> q;
	rep(aa, q) {
		ll a, b, m; cin >> a >> b >> m;
		vector<ll> v; v.push_back(a);
		ll cur = a+1;
		while (cur <= b) {
			v.push_back(cur);
			cur *= 2;
		}
		ll dif = b - v.back();
		int len = v.size();
		vector<ll> ad(len - 1);
		for (ll i = len - 1; i >= 1; i--) {
			int id = len - 1 - i;
			int j = i - 2; if (j < 0)j = 0;
			ll s = (ll)1 << j;
			ll d = dif / s; d = min(d, m - 1);
			ad[id] += d; dif -= d * s;
		}
		vector<ll> ans; ans.push_back(a);
		ll sum = a;
		rep(i, len - 1) {
			ll nex = sum + ad[i] + 1;
			ans.push_back(nex); sum += nex;
			//cout << nex << endl;
		}
		if (ans.back() == b) {
			cout << ans.size();
			rep(i, ans.size()) {
				cout << " " << ans[i];
			}
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}