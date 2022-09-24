#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0l),eps=1e-8;
int n,R,is[3005][3005],ans=0;
struct point{int x,y;}a[3005];
double l[3005],r[3005],ang[3005];
ll Dot(point x,point y){return 1ll*x.x*y.x+1ll*x.y*y.y;}
ll Cross(point x,point y){return 1ll*x.x*y.y-1ll*x.y*y.x;}
ll Dis(point x,point y){return 1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y);}
point operator +(point x,point y){return {x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
int main(){
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		double curl=-1e9,curr=1e9;
		bool in0=1,notin0=1;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			point p=a[j]-a[i];
			double A=atan2(p.y,p.x);
			ang[j]=A;
			if(ang[j]<0)ang[j]+=2*pi;
			if(Dis(a[i],a[j])<=1ll*R*R)continue;
			double dlt=asin(R/sqrt(Dis(a[i],a[j])));
			double l=A-dlt,r=A+dlt;
			if(r<0)l+=2*pi,r+=2*pi;
			if(r>2*pi)l-=2*pi,r-=2*pi;
			if(l>0){
				if(curr<l-eps)curl+=2*pi,curr+=2*pi;
				curl=max(curl,l),curr=min(curr,r);
			}
			else {
				if(curl>r+eps)curl-=2*pi,curr-=2*pi;
				curl=max(curl,l),curr=min(curr,r);
			}
			//cout<<l<<' '<<r<<' '<<curl<<' '<<curr<<'\n';
		}
		if(curl>pi)curl-=2*pi,curr-=2*pi;
		curl-=eps,curr+=eps;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			bool ok=(ang[j]>=curl&&ang[j]<=curr)||(ang[j]>=curl+2*pi&&ang[j]<=curr+2*pi);
			if(ok)is[min(i,j)][max(i,j)]++;//cout<<i<<' '<<j<<'\n';
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(is[i][j]==2)ans++;
	cout<<ans;
}