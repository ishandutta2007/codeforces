#include <bits/stdc++.h>

int m,n,cnt,a[1<<23],vis[1<<23][3],S;

void dfs(int u,int x){
	vis[u][x]=1;
	if(x==1) { 
		if(!vis[(S^u)][2]) dfs(S^u,2);
	}
	else {
		if(!vis[u][1]) dfs(u,1);
		for(int i=0;i<m;++i)
		if(u&(1<<i)&&!vis[u^(1<<i)][2])
			dfs(u^(1<<i),2);
	}
}

int main(){
	scanf("%d%d",&m,&n); S=(1<<m)-1;
	
	for(int i=0;i<(1<<m);++i)
	
		vis[i][1]=1;
		
	for(int i=1;i<=n;++i){
		
		scanf("%d",&a[i]);
		vis[a[i]][1]=0;
		
	}
	
	for(int i=1;i<=n;++i)
		if(!vis[a[i]][1]){
			cnt++;
			dfs(a[i],1);
		}
		
	printf("%d",cnt);
	return 0;
}