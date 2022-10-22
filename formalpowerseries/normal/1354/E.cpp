#include<bits/stdc++.h>
using namespace std;
vector<int> G[5005];
int n,m,n1,n2,n3,nl,nr,col[5005],cnt,rt[5005],w[5005],b[5005],ans[5005];
bool dp[5005][5005],lst[5005][5005];
void dfs(int now,int c)
{
	if(!col[now])
	{
		col[now]=c;
		if(c==1)	++w[cnt];
		else	++b[cnt];
		for(auto st:G[now])	dfs(st,-c);
	}
	else
	{
		if(col[now]^c)
		{
			puts("NO");
			exit(0);
		}
	}
}
void red(int now,int c)
{
	if(ans[now])	return ;
	if(c)
	{
		if(col[now]==1)	ans[now]=2;
		else	ans[now]=1;
	}
	else
	{
		if(col[now]==1)	ans[now]=1;
		else	ans[now]=2;
	}
	for(auto st:G[now])	red(st,c);
}
void makeSolution(int now,int st)
{
	if(!now)	return ;
	makeSolution(now-1,st-(lst[now][st]?w[now]:b[now]));
	red(rt[now],lst[now][st]);
}
int main(){
	scanf("%d %d %d %d %d",&n,&m,&n1,&n2,&n3);
	nl=n1+n3,nr=n2;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)
	{
		if(!col[i])
		{
			rt[++cnt]=i;
			dfs(i,1);
		}
	}
	dp[0][0]=true;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=nr;++j)
		{
			if(dp[i-1][j])
			{
				dp[i][j+b[i]]=dp[i][j+w[i]]=lst[i][j+w[i]]=true;
				lst[i][j+b[i]]=false;
			}
		}
	}
	if(!dp[n][nr])	return puts("NO")&0;
	makeSolution(n,nr);
	for(int i=1;i<=n;++i)	if(ans[i]==1 && n3)	--n3,ans[i]=3;
	puts("YES");
	for(int i=1;i<=n;++i)	printf("%d",ans[i]);
	return 0;
}