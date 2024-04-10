#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define eps 1e-10
#define MAXN 2001
int N,a,b,cnt1,cnt2;double x[MAXN],y[MAXN],ans;
void check(double c1,double c2)
{
	ans=cnt1=cnt2=0;
	For(i,1,N)
	{
		double tmp=0;bool flag1=0,flag2=0;if(x[i]-c1>tmp+eps)flag1=1,flag2=0,tmp=x[i]-c1;if(y[i]-c2>tmp+eps)flag2=1,flag1=0,tmp=y[i]-c2;
		if(x[i]+y[i]-x[i]*y[i]-c1-c2>tmp+eps)flag1=flag2=1,tmp=x[i]+y[i]-x[i]*y[i]-c1-c2;ans+=tmp,cnt1+=flag1,cnt2+=flag2;
	}
}
int main()
{
	cin>>N>>a>>b;For(i,1,N)cin>>x[i];For(i,1,N)cin>>y[i];
	double l=0,r=1,val1=0,val2=0;
	For(t1,1,30)
	{
		double c1=(l+r)/2;double L=0,R=1;
		For(t2,1,30)
		{
			double c2=(L+R)/2;check(c1,c2);val2=c2;if(cnt2==b)break;if(cnt2<b)R=c2;else L=c2;
		}
		val1=c1;if(cnt1==a)break;if(cnt1<a)r=c1;else l=c1;
	}
	printf("%.10lf\n",ans+a*val1+b*val2);return 0;
}