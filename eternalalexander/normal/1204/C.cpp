#include <bits/stdc++.h>

int inf=9999999;
std::stack<int>stk;
int dis[105][105],G[105][105],n,m,p[1000006];
char s[1000];

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=n;++j){
			if (s[j]=='0')G[i][j]=inf;
			else G[i][j]=1;
		}G[i][i]=0;
	}for (int i=1;i<=n;++i)for(int j=1;j<=n;++j)dis[i][j]=G[i][j];
	for (int k=1;k<=n;++k)
	for (int i=1;i<=n;++i)
	for (int j=1;j<=n;++j)
	if (dis[i][k]+dis[k][j]<=dis[i][j])dis[i][j]=dis[i][k]+dis[k][j];
	scanf("%d",&m);
	for (int i=1;i<=m;++i){scanf("%d",&p[i]);}
	stk.push(m);
	for (int i=m-1;i>=2;i--){
		if (dis[p[i-1]][p[i]]+dis[p[i]][p[stk.top()]]!=dis[p[i-1]][p[stk.top()]])stk.push(i);
	}stk.push(1);
	printf("%d\n",stk.size());
	while (!stk.empty()){
		printf("%d ",p[stk.top()]);stk.pop();
	}
	return 0;
}