#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
#define int ll 
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=3e5+5;
int Q1[N],Q2[N],top1,top2,n,m,X,a[N];
ll sum;
bool vis[N];
vector<int> E[N];
map<int,int> mp[N];
inline void Dfs(int x,int fa)
{
	vis[x]=1;
	int leaf=0;
	for(auto u:E[x])
	{
		if(vis[u])	continue;
		Dfs(u,x);
	}
	if(x==1)	return;
	if(a[x]>=X)	a[fa]+=a[x]-X,Q1[++top1]=mp[x][fa];
	else	Q2[++top2]=mp[x][fa];
}
signed main()
{
	n=read();m=read();X=read();
	For(i,1,n)	a[i]=read(),sum+=a[i];
	if(sum<X*(n-1))	{puts("NO");return 0;}
	puts("YES");
	For(i,1,m)
	{
		int x=read(),y=read();
		E[x].pb(y);E[y].pb(x);
		mp[x][y]=mp[y][x]=i;
	}
	Dfs(1,1);
	For(i,1,top1)	writeln(Q1[i]);
	Dow(i,1,top2)	writeln(Q2[i]);
}