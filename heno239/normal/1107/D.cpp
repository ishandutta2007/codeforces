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
const ll mod = 998244353;
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
const ld eps = 1e-9;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int n;
int c[5200][5200];
int sum[5200][5200];
void init() {
	rep(i, n) {
		rep(j, n) {
			sum[i][j] = c[i][j];
			if (i > 0) {
				sum[i][j] += sum[i - 1][j];
			}
			if (j > 0) {
				sum[i][j] += sum[i][j - 1];
			}
			if (i > 0 && j > 0) {
				sum[i][j] -= sum[i - 1][j - 1];
			}
		}
	}
}
int calc(int lx, int ly,int rx,int ry) {
	int res = sum[rx][ry];
	if (lx > 0) {
		res -= sum[lx - 1][ry];
	}
	if (ly > 0) {
		res -= sum[rx][ly - 1];
	}
	if (lx > 0 && ly > 0) {
		res += sum[lx - 1][ly - 1];
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n) {
		rep(j, n / 4) {
			char t; cin >> t;
			int x;
			if ('0' <= t && t <= '9') {
				x = t - '0';
			}
			else x = 10 + (t - 'A');
			per(k, 4) {
				int z = 1 << k;
				if(x&z)c[i][4 * j + 3 - k] = 1;
				x %= z;
			}
		}
	}
	init();
	int out = 0;
	rep1(i, n) {
		if (n%i != 0)continue;
		bool f = true;
		int d = n / i;
		rep(j, d) {
			rep(k, d) {
				int lx = i * j,ly=i*k;
				int rx = i * (j + 1) - 1, ry = i * (k + 1) - 1;
				int cc = calc(lx, ly, rx, ry);
				if (cc != 0 && cc != i*i)f = false;
			}
		}
		if (f)out = i;
	}
	cout << out << endl;
	//stop
	return 0;
}