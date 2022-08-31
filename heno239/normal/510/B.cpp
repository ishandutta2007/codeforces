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
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef long double ld;
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
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;

int n, m;
char mp[50][50];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool used[50][50];
typedef pair<P, P> speP;
void solve() {
	cin >> n >> m;
	rep(i, n) {
		rep(j, m) {
			cin >> mp[i][j];
		}
	}
	rep(i, n) {
		rep(j, m) {
			if (used[i][j])continue;
			queue<speP> q;
			q.push({ {i,j},{-1,-1} });
			while (!q.empty()) {
				speP p = q.front(); q.pop();
				int x = p.first.first, y = p.first.second;
				int px = p.second.first, py = p.second.second;
				rep(k, 4) {
					int nx = x + dx[k], ny = y+dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
					if (mp[nx][ny] != mp[x][y])continue;
					if (nx == px && ny == py)continue;
					if (used[nx][ny]) {
						cout << "Yes" << endl; return;
					}
					used[nx][ny] = true;
					q.push({ {nx,ny},{x,y } });
				}
			}
		}
	}
	cout << "No" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}