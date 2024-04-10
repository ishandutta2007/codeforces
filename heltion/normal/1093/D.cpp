#include<bits/stdc++.h>
using namespace std;
#define maxn 320000
typedef long long LL;
vector<int> G[maxn];
int vis[maxn], cnt[2];
int flag;
const LL mod = 998244353;
void DFS(int u){
	cnt[vis[u]] += 1;
	for(int v : G[u]) if(vis[v] == -1){
		vis[v] = 1 - vis[u];
		DFS(v);
	}
	else if(vis[v] == vis[u]) flag = 0;
}
LL pw[maxn];
int main(){
	int t;
	scanf("%d", &t);
	pw[0] = 1;
	for(int i = 1; i < maxn; i += 1) pw[i] = pw[i - 1] * 2 % mod;
	while(t --){
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i += 1) G[i].clear();
		fill(vis + 1, vis + n + 1, -1);
		for(int i = 1; i <= m; i += 1){
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		flag = 1;
		LL ans = 1;
		for(int i = 1; i <= n && flag; i += 1) if(vis[i] == -1){
			cnt[0] = cnt[1] = 0;
			vis[i] = 0;
			DFS(i);
			ans = (pw[cnt[0]] + pw[cnt[1]]) % mod * ans % mod;
		}
		printf("%lld\n", flag * ans);
	}
}