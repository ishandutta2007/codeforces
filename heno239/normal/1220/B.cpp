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
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int> P;
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
const ld eps = 1e-5;
const ld pi = acos(-1.0);

int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		int r = a % b; a = b; b = r;
	}
	return a;
}
int m[1000][1000];
void solve() {
	int n; cin >> n;
	rep(i, n) {
		rep(j, n) {
			cin >> m[i][j];
		}
	}
	int g = 0;
	rep1(i, n - 1) {
		g = gcd(g, m[i][0]);
	}
	vector<int> v;
	int k = sqrt(g + 0.1);
	rep1(i, k) {
		if (g%i == 0) {
			v.push_back(i);
			v.push_back(g / i);
		}
	}
	rep(i, v.size()) {
		vector<int> ans(n, 0);
		ans[0] = v[i];
		ans[1] = m[0][1] / v[i];
		ans[2] = m[0][2] / v[i];
		if ((ll)ans[1] * ans[2] == m[1][2]) {
			rep1(j, n - 1) {
				ans[j] = m[0][j] / v[i];
			}
			rep(j, n) {
				if (j > 0)cout << " ";
				cout << ans[j];
			}
			cout << endl;
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}