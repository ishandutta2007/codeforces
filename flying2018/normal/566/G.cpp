#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
#define ll long long
using namespace std;
struct node{
	ll x,y;
	node(ll X=0,ll Y=0):x(X),y(Y){}
	node operator +(const node a)const{return node(x+a.x,y+a.y);}
	node operator -(const node a)const{return node(x-a.x,y-a.y);}
	ll operator *(const node a)const{return x*a.y-y*a.x;}
	bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;}
}p[N],q[N],s[N];
ll cross(node a,node o,node b){return (a-o)*(b-o);}
int main()
{
	int n,m;
	scanf("%d%d%*d%*d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&q[i].x,&q[i].y);
	for(int i=1;i<=m;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
	sort(p+1,p+m+1);
	int t=0;
	for(int i=1;i<=m;i++)
	{
		while(t && s[t].x<=p[i].x && s[t].y<=p[i].y) --t;
		while(t>1 && cross(s[t],s[t-1],p[i])>=0) --t;
		s[++t]=p[i];
	}
	s[0].x=0,s[0].y=s[1].y;
	s[t+1].x=s[t].x,s[t+1].y=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=t,ans=-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(q[i].x>=s[mid].x) ans=mid,l=mid+1;
			else r=mid-1;
		}
		if(ans==-1 || cross(q[i],s[ans],s[ans+1])<=0){puts("Max");return 0;}
	}
	puts("Min");
	return 0;
}