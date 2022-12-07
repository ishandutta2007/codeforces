#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 100001
#define INF 1ll<<62
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
void re(LL& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
LL n,m,k,ans,q[N],goo[N*10];
struct node
{
	LL d,f,t,c;
	bool operator < (const node& i)const
	{
		return d<i.d;
	}
}a[N];
int main()
{
	re(n),re(m),re(k);
	for(LL i=1;i<=m;++i)
		re(a[i].d),re(a[i].f),re(a[i].t),re(a[i].c);
	sort(a+1,a+m+1);
	for(LL i=1;i<=1000000;++i)goo[i]=INF;
	for(LL i=1,last=n,now=0;i<=m;++i)
		if(a[i].f)
		{
			if(q[a[i].f] && a[i].c<q[a[i].f])now-=q[a[i].f]-a[i].c,q[a[i].f]=a[i].c;
			else if(!q[a[i].f])q[a[i].f]=a[i].c,--last,now+=a[i].c;
			if(!last)goo[a[i].d]=now;
		}
	for(LL i=2;i<=1000000;++i)goo[i]=min(goo[i],goo[i-1]);
	memset(q,0,sizeof(q));ans=INF;
	for(LL i=m,last=n,now=0;i;--i)
		if(a[i].t && a[i].d-k-2>=0)
		{
			if(q[a[i].t] && a[i].c<q[a[i].t])now-=q[a[i].t]-a[i].c,q[a[i].t]=a[i].c;
			else if(!q[a[i].t])q[a[i].t]=a[i].c,--last,now+=a[i].c;
			if(!last)ans=min(ans,now+goo[a[i].d-k-1]);
		}	
	if(ans == INF)puts("-1");
	else printf("%I64d\n",ans);
}