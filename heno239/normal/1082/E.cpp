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
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
const int mn = 500000;
int n, c;
int a[mn];
vector<int> v[mn];
int ans, cnt;
void calcmax(int id) {
	vector<int> u;
	rep(i,v[id].size()) {
		int nw = v[id][i];
		int to = lower_bound(v[c].begin(), v[c].end(), nw) - v[c].begin();
		int tto = 0;
		if (to == v[c].size()) {
			tto = v[id].size();
		}
		else {
			tto = lower_bound(v[id].begin(), v[id].end(), v[c][to]) - v[id].begin();
		}
		u.push_back(tto - i);
		i = tto - 1;
		if (i + 1 < v[id].size()) {
			int cc = lower_bound(v[c].begin(), v[c].end(), v[id][tto]) - v[c].begin();
			u.push_back(-(cc - to));
		}
	}
	int sum = 0; int mi = 0;
	rep(i, u.size()) {
		sum += u[i];
		mi = min(mi, sum);
		ans = max(ans, sum - mi + cnt);
		//cout << u[i] << endl;
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> c; c--;
	rep(i, n) {
		cin >> a[i]; a[i]--;
		v[a[i]].push_back(i);
		if (a[i] == c)cnt++;
	}
	ans = cnt;
	rep(i, mn) {
		if (i == c)continue;
		calcmax(i);
	}
	cout << ans << endl;
	return 0;
}