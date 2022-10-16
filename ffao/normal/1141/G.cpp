#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n, k, tgt_k;

vector<pii> g[310000];
int color[310000];
int cnt[310000];

void dfs(int v, int p, int col) {
	if (g[v].size() > tgt_k) {
		for (pii edge : g[v]) if (edge.first != p) {
			int ch = edge.first, idx = edge.second;
			color[idx]=1;
			dfs(ch,v,1);
		}
		return;
	}

	int pp = col+1;
	if (pp > tgt_k) pp = 1;

	for (pii edge : g[v]) if (edge.first != p) {
		int ch = edge.first, idx = edge.second;
		dfs(ch,v,pp);
		color[idx] = pp++;
		if (pp > tgt_k) pp = 1;
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		scanf("%d %d", &a, &b); a--; b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}

	for (int i = 0; i < n; i++) {
		cnt[g[i].size()]++;
	}

	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += cnt[i];
		if (tot >= n-k) {
			tgt_k = i; 
			break;
		}
	}

	dfs(0,-1,1);

	printf("%d\n", tgt_k);
	for (int i = 0; i < n-1; i++) printf("%d ", color[i]);
}