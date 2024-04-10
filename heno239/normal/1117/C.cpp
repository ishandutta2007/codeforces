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
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
ll x[2], y[2];
int n; string s;
//U,D,L,R

vector<int> v;

int ax[1 << 17], ay[1 << 17];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	rep(i, 2) {
		cin >> x[i] >> y[i];
	}
	cin >> n >> s;
	ax[0] = ay[0] = 0;
	rep(i, n) {
		ax[i + 1] = ax[i], ay[i + 1] = ay[i];
		if (s[i] == 'U') {
			if (y[0] < y[1])v.push_back(i);
			ay[i + 1]++;
		}
		else if (s[i] == 'D') {
			if (y[1] < y[0])v.push_back(i);
			ay[i + 1]--;
		}
		else if (s[i] == 'R') {
			if (x[0] < x[1])v.push_back(i);
			ax[i + 1]++;
		}
		else{
			if (x[0] > x[1])v.push_back(i);
			ax[i + 1]--;
		}
	}
	ll z = abs(x[1] - x[0]) + abs(y[1] - y[0]);
	ll le = -1, ri = INF;
	while (ri - le > 1) {
		ll mid = (ri + le) / 2;
		//cout << mid << " ";
		ll d = mid / n, r = mid % n;
		ll cx = x[0]+d * ax[n], cy = y[0]+d * ay[n];
		cx += ax[r], cy += ay[r];
		ll q = abs(cx - x[1]) + abs(cy - y[1]);
		//cout << q << endl;
		if (q <= mid)ri = mid;
		else le = mid;
	}
	if (ri == INF)ri = -1;
	cout << ri << endl;
	//stop
	return 0;
}