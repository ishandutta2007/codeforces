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
#include<utility>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<cassert>
#include<random>
#include<unordered_map>
#include<numeric>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa;cin>>nyaa;

using P = pair<int, int>;
using LP = pair<ll, ll>;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

int col[300][300];
bool exi[300][300];
void solve() {
	int h, w, q;
	scanf(" %d %d %d", &h, &w, &q);
	vector<int> x(q), y(q), c(q);
	rep(i, q) {
		scanf(" %d %d %d", &x[i], &y[i], &c[i]);
		//cin >> x[i] >> y[i] >> c[i];
		x[i]--; y[i]--;
	}
	vector<int> cans(q), revans(q), memo(q, -1);
	rep(i, q) {
		int le = i;
		while (i + 1 < q&&c[i] == c[i + 1])i++;
		uf u(h*w);
		rep(x, h)rep(y, w)exi[x][y] = false;
		int cnt = 0;
		for (int j = le; j <= i; j++) {
			if (!exi[x[j]][y[j]]) {
				memo[j] = col[x[j]][y[j]];
				col[x[j]][y[j]] = c[j];
				exi[x[j]][y[j]] = true;
				cnt++;
				int fr = x[j] * w + y[j];
				rep(k, 4) {
					int nx = x[j] + dx[k];
					int ny = y[j] + dy[k];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
					if (exi[nx][ny]) {
						int to = nx * w + ny;
						if (!u.same(fr, to)) {
							cnt--;
							u.unite(fr, to);
						}
					}
				}
			}
			cans[j] = cnt;
		}
		uf rev(h*w); cnt = 0;
		rep(x, h)rep(y, w) {
			if (col[x][y] == c[i])continue;
			cnt++;
			int fr = x * w + y;
			rep(k, 4) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
				if (col[nx][ny] == col[x][y]) {
					int to = nx * w + ny;
					if (!rev.same(fr, to)) {
						rev.unite(fr, to);
						cnt--;
					}
				}
			}
		}
		//cout << "?? " << i << " " << cnt << endl;
		for (int j = i; j >= le; j--) {
			revans[j] = cnt;
			if (memo[j] >= 0) {
				col[x[j]][y[j]] = memo[j];
				cnt++;
				int fr = x[j] * w + y[j];
				rep(k, 4) {
					int nx = x[j] + dx[k];
					int ny = y[j] + dy[k];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
					if (col[nx][ny] == memo[j]) {
						int to = nx * w + ny;
						if (!rev.same(fr, to)) {
							rev.unite(fr, to);
							cnt--;
						}
					}
				}
			}
		}
		for (int j = le; j <= i; j++)col[x[j]][y[j]] = c[j];
	}
	//rep(i, q)cout << cans[i] << " " << revans[i] << endl;
	rep(i, q) {
		int ans = cans[i] + revans[i];
		printf("%d\n", ans);
	}
	//rep(i, q)cout << cans[i] + revans[i] << "\n";
}
signed main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);
	//int t; cin >> t;rep(i,t) solve();
	solve();
	//stop
		return 0;
}