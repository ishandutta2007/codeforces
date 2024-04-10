#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100010
#define ll long long
using namespace std;
struct point{
	ll x,y;
	int id;
	point (ll X=0,ll Y=0):x(X),y(Y){}
	point operator +(const point a)const{return point(x+a.x,y+a.y);}
	point operator -(const point a)const{return point(x-a.x,y-a.y);}
	ll operator ^(const point a)const{return x*a.y-y*a.x;}
	ll operator *(const point a)const{return x*a.x+y*a.y;}
}p[N];
ll dis(point a){return a.x*a.x+a.y*a.y;}
bool cmp(point a,point b)
{
	if(a.y*b.y<0) return b.y<0;
	return (a^b)>0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].x,&p[i].y),p[i].id=i;
	sort(p+1,p+n+1,cmp);
	p[++n]=p[1];
	__int128 ans;
	int a1=0;
	for(int i=2;i<=n;i++)
	if(!a1 || ans*dis(p[i])*dis(p[i-1])<(__int128)(p[i]*p[i-1])*(p[i]*p[i-1])*((p[i]*p[i-1])<0?-1:1)*dis(p[a1])*dis(p[a1-1]))
	{
		ans=(p[i]*p[i-1])*(p[i]*p[i-1])*((p[i]*p[i-1])<0?-1:1);
		a1=i;
	}
	printf("%d %d\n",p[a1].id,p[a1-1].id);
	return 0;
}