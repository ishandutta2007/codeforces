#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*f;
}
inline void write(ll x){if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
int n,m,Fa[400001],top,l,r,q[400001],x,y,ans[400001];
bool vis[400001];
map<int,int> no[400001];
inline int Get(int x){return x==Fa[x]?x:Fa[x]=Get(Fa[x]);}
inline void Bfs(int x)
{
	int siz=1;
	l=r=1;q[l]=x;Fa[q[l]]=Get(q[l]+1);
	while(l<=r)
	{
		int now=0;
		while(1)
		{
			now=Get(now+1);
			if(now==q[l])	continue;	
			if(now>n)	break;
			if(no[q[l]][now])	continue;
			q[++r]=now;++siz;vis[now]=1;Fa[q[r]]=Get(q[r]+1);
		}
		++l;
	}
	ans[++top]=siz;	//cout<<siz<<' '<<q[top]<<' '<<top<<endl;
}
int main()
{	
	n=read();m=read();
	For(i,1,n+1)	Fa[i]=i;
	For(i,1,m)	x=read(),y=read(),no[x][y]=no[y][x]=1;
	For(i,1,n)
		if(Get(i)==i)	Bfs(i);
	cout<<top<<endl;
	sort(ans+1,ans+top+1);
	For(i,1,top)	write_p(ans[i]);
}