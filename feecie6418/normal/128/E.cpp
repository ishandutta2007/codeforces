#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps=1e-9,pi=acos(-1.0l);
struct point{db x,y;void in(){cin>>x>>y;}};
db Dot(point x,point y){return x.x*y.x+x.y*y.y;}
db Cross(point x,point y){return x.x*y.y-x.y*y.x;}
db Dis(point x,point y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
point operator +(point x,point y){return {x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
point operator *(db x,point y){return {x*y.x,x*y.y};}
point operator *(point y,db x){return {x*y.x,x*y.y};}
// 
point Rotate(point x,db y){return {x.x*cos(y)-x.y*sin(y),x.y*cos(y)+x.x*sin(y)};}
struct circle{point o;int r;}a[1005];
int n,K,cnt[1005],m;
struct T{db x;int id;}t[6005];
void Add(db l,db r,int id){
	r-=eps;
	//printf("%.12lf %.12lf %d\n",l,r,id);
	l-=floor(l/(2*pi))*(2*pi);
	r-=floor(r/(2*pi))*(2*pi);
	if(l<=r)t[++m]={l,id},t[++m]={r,-id};
	else t[++m]={l,id},t[++m]={0,id},t[++m]={r,-id};
}
int main(){
	cin>>n>>K;
	int ans=1;
	for(int i=1;i<=n;i++)cin>>a[i].o.x>>a[i].o.y>>a[i].r;
	for(int i=1;i<=n;i++){
		m=0;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			cnt[j]=0;
			point vec=a[j].o-a[i].o;
			db ang=atan2(vec.y,vec.x);
			db dis=Dis(a[i].o,a[j].o),a1=asin((a[j].r-a[i].r)/dis),a2=asin((a[j].r+a[i].r)/dis);
			Add(ang-a2,ang+a1,j);
			Add(ang+pi-a1,ang+pi+a2,j);
		}
		sort(t+1,t+m+1,[](T x,T y){return x.x<y.x;});
		int s=1;
		for(int j=1;j<=m;j++){
			if(t[j].id<0){
				cnt[-t[j].id]--;
				if(!cnt[-t[j].id])s--;
			}
			else {
				if(!cnt[t[j].id])s++;
				cnt[t[j].id]++;
			}
			ans=max(ans,s);
			//cout<<j<<' '<<t[j].x<<' '<<s<<'\n';
		}
		//cout<<i<<' '<<ans<<'\n';
	}
	cout<<ans*K+1ll*K*(K-1)/2+n;
}