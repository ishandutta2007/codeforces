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
typedef vector<string> svec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-5;

int sx[8] = { 2,1,0,-1,-2,-1,0,1 };
int sy[8] = { 0,1,2,1,0,-1,-2,-1 };
int n;
bool valid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)return false; return true;
}
int ans[50][50];
void hanten() {
	rep(i, n) {
		rep(j, n) {
			if ((i + j) % 2)ans[i][j] ^= 1;
		}
	}
}
void out() {
	cout << "!" << endl;
	rep(i, n) {
		rep(j, n) {
			//if (j > 0)cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
}
int query(int lx, int ly, int rx, int ry) {
	cout << "? "<<lx + 1 << " " << ly + 1 << " " << rx + 1 << " " << ry + 1 << endl;
	int ret; cin >> ret;
	return ret;
}
int in;
void solve() {
	cin >> n;
	ans[0][0] = 1; ans[n - 1][n - 1] = 0;
	for (int i = 2; i < n; i+=2) {
		int z = query(i - 2, 0, i, 0);
		if (z) {
			ans[i][0] = ans[i - 2][0];
		}
		else {
			ans[i][0] = ans[i - 2][0] ^ 1;
		}
	}
	in = query(0, 0, 1, 1);
	if (in)ans[1][1] = 1;
	else ans[1][1] = 0;
	for (int i = 3; i < n; i += 2) {
		in = query(i - 2, 1, i, 1);
		if (in) {
			ans[i][1] = ans[i - 2][1];
		}
		else {
			ans[i][1] = ans[i - 2][1]^1;
		}
	}
	for (int j = 2; j < n; j++) {
		rep(i, n) {
			if ((i + j) % 2)continue;
			if (i == n - 1 && j == n - 1)continue;
			in = query(i, j - 2, i, j);
			if (in) {
				ans[i][j] = ans[i][j - 2];
			}
			else {
				ans[i][j] = ans[i][j - 2] ^ 1;
			}
		}
	}
	ans[0][1] = 0;
	in = query(0, 1, 1, 2);
	if (in) {
		ans[1][2] = ans[0][1];
	}
	else {
		ans[1][2] = ans[0][1] ^ 1;
	}
	in = query(1, 0, 1, 2);
	if (in) {
		ans[1][0] = ans[1][2];
	}
	else {
		ans[1][0] = ans[1][2] ^ 1;
	}
	rep(i, 2) {
		Rep(j, 3, n) {
			if ((i + j) % 2) {
				in = query(i, j - 2, i, j);
				if (in) {
					ans[i][j] = ans[i][j - 2];
				}
				else {
					ans[i][j] = ans[i][j - 2] ^ 1;
				}
			}
		}
	}
	Rep(i, 2, n) {
		rep(j, n) {
			if ((i + j) % 2) {
				in = query(i - 2, j, i, j);
				if (in) {
					ans[i][j] = ans[i-2][j];
				}
				else {
					ans[i][j] = ans[i-2][j] ^ 1;
				}
			}
		}
	}
	rep(i, n) {
		rep(j, n) {
			if ((i + j) % 2 == 0)continue;
			int nx = i + 1; int ny = j + 1;
			if (valid(nx, ny)&&ans[i][j]==ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i][j + 1]] = true;
				exi[ans[i + 1][j]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i,j,x,y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
			nx = i + 2, ny = j;
			if (valid(nx, ny) && ans[i][j] == ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i + 1][j]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
			nx = i, ny = j + 2;
			if (valid(nx, ny) && ans[i][j] == ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i][j + 1]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
		}
	}
	rep(i, n) {
		rep(j, n) {
			if ((i + j) % 2 == 0)continue;
			int nx = i + 1; int ny = j + 1;
			if (valid(nx, ny) && ans[i][j] != ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i][j + 1]] = true;
				exi[ans[i + 1][j]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
			nx = i + 2, ny = j;
			if (valid(nx, ny) && ans[i][j] != ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i + 1][j]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
			nx = i, ny = j + 2;
			if (valid(nx, ny) && ans[i][j] != ans[nx][ny]) {
				bool exi[2] = {};
				exi[ans[i][j + 1]] = true;
				int x, y;
				x = i; y = j - 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = i - 1; y = j;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(x, y, nx, ny);
					if (in != (ans[x][y] == ans[nx][ny]))hanten();
					out(); return;
				}
				x = nx + 1, y = ny;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
				x = nx, y = ny + 1;
				if (valid(x, y) && exi[ans[x][y]^1]) {
					in = query(i, j, x, y);
					if (in != (ans[i][j] == ans[x][y]))hanten();
					out(); return;
				}
			}
		}
	}
	out();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(5);
	//init();
	solve();
	//cout << "finish" << endl;
	//stop
	return 0;
}