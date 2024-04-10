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

string s;

const int sz = 200000;
const int b = 2000;

ll ans = 0;
void calc(int l, int r) {
	//if (r == l)return;
	if (r - l+1 <= b)return;
	int m = (l + r) / 2;
	calc(l, m); calc(m + 1, r);
	vector<P> vl, vr;
	int c = 0;
	for (int i = m; i >= l; i--) {
		if (s[i] == '1')c++;
		vl.push_back({ m - i + 1,c });
	}
	c = 0;
	for (int i = m + 1; i <= r; i++) {
		if (s[i] == '1')c++;
		vr.push_back({ i - m,c });
	}
	for (int n = 1; n <= min(200000/b, r - l + 1); n++) {
		vector<P> v;
		rep(i, vl.size()) {
			int s = n * vl[i].second - vl[i].first;
			v.push_back({ s,vl[i].second });
		}
		sort(v.begin(), v.end());
		rep(i, vr.size()) {
			int s = vr[i].first - vr[i].second*n;
			int rest = b+1 - vr[i].second;
			int num = lower_bound(v.begin(), v.end(), P{ s,mod }) - lower_bound(v.begin(), v.end(), P{ s,rest });
			ans += num;
		}
	}
}
void solve() {
	cin >> s;
	int n = s.size();
	calc(0, n - 1);
	//cout << ans << endl;
	vector<int> ones;
	rep(i, n)if (s[i] == '1')ones.push_back(i);
	int len = ones.size();
	rep1(i, min(len, b)) {
		rep(j, len - i + 1) {
			int num = ones[j + i - 1] - ones[j] + 1;
			int le;
			if (j == 0)le = ones[j];
			else le = ones[j] - ones[j - 1] - 1;
			int ri;
			if (j + i == len)ri = n - 1 - ones[j + i - 1];
			else ri = ones[j + i] - ones[j + i - 1] - 1;
			//cout << i << " " << j << " " << le << " " << ri << endl;
			int z = num;
			if (z >= i)z %= i;
			for (int k = 0; k <= le; k++) {
				int s =z; if (s > 0)s = i - s;
				if (s <= ri) {
					ans += (ri - s) / i + 1;
				}
				z++;
				if (z == i)z = 0;
			
			}
		}
		//cout << i << " " << ans << endl;
	}
	cout << ans << endl;
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