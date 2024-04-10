#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <int> all[2010];

int dist(pii a, pii b){
	return abs(a.fi - b.fi) + abs(a.se - b.se);
}

int main(){
//	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			all[i].push_back(j);
		}
	}
	for (int q = 0; q < k; q++){
		int x, y;
		scanf("%d%d", &x, &y);
		int d = sqrt(q);
		pii ans(1000000, 1000000);
		for (int j = 0; j <= n && j <= dist(ans, mp(x, y)); j++){
			for (int k = 0; k < 2; k++){
				int i = x;
				if (k) i = min(n, i + j);
				else i = max(0, i - j);
				if (all[i].size() == 0) continue;
				int t = lower_bound(all[i].begin(), all[i].end(), y) - all[i].begin();
				int p1 = all[i][(t == all[i].size() ? t - 1 : t)];
				int p2 = all[i][(t - 1 == -1 ? t : t - 1)];
				pii now(i, p2);
				if (abs(p1 - y) < abs(p2 - y)) now.se = p1;
				if (dist(mp(x, y), ans) > dist(mp(x, y), now)) ans = now;
				if (dist(mp(x, y), ans) == dist(mp(x, y), now) && now < ans) ans = now;
			}
		}
		printf("%d %d\n", ans.fi, ans.se);
		all[ans.fi].erase(lower_bound(all[ans.fi].begin(), all[ans.fi].end(), ans.se));
	}
	return 0;
}