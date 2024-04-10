#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200000
using namespace std;
int n,x,u,tt[N];long long T,T0,T1,t0[N],t1[N];double l,r,m,P,pt[N];
struct pr{long long p,t;int id;}a[N];
inline bool cmp0(const pr &x,const pr &y){return x.p<y.p;}
inline bool cmp(const pr &x,const pr &y){return x.p*y.t>y.p*x.t;}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&a[i].p);
	rep(i,1,n)scanf("%I64d",&a[i].t);
	rep(i,1,n)T+=a[i].t;
	sort(a+1,a+n+1,cmp0);rep(i,1,n)a[i].id=i;
	sort(a+1,a+n+1,cmp);rep(i,1,n)tt[a[i].id]=i;
	l=0;r=1;m=0.5;T0=T1=0;
	rep(i,1,n){
		if(a[i].p*a[i-1].t!=a[i-1].p*a[i].t)T0=T1;
		T1+=a[i].t;t0[i]=T0+a[i].t;
	}T0=T1=T;
	dep(i,n,1){
		if(a[i].p*a[i+1].t!=a[i+1].p*a[i].t)T0=T1;
		T1-=a[i].t;t1[i]=T0;
	}
	for(;r-l>1e-12;m=(l+r)/2){
		rep(i,1,n){
			P=a[tt[i]].p*(1-m*t0[tt[i]]/T);
			pt[i]=pt[i-1];if(P>pt[i])pt[i]=P;
		}x=n;u=1;
		dep(i,n,1){
			while(a[tt[x]].p>=a[tt[i]].p)x--;
			P=a[tt[i]].p*(1-m*t1[tt[i]]/T);
			if(P<pt[x]){u=0;break;}
		}
		if(u)l=m;else r=m;
	}
	printf("%.11lf\n",m);
}