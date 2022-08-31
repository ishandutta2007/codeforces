#include<iostream>
#include<cstdio>
#include<string>
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
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
const double EPS = 1e-9;
typedef pair<int,int> P;
typedef unsigned int ui;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int d[100001] = {}; int a[100001] = {};
int main() {
	int n, m; cin >> n >> m;
	int sum = 0;
	rep(i, n) {
		cin >> a[i];
	}
	d[0] = a[0]; sum = a[0];
	Rep(i, 1, n) {
		if (i % 2) {
			d[i] = d[i - 1];
		}
		else {
			d[i] = d[i - 1] + (a[i] - a[i - 1]);
			sum += a[i] - a[i - 1];
		}
	}
	if (n % 2 == 0) {
		sum += m - a[n - 1];
		d[n] = d[n - 1] + (m - a[n - 1]);
	}
	else {
		d[n] = d[n - 1];
	}
	int ma = sum;
	rep(i, n) {
		int x = sum - d[i];
		int y = m - a[i];
		int t = y - x;
		if (a[i] - a[i - 1] == 1)continue;
		if (i % 2 == 0) {
			ma = max(ma, d[i] - 1 + t);
		}
		else {
			ma = max(ma, d[i] + (a[i] - a[i - 1] - 1) + t);
		}
	}
	if (n % 2&&m-a[n-1]>1) {
		ma = max(ma, d[n] + (m - a[n - 1] - 1));
	}
	cout << ma << endl;
	return 0;
}