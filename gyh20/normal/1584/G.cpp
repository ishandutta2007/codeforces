#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const double PI=acos(-1);
int n,m,R,ans;
struct point{int x,y;}p[3002];
char u[3002][3002];
inline double dis(re point x,re point y){return sqrt(1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y));}
int main(){
	n=read(),R=read();
	for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read();
	for(re int i=1;i<=n;++i){
		re double L1=PI,R1=-PI,L2=PI,R2=-PI;
		for(re int j=1;j<=n;++j)
			if(dis(p[i],p[j])>R){
				re double K=atan2(p[j].y-p[i].y,p[j].x-p[i].x),D=asin(R/dis(p[i],p[j])),l=K-D,r=K+D;
				if(l>=-PI&&r<=PI)L1=min(L1,r),L2=min(L2,r),R1=max(R1,l),R2=max(R2,l);
				else if(l<-PI)L1=min(L1,r),R2=max(R2,l+PI+PI);
				else L1=min(L1,r-PI-PI),R2=max(R2,l);
			}
		for(re int j=1;j<=n;++j){
			re double K=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
			if((K>=R1&&K<=L1)||(K>=R2&&K<=L2))u[i][j]=1;
		}
	}
	for(re int i=1;i<=n;++i)
		for(re int j=i+1;j<=n;++j)
			 ans+=u[i][j]&&u[j][i];
	printf("%d",ans);
}