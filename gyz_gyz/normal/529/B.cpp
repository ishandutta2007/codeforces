#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 2001
using namespace std;
int a[mx],b[mx],c[mx],d[mx],n,m,p,x,r,w,u,ans;
inline bool cmp(int x,int y){return x>y;}
int main(){
	scanf("%d",&n);ans=1000000000;
	rep(i,1,n)scanf("%d%d",&a[i],&b[i]);
	rep(i,1,n){
		c[++m]=a[i];c[++m]=b[i];
	}
	sort(c+1,c+m+1,cmp);
	rep(i,1,m){
		rep(j,1,n)if(a[j]>c[i]&&b[j]>c[i]){u=1;break;}
		if(u)break;p=0;x=0;
		rep(j,1,n)if(b[j]>c[i])p++,x+=b[j];else x+=a[j];
		if(p>n/2)break;r=0;
		rep(j,1,n)if(a[j]>b[j]&&a[j]<=c[i])d[++r]=a[j]-b[j];
		sort(d+1,d+r+1,cmp);
		if(n/2-p>r)w=r;else w=n/2-p;
		rep(j,1,w)x-=d[j];
		if(c[i]*x<ans)ans=c[i]*x;
	}
	printf("%d\n",ans);
}