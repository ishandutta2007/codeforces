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
const ll mod = (1e+9) + 7;
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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
//3RE
LDP cent(LDP a[3]) {
	ld x[2], y[2];
	rep(i, 2) {
		x[i] = a[i + 1].first - a[0].first;
		y[i] = a[i + 1].second - a[0].second;
	}
	ld bunbo = 2 * (x[0]*y[1] - y[0] * x[1]);
	ld cx = (x[0] * x[0] * y[1] + y[0] * y[0] * y[1] - y[0] * x[1] * x[1] - y[0] * y[1] * y[1]) / bunbo;
	ld cy = (x[0] * x[1] * x[1] + x[0] * y[1] * y[1] - x[0] * x[0] * x[1] - y[0] * y[0] * x[1]) / bunbo;
	return { cx+a[0].first,cy+a[0].second };
}
LDP z[3];
int main() {
	cout << fixed << setprecision(7);
	ld x[4], y[4];
	rep(i, 3) {
		cin >> x[i] >> y[i];
	}
	rep1(i, 2) {
		x[i] -= x[0]; y[i] -= y[0];
	}
	x[0] = x[3]=0; y[0] =y[3]= 0;
	rep(i, 3) {
		z[i] = { x[i],y[i] };
	}
	LDP c = cent(z);
	ld cx = c.first; ld cy = c.second;
	//cout << cx << " " << cy << endl;
	ld r = sqrt(cx*cx + cy * cy);
	ld ang[3];
	rep(i, 3) {
		ld d = sqrt(pow(x[i + 1] - x[i], 2) + pow(y[i + 1] - y[i], 2));
		ang[i] = acos(1 - d * d / (2 * r*r));
	}
	for (ld i = 3; i <= 100;i++) {
		ld uni = 2 * pi / i;
		bool f = true;
		rep(j, 3) {
			ld t = ang[j] / uni;
			int zz = (t + eps);
			if (abs(t - (ld)zz) > eps)f = false;
		}
		if (f) {
			//cout << i << endl;
			ld out = (i / 2.0)*r*r*sin(uni);
			cout << out << endl;
			break;
		}
	}
	return 0;
}