#include<bits/stdc++.h>
using namespace std;
const int N=505,M=11,inf=0x3f3f3f3f;
int n,k,nxt[N][M],dep[N],tms[N],nds=1,dp[N][M][N],tmp[N][M][N][M];
char temp[N];
int dfs(int now,int rem,int lst)
{
	if(~dp[now][rem][lst])
		return dp[now][rem][lst];
	int &res=dp[now][rem][lst];
	res=inf;
	if(rem)
		res=dfs(now,rem-1,now);
	tmp[now][rem][lst][0]=0;
	int ids=0;
	for(int i=0;i<10;i++)
	{
		if(nxt[now][i])
		{
			ids++;
			for(int j=0;j<=rem;j++)
				tmp[now][rem][lst][ids]=min(tmp[now][rem][lst][ids],tmp[now][rem-j][lst][ids-1]+dfs(nxt[now][i],j,lst));
		}
	}
	res=min(res,tmp[now][rem][lst][ids]+(dep[now]-dep[lst])*tms[now]);
	return res;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%s %d",temp,&m);
		int now=1;
		for(int i=0;temp[i];i++)
		{
			if(!nxt[now][temp[i]-'0'])
			{
				nxt[now][temp[i]-'0']=++nds;
				dep[nds]=dep[now]+1;
			}
			now=nxt[now][temp[i]-'0'];
		}
		tms[now]+=m;
	}
	memset(dp,-1,sizeof(dp));
	memset(tmp,inf,sizeof(tmp));
	printf("%d\n",dfs(1,k,1));
	return 0;
}