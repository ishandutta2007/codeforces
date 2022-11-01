#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register int i=j;i<=k;++i)
#define Dow(i,j,k)	for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
char s[200001];
bool vis[1001][1001];
int n,m,x,y;
inline int get(int &x,int &y,char dir)
{
	int ans=1;
	if(dir=='U')
	{
		ans=1;
		if(x==1)	ans=0;else x--;
		if(ans==0)return ans;
	}
	if(dir=='D')
	{
		ans=1;
		if(x==n)	ans=0;else	x++;
		if(ans==0)return ans;
	}
	if(dir=='L')
	{
		ans=1;
		if(y==1)	ans=0;else y--;
		if(ans==0)return ans;
	}
	if(dir=='R')
	{
		ans=1;
		if(y==m)	ans=0;else y++;
		if(ans==0)return ans;
	}
	if(vis[x][y])	return 0;
	vis[x][y]=1;
	return 1;
}
int tot=0;
int main()
{
	n=read();m=read();x=read();y=read();vis[x][y]=1;//swap(n,m);
	scanf("\n%s",s+1);
	int len=strlen(s+1);
	cout<<1<<' ';
	For(i,1,len-1)
	{
		int tmp=0;
		tmp=get(x,y,s[i]);
		printf("%d ",tmp);
	}
	int ans=0;
	For(i,1,n)
		For(j,1,m)	if(!vis[i][j])	ans++;
	cout<<ans<<endl;
}