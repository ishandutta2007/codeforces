#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
const int inf = 1e9;
std::vector<int>ch[maxn];
int a[maxn],b[maxn],c[maxn],w0[maxn],w1[maxn],u,v,n;
ll ans ;

void dfs(int u,int f,int min) {
	min = std::min (min, a[u]);
	for(int v:ch[u]){
		if(v==f)continue;
		dfs(v,u,min);
		w0[u]+=w0[v];
		w1[u]+=w1[v];
	} if (b[u] != c[u]) {
		if (b[u] == 0) w0[u] ++;
		else w1[u] ++;
	} int d = std::min(w0[u],w1[u]);
	ans += (ll) d * min * 2;
	w0[u] -= d;
	w1[u] -= d;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}dfs(1,0,inf);
	printf("%lld",(w0[1] == 0 && w1[1] == 0)? ans : -1);
	return 0;
}