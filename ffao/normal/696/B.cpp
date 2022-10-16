#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


vector<int> adj[110000];
int tam[110000];
double ans[110000];

void dfst(int v) {
	tam[v]=1;

	for (int x : adj[v]) {
		dfst(x);
		tam[v] += tam[x];
	}
}

void dfs(int v, double cur) {
	ans[v]=cur;

	for (int x : adj[v]) {
		dfs(x, cur + 0.5 + (tam[v]-tam[x])/2.0);
	}
}

int n;
void solve() {
	scanf("%d", &n);
	REP(i,n-1) {
		int p;
		scanf("%d", &p);
		adj[p-1].push_back(i+1);
	}

	dfst(0);
	dfs(0, 1);

	REP(i,n) printf("%.15f ", ans[i]);
	printf("\n");
}

int main() {
    solve();
}