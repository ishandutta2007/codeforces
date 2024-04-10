#include<cstdio>
#include<iostream>
#include<cmath>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int N=100010;
PII a,b,t;
PII c[N];
int n;
double p1[N],p2[N];
double dist(PII a) { return sqrt(1LL*a.FR*a.FR+1LL*a.SC*a.SC);}
PII operator - (PII a,PII b) { return MP(a.FR-b.FR,a.SC-b.SC);}
int main()
{
	scanf("%d%d%d%d%d%d",&a.FR,&a.SC,&b.FR,&b.SC,&t.FR,&t.SC);
	scanf("%d",&n);a=a-t;b=b-t;
	for (int i=1;i<=n;i++) scanf("%d%d",&c[i].FR,&c[i].SC),c[i]=c[i]-t;
	double now=0;
	double ans=1e+18;
	for (int i=1;i<=n;i++) now+=2*dist(c[i]);
	for (int i=1;i<=n;i++) 
	{
		p1[i]=dist(a-c[i])-dist(c[i]);
		p2[i]=dist(b-c[i])-dist(c[i]);
		ans=min(ans,now+p1[i]);
		ans=min(ans,now+p2[i]);
	}
	int k1=0,k2=0;
	for (int i=1;i<=n;i++)
	if (p2[i]<p2[k1]||k1==0) k2=k1,k1=i;else
	if (p2[i]<p2[k2]||k2==0) k2=i;
	for (int i=1;i<=n;i++)
	{
		if (i!=k1)  ans=min(ans,now+p1[i]+p2[k1]);
		else 		ans=min(ans,now+p1[i]+p2[k2]);
	}
	printf("%.9lf\n",ans);
	return 0;
}