#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(ll i=j;i<=k;i++)
#define Dow(i,j,k) for(ll i=k;i>=j;i--)
using namespace std;
inline void read(ll &tx){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  tx=x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
using namespace std;
ll f[100001],alr,poi[100001],nxt[100001],F[100001],X[100001],Y[100001],n,x,y,cnt,c[100001];
bool vis[5001];
ll dx[]={0,1,0,-1,0};
ll dy[]={0,0,1,0,-1};
inline void add(ll x,ll y){poi[++cnt]=y;nxt[cnt]=f[x];f[x]=cnt;}
inline void dfs(ll now,ll x,ll y,ll b,ll fdir)
{
	X[now]=x;Y[now]=y;
	vis[now]=1;
	ll dir=1;
	for(ll i=f[now];i;i=nxt[i])
	{
		if(vis[poi[i]])	continue;
		if(fdir!=-1)	if(dir==fdir)	dir++;
		dfs(poi[i],x+dx[dir]*(1<<b),y+dy[dir]*(1<<b),b-1,(dir+2-1)%4+1);	++dir;
	}
}
int main()
{
	read(n);
	For(i,1,n-1)
		read(x),read(y),add(x,y),add(y,x),c[x]++,c[y]++;
	For(i,1,n)	
	{
		if(c[i]>4)	{puts("NO");return 0;}
	}
	puts("YES");
	dfs(1,0,0,30LL,-1);
	For(i,1,n)	printf("%I64d %I64d\n",X[i],Y[i]);
}