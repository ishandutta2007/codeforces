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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

int x[666], y[666];
int nx, ny;
int mp[999][999];
void cantgo() {
	rep(i, 3) {
		rep(k, 3) {
			if (i == 1 && k == 1)continue;
			int cx = nx + i-1, cy = ny + k-1;
			if (cx < 0 || cy < 0 || cx >= 999 || cy >= 999)continue;
			if (mp[cx][cy])continue;
			rep(j, 666) {
				if (cx == x[j] || cy == y[j]) {
					cout << cx+1 << " " << cy+1 << endl;
					int t, l, r; cin >> t >> l >> r; return;
				}
			}
		}
	}
}
bool refl() {
	int t, l, r; cin >> t >> l >> r; t--; l--; r--;
	if (t < 0)return true;
	mp[x[t]][y[t]] = 0; mp[l][r] = 1;
	x[t] = l, y[t] = r;
	return false;
}
bool go_to_center() {
	while (true) {
		if (nx == 499 && ny == 499)return false;
		int dx = 0, dy = 0;
		if (nx > 499)dx = -1;
		else if (nx < 499)dx = 1;
		if (ny > 499)dy = -1;
		else if (ny < 499)dy = 1;
		int cx = nx + dx, cy = ny + dy;
		if (mp[cx][cy]) {
			cantgo(); return true;
		}
		cout << cx+1 << " " << cy+1 << endl;
		if (refl())return true;
		nx = cx, ny = cy;
	}
	return false;
}
void go_straight(int ex,int ey) {
	while (true) {
		int cx = nx+ex, cy = ny+ey;
		if (mp[cx][cy]) {
			cantgo(); return;
		}
		cout << cx+1 << " " << cy+1 << endl;
		if (refl())return;
		nx = cx; ny = cy;
	}
}
void solve() {
	if (go_to_center())return;
	int c[4] = {};
	rep(i, 666) {
		if (x[i] > 499 && y[i] > 499)c[0]++;
		else if (x[i] > 499 && y[i] < 499)c[1]++;
		else if (x[i] < 499 && y[i] < 499)c[2]++;
		else c[3]++;
	}
	if (c[0] + c[1] + c[3]>499) {
		go_straight(1, 1);
	}
	else if (c[1] + c[0] + c[2] > 499) {
		go_straight(1, -1);
	}
	else if (c[2] + c[1] + c[3] > 499) {
		go_straight(-1, -1);
	}
	else {
		go_straight(-1, 1);
	}
}
int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> nx >> ny; nx--; ny--;
	rep(i, 666) {
		cin >> x[i] >> y[i]; x[i]--; y[i]--;
		mp[x[i]][y[i]] = 1;
	}
	solve();
	//stop
	return 0;
}