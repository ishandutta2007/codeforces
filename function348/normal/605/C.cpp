#include<cstdio>
#include<iostream>
#include<algorithm>
#define FR first
#define SC second
using namespace std;
const int N=100010;
typedef pair<int,int> PII;
int n,p,q,top;
PII a[N],b[N];
double ans;
void calc(int x1,int y1,int x2,int y2,double &k,double &b)
{
	k=1.0*(y2-y1)/(x2-x1);
	b=y1-k*x1;
}
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].FR,&a[i].SC);
	sort(a+1,a+1+n);
	b[1]=a[1];top=1;
	for (int i=2;i<=n;i++)
	{
		while (b[top].SC<=a[i].SC&&top) top--;
		while (1LL*(a[i].SC-b[top].SC)*(b[top].FR-b[top-1].FR)>=
			   1LL*(b[top].SC-b[top-1].SC)*(a[i].FR-b[top].FR)&&top>1) top--;
		b[++top]=a[i];
	}
	double k=1.0*q/p;
//	printf("%d %d\n",b[1].FR,b[1].SC);
//	printf("%d %d\n",b[2].FR,b[2].SC);
	ans=1e+18;
	ans=min(ans,max(1.0*p/b[1].FR,1.0*q/b[1].SC));
	ans=min(ans,max(1.0*p/b[top].FR,1.0*q/b[top].SC));
	for (int i=1;i<top;i++)
	if (1.0*b[i].SC/b[i].FR>=k&&1.0*b[i+1].SC/b[i+1].FR<k)
	{
		double K,B;
		calc(b[i].FR,b[i].SC,b[i+1].FR,b[i+1].SC,K,B);
	//	printf("%lf %lf\n",K,B);
		double x=1.0*B/(k-K),y=x*k;
		ans=min(ans,1.0*p/x);
		break;
	}
	printf("%.6lf\n",ans);
	return 0;
}