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
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
const ld INF = (ld)10000000000000;
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
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<vector<int>> v(n + m+3), u(n + m + 3);
	rep(i, n) {
		rep(j, m) {
			int a; cin >> a;
			v[i + j].push_back(a);
			//cout << i + j << "?" << a << endl;
		}
	}
	rep(i, n) {
		rep(j, m) {
			int b; cin >> b;
			u[i + j].push_back(b);
			//cout << i + j << "?" << b << endl;
		}
	}
	bool f = true;
	rep(i, n + m + 3) {
		sort(v[i].begin(), v[i].end());
		sort(u[i].begin(), u[i].end());
		if (v[i] != u[i])f = false;
	}
	if (f)cout << "YES" << endl;
	else cout << "NO" << endl;
	//stop
	return 0;
}