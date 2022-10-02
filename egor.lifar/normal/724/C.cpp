#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int n, m;
int k;
int x[100001], y[100001];
unordered_map<int, long long> ft[2][2][100001];


int main() {
	cin >> n >> m;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	ft[1][1][0][0] = 0;
	int cx = 0, cy = 0;
	int vx = 1, vy = 1;
	while (true) {
		int t = 1000000000;
		if (vx == 1) {
			t = min(t, (n - cx) / vx);
		} else {
			t = min(t, -cx / vx);
		}
		if (vy == 1) {
			t = min(t, (m - cy) / vy);
		} else {
			t = min(t, -cy / vy);
		}
		//cout << t << endl;
		int nextx, nexty;
		nextx = cx + vx * t;
		nexty = cy + vy * t;
		if (nextx == n && nexty == m) {
			break;
		}
		if (nextx == 0 && nexty == m) {
			break;
		}
		if (nextx == n && nexty == 0) {
			break;
		}
		if (nextx == 0 && nexty == 0) {
			break;
		}
		long long last = ft[vx == 1][vy == 1][cx][cy];
		if (nextx == n || nextx == 0) {
			vx *= -1;
		} else {
			vy *= -1;
		}
		if (ft[vx == 1][vy == 1][nextx].find(nexty) == ft[vx == 1][vy == 1][nextx].end()) {
			ft[vx == 1][vy == 1][nextx][nexty] = last + t;
		} else {
			break;
		}
		cx = nextx;
		cy = nexty;
	}
	for (int i = 0; i < k; i++) {
		long long ans = 1000000000000000000LL;
		long long s = 1000000000000000000LL;
		if (ft[1][1][x[i] - min(x[i], y[i])].find(y[i] - min(x[i], y[i])) != ft[1][1][x[i] - min(x[i], y[i])].end()) {
			s = ft[1][1][x[i] - min(x[i], y[i])][y[i] - min(x[i], y[i])];
		}
		ans = min(ans, s + min(x[i], y[i]));
		s = 1000000000000000000LL;
		if (ft[0][0][x[i] + min(n - x[i], m - y[i])].find(y[i] + min(n - x[i], m - y[i])) != ft[0][0][x[i] + min(n - x[i], m - y[i])].end()) {
			s = ft[0][0][x[i] + min(n - x[i], m - y[i])][y[i] + min(n - x[i], m - y[i])];
		}
		ans = min(ans, s + min(n - x[i], m - y[i]));
		s = 1000000000000000000LL;
		if (ft[1][0][x[i] - min(x[i], m - y[i])].find(y[i] + min(x[i], m - y[i])) != ft[1][0][x[i] - min(x[i], m - y[i])].end()) {
			s = ft[1][0][x[i] - min(x[i], m - y[i])][y[i] + min(x[i], m - y[i])];
		}
		ans = min(ans, s + min(x[i], m - y[i]));
		s = 1000000000000000000LL;
		if (ft[0][1][x[i] + min(n - x[i], y[i])].find(y[i] - min(n - x[i], y[i])) != ft[0][1][x[i] + min(n - x[i], y[i])].end()) {
			s = ft[0][1][x[i] + min(n - x[i], y[i])][y[i] - min(n - x[i], y[i])];
		}
		ans = min(ans, s + min(n - x[i], y[i]));
		if (ans == 1000000000000000000LL) {
			printf("-1\n");
			continue;
		}
		printf("%lld\n", ans);
	}
	return 0;
}