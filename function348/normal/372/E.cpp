#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef double db;
struct point {db x,y;};
struct rec {db x,y,f;};
const int N=1010,p=1000000007;
const db eps=1e-9;
int n,num;
point x[N];
rec c[N*N];
db abs(db n) { return n>0?n:-n;}
int cmp(rec x,rec y)
{
	if (abs(x.x-y.x)>eps) return x.x<y.x;
	if (abs(x.y-y.y)>eps) return x.y<y.y;
	return x.f<y.f;
}
int cmp1(rec a,rec b) { return abs(a.x-b.x)<eps&&abs(a.y-b.y)<eps;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		x[i]=(point){1.0*a*b*d*d/(a*a*d*d+b*b*c*c),1.0*(c*d*b*b)/(a*a*d*d+b*b*c*c)};
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++)
	{
		c[++num]=(rec){x[i].x+x[j].x,x[i].y+x[j].y,0};
		if (abs(x[i].x-x[j].x)<eps) c[num].f=1e+100;else c[num].f=(x[j].y-x[i].y)/(x[j].x-x[i].x);
	}
	sort(c+1,c+1+num,cmp);
	int ans=0;
	for (int i=1;i<=num;)
	{
		int j=i+1,d=1,tmp=1;
		while (abs(c[i].x-c[j].x)<eps&&abs(c[i].y-c[j].y)<eps&&j<=num)
		{
			if (abs(c[j-1].f-c[j].f)>eps) tmp=1LL*tmp*(d+1)%p,d=1;
			else d++;
			j++;
		}
		tmp=1LL*tmp*(d+1)%p;
		ans=(ans+tmp-1-(j-i))%p;
		i=j;
	}
	ans=(ans+p)%p;
	printf("%d\n",ans);
	return 0;
}