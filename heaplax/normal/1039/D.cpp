#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 100001
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,now,f[N],ans[N];
int cnt,head[N],nxt[N+N],to[N+N];
void dfs(int u,int fa,int k)
{
	int mx1=0,mx2=0;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa)
		{
			dfs(v,u,k);
			if(f[v]>mx1)mx2=mx1,mx1=f[v];else mx2=max(mx2,f[v]);
		}
	if(mx1+mx2+1>=k)f[u]=0,++now;else f[u]=mx1+1;
}
void sol(int l,int r,int L,int R)
{
	if(l>r || L>R)return;
	if(L==R){for(;l<=r;++l)ans[l]=L;return;}
	int mid=l+r>>1;now=0;dfs(1,0,mid);ans[mid]=now;
	sol(l,mid-1,now,R);sol(mid+1,r,L,now);
}
int main()
{
	re(n);
	for(int i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	printf("%d\n",n);
	sol(2,n,0,n/2);
	for(int i=2;i<=n;++i)
		printf("%d\n",ans[i]);
}