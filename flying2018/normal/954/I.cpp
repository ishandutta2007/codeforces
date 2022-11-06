#include<iostream>
#include<cstdio>
#include<cstring>
#define N 125010
using namespace std;
int id[N],nxt[N],n,m;
int ans[N];
char s[N],t[N];
void solve(int res)
{
	int u=0;
	nxt[1]=0;
	for(int i=2;i<=m;i++)
	{
		while(u && id[t[i]-'a']!=id[t[u+1]-'a']) u=nxt[u];
		if(id[t[i]-'a']==id[t[u+1]-'a']) u++;
		nxt[i]=u;
	}
	u=0;
	for(int i=1;i<=n;i++)
	{
		while(u && id[s[i]-'a']!=id[t[u+1]-'a']) u=nxt[u];
		if(id[s[i]-'a']==id[t[u+1]-'a']) u++;
		if(u==m) ans[i]=min(ans[i],res),u=nxt[u];
	}
}
int ids[7];
void dfs(int u,int t)
{
	if(u>5) return solve(6-t);
	id[u]=u;
	ids[t+1]=u;
	dfs(u+1,t+1);
	ids[t+1]=0;
	for(int i=1;i<=t;i++)
	id[u]=ids[i],dfs(u+1,t);
}
int main()
{
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(int i=1;i<=n;i++) ans[i]=10;
	dfs(0,0);
	for(int i=m;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}