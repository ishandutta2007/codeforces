#include <bits/stdc++.h>
#define N 200050
#define INF (1<<29)
using namespace std;
int n, d[N], b[N], ans, max_d;
inline int rd() {int r;scanf("%d",&r);return r;}
void solve(int id) {
	int min_gap = INF, max_gap = -INF;
	int tot = 0;
	for (int i=1;i<=n;i++)
		if (i!=id) b[++tot] = d[i];
	for (int i=1;i<=n-1;i++) {
		min_gap = min(b[i]-b[i-1]-1, min_gap);
		max_gap = max(b[i]-b[i-1]-1, max_gap);
	}
	max_gap = (max_gap-1)/2;
	max_gap = max(max_gap, max_d-b[n-1]-1);
	
	int ret = min(max_gap, min_gap);
	ans = max(ans, ret);
	return ;
}
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		n = rd(); max_d = rd();
		for (int i=1;i<=n;i++) d[i] = rd();
		sort(d+1, d+n+1);
		ans = INF;
		int id = 1;
		for (int i=1;i<=n;i++) {
			if (d[i]-d[i-1] < d[id]-d[id-1]) id = i;
			ans = min(ans, d[i]-d[i-1]-1);
		}
		
		solve(id);
		if (id > 1) solve(id-1);
		printf("%d\n", ans);		
	}
	return 0;
}