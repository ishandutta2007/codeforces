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
#include<cassert>
using namespace std;

typedef long long  ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
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
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
typedef vector<int> vec;

void solve() {
	int n, x; cin >> n >> x;
	int b = 0;
	if (x >= (1 << n)) {
		b = -1;
	}
	else {
		rep(i, 18) {
			if (x&(1 << i)) {
				b = i; break;
			}
		}
	}
	vector<int> c;
	rep(i, n) {
		if (i == b)continue;
		c.push_back(1 << i);
	}
	vector<int> ans;

	rep(i, c.size()) {
		int len = ans.size();
		ans.push_back(c[i]);
		rep(i, len)ans.push_back(ans[i]);
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
	//cout << fixed << setprecision(5);
	//while (cin >> w>>h>>n,n)solve();
	solve();
	//stop
	return 0;
}