#include<bits/stdc++.h>
#define MN 1000 
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
struct Point
{
	int x,y;
	Point(){}
	Point(int _x,int _y):x(_x),y(_y){}
	double len() {return sqrt(x*x+y*y);}
	friend int operator * (const Point&a,const Point&b){return a.x*b.x+a.y*b.y;}
	friend int operator ^ (const Point&a,const Point&b){return a.x*b.y-b.x*a.y;}
	friend Point operator + (const Point&a,const Point&b){return Point(a.x+b.x,a.y+b.y);}
	friend Point operator - (const Point&a,const Point&b){return Point(a.x-b.x,a.y-b.y);}
}a[MN+5],b[MN+5],P,Q;
bool Check(Point x,Point y,double len)
{
	if(x.len()<len&&y.len()<len) return false;
	if(x.len()<=len||y.len()<=len) return true;
	if(x.x==y.x&&x.y==y.y) return false;
	if((y-x)*Point(-x.x,-x.y)<0) return false;
	if((x-y)*Point(-y.x,-y.y)<0) return false;
	double dis=fabs(((y-x)^Point(-x.x,-x.y))/(x-y).len());
	return dis<=len;
}
int main()
{
	P.x=read();P.y=read();n=read();
	for(int i=1;i<=n;++i) a[i].x=read(),a[i].y=read();
	Q.x=read();Q.y=read();m=read();
	for(int i=1;i<=m;++i) b[i].x=read(),b[i].y=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(Check(a[i]-P+Q-b[j],a[i%n+1]-P+Q-b[j],(P-Q).len())) return 0*puts("YES");	
			if(Check(b[j]-Q+P-a[i],b[j%m+1]-Q+P-a[i],(P-Q).len())) return 0*puts("YES");
		}
	puts("NO");
	return 0;
}