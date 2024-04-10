#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int son[1000001][12],sz[1000001],vis[1000001],n,tot;
char s[100001][20];
inline void build(int x,int beg)
{
	int now=0;
	For(i,beg,9)
	{
		if(!son[now][s[x][i]-'0'])	son[now][s[x][i]-'0']=++tot;
		now=son[now][s[x][i]-'0'];
		if(vis[now]!=x)	sz[now]++,vis[now]=x;
	}
}
inline void Build(int x){For(i,1,9)	build(x,i);}
inline int get(int x,int beg)
{
	int now=0,cnt=0;
	For(i,beg,9)
	{
		now=son[now][s[x][i]-'0'];
		cnt++;
		if(sz[now]==1)	return cnt;
	}
	return 1e9;
}
inline void solve(int x)
{
	int ans=1e9;
	int a[11]={0};
	For(i,1,9)
	{
		int tmp=get(x,i);
	
		if(tmp<ans)	
		{	
			ans=tmp;
			For(j,i,i+tmp-1)	a[j-i+1]=s[x][j]-'0';
		}
	}
	For(i,1,ans)	printf("%d",a[i]);puts("");
}
int main()
{
	n=read();
	For(i,1,n)
		scanf("\n%s",s[i]+1);
	For(i,1,n)	Build(i);
	For(i,1,n)	solve(i);
}