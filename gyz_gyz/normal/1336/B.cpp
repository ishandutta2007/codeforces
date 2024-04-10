#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=3e18;
const int mo=998244353;
int a[N],b[N],c[N];
ll cal(ll x,ll y,ll z){
	return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}
void sol(){int n1,n2,n3;ll ans=inf;
	scanf("%d%d%d",&n1,&n2,&n3);
	rep(i,1,n1)scanf("%d",&a[i]);
	rep(i,1,n2)scanf("%d",&b[i]);
	rep(i,1,n3)scanf("%d",&c[i]);
	sort(a+1,a+n1+1);
	sort(b+1,b+n2+1);
	sort(c+1,c+n3+1);
	int x=1,y=1;
	rep(i,1,n1){
		while(x<=n2&&a[i]>b[x])++x;
		while(y<=n3&&a[i]>c[y])++y;
		if(x>1&&y<=n3)ans=min(ans,cal(a[i],b[x-1],c[y]));
		if(y>1&&x<=n2)ans=min(ans,cal(a[i],b[x],c[y-1]));
	}x=1,y=1;
	rep(i,1,n2){
		while(x<=n1&&b[i]>=a[x])++x;
		while(y<=n3&&b[i]>c[y])++y;
		if(x>1&&y<=n3)ans=min(ans,cal(a[x-1],b[i],c[y]));
		if(y>1&&x<=n1)ans=min(ans,cal(a[x],b[i],c[y-1]));
	}x=1,y=1;
	rep(i,1,n3){
		while(x<=n1&&c[i]>=a[x])++x;
		while(y<=n2&&c[i]>=b[y])++y;
		if(x>1&&y<=n2)ans=min(ans,cal(a[x-1],b[y],c[i]));
		if(y>1&&x<=n1)ans=min(ans,cal(a[x],b[y-1],c[i]));
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}