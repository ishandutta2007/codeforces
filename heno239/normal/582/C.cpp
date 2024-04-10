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

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}

vector<int> divisor(int x) {
	vector<int> ret;
	rep1(i, 1000) {
		if (x%i == 0) {
			ret.push_back(i);
			ret.push_back(x / i);
		}
	}
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

bool allsame(vector<int> &a) {
	rep(i, (int)a.size() - 1) {
		if (a[i] != a[i + 1])return false;
	}
	return true;
}
void solve() {
	int n; cin >> n;
	vector<int> a(n); rep(i, n)cin >> a[i];
	if (allsame(a)) {
		ll ans = (ll)n*(n - 1);
		cout << ans << endl; return;
	}
	vector<int> d = divisor(n); d.pop_back();
	ll ans = 0;
	rep(i, d.size()) {
		//cout << ans << endl;
		vector<int> non;
		int k = d[i];
		vector<int> ma(k, 0);
		rep(j, n) {
			ma[j%k] = max(ma[j%k], a[j]);
		}
		rep(j, n) {
			if (ma[j%k] != a[j])non.push_back(j);
		}
		int sz = non.size(); rep(j, sz)non.push_back(non[j] + n);
		int u = n / k;
		vector<bool> p(u,true);
		rep(j, d.size()) {
			if (u%d[j]||d[j]==1)continue;
			for (int l = d[j]; l < u; l += d[j])p[l] = false;
		}
		/*rep1(j, u - 1) {
		if (gcd(j, u) == 1)p[j] = true;
		}*/
		vector<int> rc(u, 0);
		rep(j, u - 1) {
			rc[j + 1] += rc[j];
			if (p[j + 1])rc[j + 1]++;
		}

		if (non.empty()) {
			ans += (ll)n*rc[u - 1]; continue;
		}
		int le = 0;
		rep(j, n) {
			if (j > non[le])le++;
			if (j == non[le])continue;
			int dif = non[le] - j;
			dif /= k;
			ans += rc[dif];
		}
	}

	cout << ans << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}