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
const ll INF = mod*mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void solve() {
	int n; cin >> n;
	vector<ll> s(n);
	vector<ll> dif(n - 1);
	rep(i, n) {
		cin >> s[i];
	}
	sort(s.begin(), s.end());
	rep(i, n - 1) {
		dif[i] = s[i + 1] - s[i];
	}
	sort(dif.begin(), dif.end());

	vector<LP> v;
	int q; cin >> q;
	vector<ll> ans(q);
	rep(i, q) {
		ll l, r; cin >> l >> r;
		r = r - l + 1;
		v.push_back({ r,i });
	}
	sort(v.begin(), v.end());

	int le = 0; ll sum = 0; ll loc = 0;
	rep(i, v.size()) {
		while (le<n-1&&dif[le] < v[i].first) {
			sum += (n - le)*(dif[le] - loc);
			loc = dif[le]; le++;
		}
		ans[v[i].second] = sum+(v[i].first-loc)*(n-le);
	}
	rep(i, q) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}