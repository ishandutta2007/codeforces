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
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
//#define revstr(s) reverse(s.begin(),s.end())
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef unsigned long long ul;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(18);
	ld x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ld gx = x2 - x1, gy = y2 - y1;
	ld the1 = atan2(y2 - y1, x2 - x1);
	ld dis = sqrt((pow(y2 - y1, 2) + pow((x2 - x1), 2)));
	ld vm, t; cin >> vm >> t;
	ld v[2];
	ld wx[2], wy[2];
	rep(aa, 2) {
		cin >> wx[aa] >> wy[aa];
		ld vx = wx[aa], vy = wy[aa];
		ld the2 = atan2(vy, vx);
		ld d2 = sqrt((pow(vy, 2) + pow(vx, 2)));
		v[aa] = d2 * cos(the1 - the2) + sqrt(pow(d2, 2)*(pow(cos(the1 - the2), 2) - 1) + pow(vm, 2));
	}
	ld out = INF;

	if (dis < t*v[0]) {
		out = dis / v[0];
	}
	else {
		ld a2 = pow(vm, 2) - (pow(wx[1], 2) + pow(wy[1], 2));
		ld a1 = 0;
		a1 += 2 * wx[1] * (gx - t * (wx[0] - wx[1]));
		a1 += 2 * wy[1] * (gy - t * (wy[0] - wy[1]));

		ld a0 = 0;
		a0 -= pow(gx - t * (wx[0] - wx[1]), 2);
		a0 -= pow(gy - t * (wy[0] - wy[1]), 2);
		out = (-a1 + sqrt(a1*a1 - 4 * a0*a2)) / (2 * a2);
	}
	cout << out << endl;
	return 0;
}