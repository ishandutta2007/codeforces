#include <iostream>
#include <cstdio>
#include <cstdlib>
#define maxn 5005
using namespace std;
int inf=1000000005;
bool bgm[maxn][maxn]={false};
int mins[maxn][maxn];
short nx[maxn][maxn];
struct edge
{
	long long v,len;
	edge *next;
}pool[maxn],*h[maxn];
long long cnt=0;
void addedge(long long u,long long v,long long len)
{
	edge *new1=&pool[cnt++];
	new1->next=h[u];new1->v=v;new1->len=len;
	h[u]=new1;
}
long long n,m,t;
long long ma(long long b)
{
	if(b>0) return b;
	return 0;
}
long long getmin(long long a,long long b)
{
	if(bgm[a][b]) return mins[a][b];
	if(a==n && b>1) return mins[a][b]=inf;
	if(a==n && b<=1) return mins[a][b]=0;
	bgm[a][b]=true;
	mins[a][b]=inf;
	for(edge*p=h[a];p;p=p->next)
	{
		long long nownum=p->len+getmin(p->v,ma(b-1));
		if(nownum>t) continue;
		if(nownum<mins[a][b]) mins[a][b]=nownum,nx[a][b]=p->v;
	}
	return mins[a][b];
}

int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&t);
	long long u,v,len;
	for(long long i=0;i<m;i++)
	{
		scanf("%I64d%I64d%I64d",&u,&v,&len);
		addedge(u,v,len);
	}
	long long nans=0;
	for(long long i=2;i<=n;i++) getmin(1,i);
	for(long long i=2;i<=n;i++) if(getmin(1,i)<=t) nans=i;
	printf("%I64d\n",nans);
	long long nowpl=1;
	for(long long i=nans;i>=1;i--)
	{
		printf("%I64d ",nowpl);
		nowpl=nx[nowpl][i];
	}
	return 0;
}