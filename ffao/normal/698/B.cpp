#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int p[210000];
int par[210000];
int sn[210000];
int root[210000];

int find(int a) {
	if (par[a]==a) return a;
	return par[a]=find(par[a]);
}

void link(int a, int b) {
	int x = find(a), y = find(b);
	par[y]=x;
}

int n;
void solve() {
	int ans = 0;

	scanf("%d", &n);
	REP(i,n) {
		par[i] = i;
		scanf("%d", &p[i]); p[i]--;
	}

	for (int i = 0; i < n; i++) {
		link(i, p[i]);
	} 

	memset(root,-1,sizeof(root));
	for (int i = 0; i < n; i++) if (root[find(i)] == -1) {
		int comp = find(i);
		int cur = i;
		while (!sn[cur]) {
			sn[cur] = 1;
			cur = p[cur];
		}
		root[comp] = cur;
	}

	int firstcomp = -1;
	for (int i = 0; i < n; i++) {
		int comp = find(i);
		if (p[ root[comp] ] == root[comp] ) firstcomp = comp;
	}

	if (firstcomp == -1) {
		ans++;
		firstcomp = find(0);
		p[root[firstcomp]] = root[firstcomp];
	}

	for (int i = 0; i < n; i++) if (find(i) == i && i != firstcomp) {
		ans++;
		p[root[i]] = root[firstcomp];
	} 

	printf("%d\n", ans);
	REP(i,n) printf("%d ", p[i]+1);
	printf("\n");
}

int main() {
    solve();
}