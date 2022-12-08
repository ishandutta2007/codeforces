#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const double PI=acos(-1),eps=1e-6;
int x[N],y[N],n;
struct node {
	double a;
	int v;
	node(){}
	node(double A,int V) {
		a=A,v=V;
	}
	int operator<(const node &A) const{
		return a<A.a;
	}
}p[4*N];
int calc(double r) {
	int sum=0,m=0;
	for(int i=1;i<=n;i++)
		if(!x[i]&&!y[i])sum++;
		else {
			double d=sqrt(1ll*x[i]*x[i]+1ll*y[i]*y[i]);
			if(d>2*r)continue;
			double th=atan2(x[i],y[i]),a=acos(d/(2*r));
			p[++m]=node(th-a,1);
			p[++m]=node(th+a,-1);
			p[++m]=node(th-a+2*PI,1);
			p[++m]=node(th+a+2*PI,-1);
		}
	sort(p+1,p+m+1);
	int Max=0,s=0;
	for(int i=1;i<=m;i++) {
		s+=p[i].v;
		Max=max(Max,s);
	}
	return Max+sum;
}
int main() {
	int k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	double l=0,r=2e5;
	while(r-l>eps) {
		double mid=(l+r)/2;
		if(calc(mid)>=k)r=mid;
		else l=mid;
	}
	printf("%.10f\n",l);
	return 0;
}