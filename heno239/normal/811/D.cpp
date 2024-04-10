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
const ld eps = 1e-4;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
int n, m;
char mp[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
char dc[4] = { 'R','D','L','U' };
int d[102][102];
typedef pair<int, P> speP;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, n + 2) {
		rep(j, m + 2) {
			if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
				mp[i][j] = '#';
			}
		}
	}
	int sx = 1; int sy = 1;
	int gx, gy;
	rep1(i, n) {
		rep1(j, m) {
			cin >> mp[i][j];
			if (mp[i][j] == 'F') {
				gx = i; gy = j;
				mp[i][j] = '.';
			}
		}
	}
	if (gx == 1 && gy == 1)return 0;
	//cout << gx << " " << gy << endl;
	rep(i, n + 2) {
		rep(j, m + 2) {
			d[i][j] = mod;
		}
	}
	priority_queue<speP, vector<speP>, greater<speP>> q; d[gx][gy] = 0; q.push({ 0,{ gx,gy } });
	while (!q.empty()) {
		speP y = q.top(); q.pop(); P x = y.second;
		rep(k, 4) {
			int nx = x.first + dx[k];
			int ny = x.second + dy[k];
			if (mp[nx][ny] != '.')continue;
			int nd = y.first + 1;
			if (nd < d[nx][ny]) {
				d[nx][ny] = nd;
				q.push({ nd,{ nx,ny } });
			}
		}
	}
	/*rep1(i, n) {
		rep1(j, m) {
			cout << d[i][j] << "   ";
		}
		cout << endl;
	}*/
	int x, y;
	if (mp[1][2] == '.') {
		cout << "R" << endl;
		cin >> x >> y;
		if (gx == x && gy == y)return 0;
		if (sx == x && sy == y) {
			swap(dc[0], dc[2]);
		}
		else {
			cout << "L" << endl; cin >> x >> y;
			if (gx == x && gy == y)return 0;
		}
		while (mp[2][y] != '.') {
			cout << dc[0] << endl;
			cin >> x >> y;
			if (gx == x && gy == y)return 0;
		}
		cout << "D" << endl; cin >> x >> y;
		if (gx == x && gy == y)return 0;
		if (x == 1) {
			swap(dc[1], dc[3]);
		}
	}
	else {
		cout << "D" << endl; cin >> x >> y;
		if (gx == x && gy == y)return 0;
		if (x == 1) {
			swap(dc[1], dc[3]);
		}
		else {
			cout << "U" << endl; cin >> x >> y;
			if (gx == x && gy == y)return 0;
		}
		while (mp[x][2] != '.') {
			cout << dc[1] << endl;
			cin >> x >> y;
			if (gx == x && gy == y)return 0;
		}
		cout << "R" << endl; cin >> x >> y;
		if (gx == x && gy == y)return 0;
		if (y == 1) {
			swap(dc[0], dc[2]);
		}
	}
	/*rep1(i, n) {
	rep1(j, m) {
	cout << d[i][j] << "  ";
	}
	cout << endl;
	}*/
	while (d[x][y]) {
		rep(k, 4) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (d[nx][ny] == d[x][y] - 1) {
				cout << dc[k] << endl; cin >> x >> y;
				if (gx == x && gy == y)return 0; break;
			}
		}
	}
	return 0;
}