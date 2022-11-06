#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5010
#define ll long long
using namespace std;
struct node{
	ll x,y;
	node(ll X=0,ll Y=0):x(X),y(Y){}
	bool operator <(const node a)const{return x==a.x?y<a.y:x<a.x;}
	node operator +(node a){return node(x+a.x,y+a.y);}
	node operator -(node a){return node(x-a.x,y-a.y);}
	ll operator *(node a){return x*a.y-y*a.x;}
}p[N],q[N],a,b,c;
ll cross(node x,node o,node y){return (x-o)*(y-o);}
int t;
void print(node a){printf("%lld %lld\n",a.x,a.y);}
int main()
{
	int n;
	ll s;
	scanf("%d%lld",&n,&s);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		for(;t>1 && cross(q[t],q[t-1],p[i])<=0;t--);
		q[++t]=p[i];
	}
	int s0=t;
	for(int i=n-1;i>=1;i--)
	{
		for(;t>s0 && cross(q[t],q[t-1],p[i])<=0;t--);
		q[++t]=p[i];
	}
	--t;
	ll sm=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1,k=j%t+1;j<=t && k!=i;j++)
		{
			for(;cross(q[j],q[i],q[k])<cross(q[j],q[i],q[k+1]);k=k%t+1);
			if(k!=i && k!=j && cross(q[j],q[i],q[k])>sm) sm=cross(q[j],q[i],q[k]),a=q[i],b=q[j],c=q[k];
		}
	print(a-c+b),print(b-a+c),print(c-b+a);
	return 0;
}