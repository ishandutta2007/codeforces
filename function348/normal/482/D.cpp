#include<cstdio>
#include<iostream>
#define MP make_pair
#define FR first
#define SC second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=100010;
const LL mo=1000000007;
struct Edge{int y,ne;};
int n,num;
int fa[N];
Edge e[N];int last[N];
PII f[N];
PII operator * (PII x,PII y)
{
	return MP((x.FR*y.SC+x.SC*y.FR)%mo,(x.FR*y.FR+x.SC*y.SC)%mo);
}
PII operator + (PII x,PII y)
{
	return MP((x.FR+y.FR)%mo,(x.SC+y.SC)%mo);
}
void add(int x,int y)
{
	e[++num].y=y;e[num].ne=last[x];last[x]=num;
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++) scanf("%d",&fa[i]),add(fa[i],i);
	for (int i=n;i>=1;i--)
	{
		PII now=MP(0,1);
		LL res=1;
		PII res2=MP(0,1);
		for (int j=last[i];j;j=e[j].ne)
		{
			now=now*f[e[j].y]+now;
			res=res*(f[e[j].y].SC+1)%mo;
			res2=res2*MP(f[e[j].y].FR,1);
		}
		now.FR*=2;now.SC*=2;
		now.FR-=res2.FR;
		now.SC-=res;
		swap(now.FR,now.SC);
		f[i]=now;
	}
	LL ans=((f[1].FR+f[1].SC)%mo+mo)%mo;
	printf("%I64d\n",ans);
	return 0;
}