#include <bits/stdc++.h>

int vis[100]={0},arr[100],n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&arr[i]);
	for(int i=1;i<=m;++i){scanf("%d",&arr[0]);vis[arr[0]]=1;}
	for(int i=1;i<=n;++i)if (vis[arr[i]])printf("%d ",arr[i]);
	return 0;
}