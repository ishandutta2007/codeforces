#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
struct edge{int nx,t;}e[MN*2+5];
int u[MN+5],s[MN+5],h[MN+5],en,k;
long long ans;
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void solve(int x,int fa)
{
	s[x]=u[x];
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		solve(e[i].t,x);
		s[x]+=s[e[i].t];
		ans+=min(s[e[i].t],k-s[e[i].t]);
	}
}
int main()
{
	int n,i;
	n=read();k=read()<<1;
	for(i=1;i<=k;++i)u[read()]=1;
	for(i=1;i<n;++i)ins(read(),read());
	solve(1,0);
	printf("%I64d",ans);
}