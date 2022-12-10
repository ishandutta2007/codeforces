#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1),eps=1e-6;
const int N=3010;
int f[N][N];
struct node {
	int x,y;
	node(){}
	node(int X,int Y) {
		x=X,y=Y;
	}
	node operator-(const node &a)const {
		return node(x-a.x,y-a.y);
	}
	long long dis() {
		return 1ll*x*x+1ll*y*y;
	}
}p[N];
int main() {
	int n,R,ans=0;
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1;
	for(int i=1;i<=n;i++) {
		double aL=-PI,aR=PI,bL=-PI,bR=PI;
		for(int j=1;j<=n;j++) {
			if(i==j)continue;
			long long d=(p[i]-p[j]).dis();
			if(d<=1ll*R*R)continue;
			double th=asin(R/sqrt(d)),w=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
			if(-PI-eps<=w-th&&w+th<=PI+eps) {
				aL=max(aL,w-th),aR=min(aR,w+th);
				bL=max(bL,w-th),bR=min(bR,w+th);
			} else if(w-th<=-PI)aR=min(aR,w+th),bL=max(bL,w-th+2*PI);
			else aR=min(aR,w+th-2*PI),bL=max(bL,w-th);
		}
		for(int j=1;j<=n;j++) {
			if(i==j)continue;
			double w=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
			if((w<aL||aR<w)&&(w<bL||bR<w))
				f[i][j]=f[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans+=f[i][j];
	printf("%d\n",ans);
	return 0;
}