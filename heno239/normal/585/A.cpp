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
	int n; cin >> n;
	vector<ll> v(n), d(n), p(n);
	vector<bool> non(n, false);
	rep(i, n)cin >> v[i] >> d[i] >> p[i];
	//int ans = 0;
	vector<int> ans;
	rep(i, n) {
		if (non[i])continue;
		ans.push_back(i + 1);
		ll dec = v[i];
		ll addec = 0;
		for (int j = i + 1; j < n; j++) {
			if (non[j])continue;
			p[j] -= dec + addec; dec = max(dec - 1, (ll)0);
			if (p[j] < 0) {
				non[j] = true;
				addec += d[j];
			}
		}
		
	}
	cout << ans.size() << endl;
	rep(i, ans.size()) {
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