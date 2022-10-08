#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);
const int size = 1000;

int n, vt, e;
int as[size];
int bs[size];
bool way[size][size];
bool used[size];
int gldif;
int from[size];
vector <pair <pair <int, int>, int> > ans;

int dfs(int rst, int v) {
	used[v] = true;
	int sm = 0;
	if (v > rst) {
		if (gldif > 0 && as[v] > 0) {
			int d = min(gldif, as[v]);
			gldif -= d;
			sm += d;
	//		ans.pb(mp(mp(v, from[v]), d));
		}
		if (gldif < 0 && as[v] < vt) {
			int d = min(-gldif, vt - as[v]);
			gldif += d;
			sm -= d;
	//		ans.pb(mp(mp(from[v], v), d));
		}
	}
	for (int i = 0; i < n; i++)
		if (way[v][i] && !used[i]) {
			from[i] = v;
			sm += dfs(rst, i);
		}
	if (v != rst && sm != 0)
		if (sm > 0) {
			ans.pb(mp(mp(v, from[v]), sm));
		} else {
			ans.pb(mp(mp(from[v], v), -sm));
		}

	return sm;
}

int main() {
	vector <pair <pair <int, int>, int> > tans;
	int a, b;

	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	scanf("%d%d%d", &n, &vt, &e);
	for (int i = 0; i < n; i++)
		scanf("%d", &as[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &bs[i]);
	for (int i = 0; i < e; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		way[a][b] = true;
		way[b][a] = true;
	}
	for (int i = 0; i < n; i++)
		if (as[i] != bs[i]) {
			gldif = bs[i] - as[i];
			int d[2];
			d[0] = gldif / 2;
			d[1] = gldif - d[0];
			for (int hp = 0; hp < 2; hp++) {
				gldif = d[hp];
				for (int j = 0; j < n; j++)
					used[j] = false;
				ans.clear();
				dfs(i, i);

				if (gldif != 0) {
					cout << "NO" << endl;
					return 0;
				}

				for (int j = 0; j < int(ans.size()); j++)
					used[j] = false;
				int cnt = 0;
				while (cnt < int(ans.size())) {
					bool flag = false;
					for (int j = 0; j < int(ans.size()); j++)
						if (!used[j] && as[ans[j].fs.fs] >= ans[j].sc && as[ans[j].fs.sc] + ans[j].sc <= vt) {
							tans.pb(ans[j]);
							as[ans[j].fs.fs] -= ans[j].sc;
							as[ans[j].fs.sc] += ans[j].sc;
							cnt++;
							used[j] = true;
							flag = true;
						}
					if (!flag) {
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}

	printf("%d\n", int(tans.size()));
	for (int i = 0; i < int(tans.size()); i++) {
		printf("%d %d %d\n", tans[i].fs.fs + 1, tans[i].fs.sc + 1, tans[i].sc);
	}

	return 0;
}