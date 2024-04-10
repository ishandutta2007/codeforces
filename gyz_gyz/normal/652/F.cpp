#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 500000
using namespace std;
int n,m,s1,t1,s2,t2,sr,nw,x,ti,T;
int l[N],r[N],tt[N];long long t;char ch;
struct pr{int x,p,id;}a[N];
inline bool cmp(const pr &x,const pr &y){
	if(x.x==y.x)return x.p;else return x.x<y.x;
}
int main(){
	scanf("%d%d%I64d",&n,&m,&t);m*=2;t*=2;
	rep(i,1,n){
		scanf("%d",&a[i].x);a[i].x=a[i].x*2-1;ch=0;
		while(ch!='L'&&ch!='R')ch=getchar();
		a[i].p=(ch=='R');a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)tt[a[i].id]=i;
	rep(i,2,n)if(!a[i].p)l[++t1]=a[i].x;
	dep(i,n,2)if(a[i].p)r[++t2]=a[i].x-m;
	nw=a[1].p;x=a[1].x;s1=s2=1;
	if(nw&&!t1){
		rep(i,1,n)printf("%I64d ",((a[tt[i]].x+t)%m+1)/2);return 0;
	}
	if(!nw&&!t2){
		rep(i,1,n)printf("%I64d ",((a[tt[i]].x-t%m+m)%m+1)/2);return 0;
	}
	while(ti<m){
		if(nw)T=(l[s1]-ti-x)/2;else T=(x-r[s2]-ti)/2;
		if(ti+T>=m){
			if(nw)x=(x-ti)%m;else x=(x+ti)%m;break;
		}ti+=T;
		if(nw)x+=T,r[++t2]=l[s1]-ti*2-m,s1++;
		else x-=T,l[++t1]=r[s2]+ti*2+m,s2++;nw^=1;
	}
	while(x<0)x+=m;while(x>=m)x-=m;
	rep(i,1,n)if(x==a[i].x&&nw==a[i].p)sr=i-1;
	nw=a[1].p;x=a[1].x;s1=s2=1;t1=t2=ti=0;sr=sr*(t/m)%n;
	rep(i,2,n)if(!a[i].p)l[++t1]=a[i].x;
	dep(i,n,2)if(a[i].p)r[++t2]=a[i].x-m;
	while(ti<t%m){
		if(nw)T=(l[s1]-ti-x)/2;else T=(x-r[s2]-ti)/2;
		if(ti+T>=t%m){
			if(nw)x=x+t%m-ti;else x=(x+ti-t%m+m)%m;break;
		}ti+=T;
		if(nw)x+=T,r[++t2]=l[s1]-ti*2-m,s1++;
		else x-=T,l[++t1]=r[s2]+ti*2+m,s2++;nw^=1;
	}
	while(x<0)x+=m;while(x>=m)x-=m;
	rep(i,1,n)if(a[i].p)a[i].x=(a[i].x+t%m)%m;
	else a[i].x=(a[i].x-t%m+m)%m;
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)if(a[i].x==x&&a[i].p==nw)sr=(sr+i-1)%n;
	rep(i,1,n)printf("%d ",(a[(tt[i]+sr-1)%n+1].x+1)/2);
}