#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>
#define MN 200000
#define eps 1e-10
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> a[MN+5];
int n,q[MN+5],top=0;double ans=1e9,P,Q;
double Calc(double x,double y,double xx,double yy)
{
	double l=0,r=1000000,res=1e9,t1,t2,X=P,Y=Q;
	if(x<xx) swap(x,xx),swap(y,yy);
//	cout<<"Calc"<<x<<" "<<xx<<" "<<y<<" "<<yy<<" "<<X<<" "<<Y<<endl;
	for(int i=1;i<=60;++i)
	{	
		double mid=(l+r)/2.0;
		if(fabs(x-xx)>1e-7) t1=(double)(X-xx*mid)/(x-xx);
		else t1=0;
		if(t1>mid) t1=mid;if(t1<0) t1=0;t2=mid-t1;
	//	if(t1>1e-7) cout<<mid<<" "<<t1<<" "<<t2<<endl;
		if(t1*y+t2*yy>=Y-eps&&t1*x+t2*xx>=X-eps) res=mid,r=mid;
		else l=mid;
	}
	return res;
}
long long Get(int x,int y,int z){return 1LL*(a[y].first-a[x].first)*(a[z].second-a[x].second)-1LL*(a[z].first-a[x].first)*(a[y].second-a[x].second);		}
int main()
{
	n=read();P=read();Q=read();
	for(int i=1;i<=n;++i) a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) 
	{
		while(top>1&&Get(q[top-1],q[top],i)>=0) --top;
		q[++top]=i;
	}
	for(int i=1;i<=top;++i) a[i]=a[q[i]];
	for(int i=1;i<=top;++i) ans=min(ans,Calc(a[i].first,a[i].second,a[i].first,a[i].second));
	for(int i=1;i<top;++i) ans=min(ans,Calc(a[i].first,a[i].second,a[i+1].first,a[i+1].second));
	printf("%.10lf",ans);
	return 0;
}