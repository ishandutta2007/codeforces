#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
const int N = 1011;
const int LOG = 20;
const int MOD = 1e9 + 7;
typedef complex<double> Complex;
int dis[N][N];
struct RELA {
	int a[N][N];
	char mp[N][N];
	int n, m;
	void init(int _n, int _m) {
		n = _n; m = _m;
		for(int i(0); i < n; i++) {
			for(int j(0); j <= m; j++) {
				a[i][j] = j;
			}
		}
	}
	int getr(int * rela, int x) {
		int p(x);
		while(p != rela[p]) p = rela[p];
		int p1(p); p = x;
		while(p != rela[p]) {
			int p2(rela[p]);
			rela[p] = p1;
			p = p2;
		}
		return p1;
	}
	void del(int i, int j) {
		a[i][j] = getr(a[i], j + 1);
	}
	void nxt(int i, int j, int & x, int & y) {
		j = getr(a[i], j + 1);
		x = i; y = j;
		if(j == m || mp[i][j] == '#') {
			x = y = -1;
		}
	}

} lr, rl, bt, tb;
int n, m;
void erase(int x, int y) {
	lr.del(x, y);
	rl.del(x, m - y - 1);
	tb.del(y, x);
	bt.del(y, n - x - 1);
}
char a[N][N];
int main() {
	int k;
	scanf("%d%d%d", &n, &m, &k);
	lr.init(n, m);
	rl.init(n, m);
	tb.init(m, n);
	bt.init(m, n);
	
	for(int i(0); i < n; i++) {
		scanf("%s", a[i]);
		for(int j(0); j < m; j++) {
			lr.mp[i][j] = a[i][j];
			rl.mp[i][m - j - 1] = a[i][j];
			tb.mp[j][i] = a[i][j];
			bt.mp[j][n - i - 1] = a[i][j];
		}
	}
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--; y1--; x2--; y2--;
	memset(dis, -1, sizeof(dis));
	vector<pair<int, int> > q;
	q.push_back({x1, y1});
	dis[x1][y1] = 0;
	erase(x1, y1);
	for(int op(0); op < (int)q.size(); op++) {
		int x(q[op].first), y(q[op].second);
		int X, Y;
		for(lr.nxt(x, y, X, Y); Y - y <= k && X != -1; lr.nxt(X, Y, X, Y)) {
			dis[X][Y] = dis[x][y] + 1;
			q.push_back({X, Y});
			erase(X, Y);
		}
		for(rl.nxt(x, m - y - 1, X, Y); Y - (m - y - 1) <= k && X != -1; rl.nxt(X, Y, X, Y)) {
			dis[X][m - Y - 1] = dis[x][y] + 1;
			q.push_back({X, m - Y - 1});
			erase(X, m - Y - 1);
		}
		for(tb.nxt(y, x, Y, X); X - x <= k && X != -1; tb.nxt(Y, X, Y, X)) {
			dis[X][Y] = dis[x][y] + 1;
			q.push_back({X, Y});
			erase(X, Y);
		}
		for(bt.nxt(y, n - x - 1, Y, X); X - (n - x - 1) <= k && X != -1; bt.nxt(Y, X, Y, X)) {
			dis[n - X - 1][Y] = dis[x][y] + 1;
			q.push_back({n - X - 1, Y});
			erase(n - X - 1, Y);
		}
	}
	printf("%d\n", dis[x2][y2]);
}