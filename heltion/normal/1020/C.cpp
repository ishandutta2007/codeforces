#include<bits/stdc++.h>
#define maxn 3600
using namespace std;
typedef long long LL;
int n, m;
int p[maxn];
int v[maxn];
vector<LL> G[maxn];
LL c[maxn];
vector<LL> PG;
LL cal(int L){
	LL ret = 0;
	PG.clear();
	int pV = 0;
	for(int i = 2; i <= m; i += 1){
		if(G[i].size() >= L){
			pV += G[i].size() - L + 1;
			for(int j = 0; j < G[i].size() - L + 1; j += 1) ret += G[i][j];
			for(int j = G[i].size() - L + 1; j < G[i].size(); j += 1) PG.push_back(G[i][j]);
		}
		else{
			for(int j: G[i]) PG.push_back(j);
		}
	}
	sort(PG.begin(), PG.end());
	if(pV + v[1] >= L) return ret;
	for(int i = 0; i < L - pV - v[1]; i += 1) ret += PG[i];
	return ret;
}
int main(){
	LL ans = -1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i += 1){
		scanf("%d %lld", p + i, c + i);
		v[p[i]] += 1;
		G[p[i]].push_back(c[i]);
	}
	for(int i = 1; i <= m; i += 1) sort(G[i].begin(), G[i].end());
	for(int i = 1; i <= n; i += 1){
		LL ret = cal(i);
		//printf("%d %lld\n", i, ret);
		if(ans == -1 || ans > ret) ans = ret;
	}
	printf("%lld\n", ans);
}