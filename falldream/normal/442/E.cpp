#include<bits/stdc++.h>
#define MN 1000
#define eps 1e-10
const double pi=acos(-1);
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct eve{double x;int ad;}e[MN*10+5];
int w,h,n,top,now;
double ans=eps,dis[MN+5][MN+5];
pair<int,int> s[MN+5];
inline double Sq(int x){return 1.0*x*x;}
inline void Add(double l,double r,int v=1)
{
	if(l<=0) now+=v; else e[++top]=(eve){l,v};
	if(r<2*pi) e[++top]=(eve){r+eps,-v};
}
bool cmp(const eve&a,const eve&b){return a.x<b.x;}
bool Solve(int x,double mid)
{
	top=now=0;
	for(int i=1;i<=n;++i) if(dis[i][x]>0&&dis[i][x]<2*mid)
	{
		double r1=acos(dis[i][x]/2/mid);
		double s1=atan2(s[i].second-s[x].second,s[i].first-s[x].first);
		double l=s1-r1,r=s1+r1;
		while(l<0) l+=2*pi;while(l>=2*pi) l-=2*pi;
		while(r<0) r+=2*pi;while(r>=2*pi) r-=2*pi;
		if(l<=r) Add(l,r);
		else Add(0,r),Add(l,2*pi);
	}
	if(s[x].first<mid)
		Add(pi-acos(s[x].first/mid),pi+acos(s[x].first/mid),2);	
	if(s[x].second<mid)
		Add(1.5*pi-acos(s[x].second/mid),1.5*pi+acos(s[x].second/mid),2);
	if(s[x].first+mid>w)
		Add(0,acos((w-s[x].first)/mid),2),
		Add(2*pi-acos((w-s[x].first)/mid),2*pi,2);
	if(s[x].second+mid>h)
		Add(pi/2-acos((h-s[x].second)/mid),pi/2+acos((h-s[x].second)/mid),2);
	if(now<2) return true;sort(e+1,e+top+1,cmp);
	for(int i=1;i<=top;++i) 
		if((now+=e[i].ad)<2) return true;
	return false;
}
int main()
{
	w=read();h=read();n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read();
	srand((long long)new char);
	for(int t=0;t<5;++t) random_shuffle(s+1,s+n+1);
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) 
		dis[i][j]=dis[j][i]=sqrt(Sq(s[i].second-s[j].second)+Sq(s[i].first-s[j].first));
	for(int i=1;i<=n;++i) if(Solve(i,ans+eps))
	{
		double l=ans,r=1500000,mid;
		for(int t=1;t<=60;++t)
		{
			mid=(l+r)/2.0;
			if(Solve(i,mid)) ans=mid,l=mid;
			else r=mid;	
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}