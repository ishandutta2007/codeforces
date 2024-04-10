#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

int in[1010];
pii to[1010];
int vis[1010];
vector <piii> ans;

int main(){
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		to[u] = mp(v, c), in[v]++;
	}
	for (int i = 1; i <= n; i++){
		if (vis[i] || in[i]) continue;
		int now = i; vis[now] = 1;
		int minj = 0x3f3f3f3f;
		int flag = 0;
		while (to[now].fi){
			minj = min(minj, to[now].se);
			now = to[now].fi;
			if (vis[now]){
				flag = 1;
				break;
			}
			vis[now] = 1;
		}
		if (minj != 0x3f3f3f3f && !flag) ans.push_back(mp(mp(i, now), minj));
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++){
		printf("%d %d %d\n", ans[i].fi.fi, ans[i].fi.se, ans[i].se);
	}
	return 0;
}