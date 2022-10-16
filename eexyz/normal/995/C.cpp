#include<bits/stdc++.h>
using namespace std;
#define N 100004
int n,i,j,pos,fl,x,cnt,X,Y,fa[N],ans[N],vis[N];
struct vec{int x,y,pos;}a[N],b[10];
vec operator + (vec aa,vec bb){
	aa.x+=bb.x;
	aa.y+=bb.y;
	return aa;
}
vec operator - (vec aa,vec bb){
	aa.x-=bb.x;
	aa.y-=bb.y;
	return aa;
}
bool pd(vec aa){
//	cout<<aa.x<<" "<<aa.y<<"\n";
	return (1ll*aa.x*aa.x+1ll*aa.y*aa.y)<=1000000000000ll;
}
bool Pd(vec aa){
	return (1ll*aa.x*aa.x+1ll*aa.y*aa.y)<=2250000000000ll;
}
int main(){
	cin>>n;
	for(i=1;i<=n;++i)cin>>a[i].x>>a[i].y,a[i].pos=i;
	for(i=1;i<=n;++i){
		for(fl=j=1;j<=cnt;++j){
			if(pd(a[i]+b[j])){
				x=b[j].pos;
				b[j]=b[j]+a[i];
				b[j].pos=x;
				fl=0;
				fa[i]=b[j].pos;
				break;
			}
			if(pd(b[j]-a[i])){
				x=b[j].pos;
				b[j]=b[j]-a[i];
				b[j].pos=x;
				fl=0;
				fa[i]=b[j].pos;vis[i]=1;
				break;
			}
		}
		if(fl)b[++cnt]=a[i],ans[i]=i;
		if(cnt==2&&pd(b[1]+b[2])){
			fa[b[2].pos]=b[1].pos;
			b[1]=b[1]+b[2];
			--cnt;
		}
		if(cnt==2&&pd(b[1]-b[2])){
			fa[b[2].pos]=b[1].pos;
			vis[b[2].pos]=1;
			b[1]=b[1]-b[2];
			--cnt;
		}
	}
	if(cnt>2){
		while(1);
	}
//	cout<<b[1].x<<" "<<b[1].y<<' '<<b[2].x<<" "<<b[2].y<<"\n";
	if(Pd(b[1]+b[2])){
		fa[b[2].pos]=b[1].pos;
	}
	else fa[b[2].pos]=b[1].pos,vis[b[2].pos]=1;
	for(i=1;i<=n;++i){
//		cout<<fa[i]<<"++";
		vis[i]+=vis[fa[i]];
		if(vis[i]&1)cout<<"-1 ",X-=a[i].x,Y-=a[i].y;
		else cout<<"1 ",X+=a[i].x,Y+=a[i].y;
//		cout<<X<<" "<<Y<<"\n";
	}
}