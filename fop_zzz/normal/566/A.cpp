#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define VI vector<int>
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
    while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
int n;
int son[800010][26],tot,tans[200001];
VI bj[800010][2];
char s[1000001];
bool vis[200001][2];
inline void build(char s[],int to,int kd)
{
	int now=0;
	int len=strlen(s+1);
	bj[now][kd].pb(to);
	For(i,1,len)
	{
		if(!son[now][s[i]-'a'])	son[now][s[i]-'a']=++tot;
		now=son[now][s[i]-'a'];
		bj[now][kd].pb(to);
	}
}
inline int dfs(int dep,int now)
{
	int tmp=0;
	For(i,0,25)
		if(son[now][i])
			tmp+=dfs(dep+1,son[now][i]);
	VI to[2];
	
	for(int i=0;i<bj[now][0].size();++i)
		if(!vis[bj[now][0][i]][0])
			to[0].pb(bj[now][0][i]);
			
	for(int i=0;i<bj[now][1].size();++i)
		if(!vis[bj[now][1][i]][1])
			to[1].pb(bj[now][1][i]);
			
	int can=min(to[1].size(),to[0].size());
	tmp+=dep*can;
	for(int i=0;i<can;++i)
	{
		tans[to[1][i]]=to[0][i];
		vis[to[1][i]][1]=vis[to[0][i]][0]=1;
	}
	return tmp;
}
int main()
{
	n=read();
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		build(s,i,1);
	}
	For(i,1,n)
	{
		scanf("\n%s",s+1);
		build(s,i,0);
	}
	int ans=dfs(0,0);
	cout<<ans<<endl;
	For(i,1,n)	printf("%d %d\n",i,tans[i]);
}