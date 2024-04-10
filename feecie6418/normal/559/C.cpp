#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;
int n,m,k,jc[200005]={1},ny[200005]={1},f[2005];
struct P{
	int x,y;
}a[2005];
int Power(int x,int y,int mod) {
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
int C(int x,int y){
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
} 
int M(int i,int j,int x,int y){
	return C(x-i+y-j,x-i);
}
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+m;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n+m]=Power(jc[n+m],mod-2,mod);
	for(int i=n+m-1;i>=1;i--)ny[i]=1ll*(i+1)*ny[i+1]%mod;
	for(int i=1;i<=k;i++)cin>>a[i].x>>a[i].y;
	a[++k].x=1,a[k].y=1;
	a[++k].x=n,a[k].y=m;
	sort(a+1,a+k+1,[](P i,P j){return i.x^j.x?i.x<j.x:i.y<j.y;});
	f[1]=1;
	for(int i=2;i<=k;i++){
		f[i]=M(1,1,a[i].x,a[i].y);
		for(int j=2;j<i;j++){
			if(a[j].y>a[i].y)continue;
			f[i]=(f[i]-1ll*f[j]*M(a[j].x,a[j].y,a[i].x,a[i].y)%mod+mod)%mod;
		}
	}
	cout<<f[k];
	return 0;
}