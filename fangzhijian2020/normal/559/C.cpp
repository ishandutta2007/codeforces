#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int fac[200005],ifac[200005];
int C(int n,int m){return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int H,W,n,f[2005][2];
struct node{
	int x,y;
	bool operator<(const node &a)const{
		if(x==a.x)return y<a.y;
		return x<a.x;
	}
}a[2005];
int main(){
	scanf("%d%d%d",&H,&W,&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	fac[0]=1;for(int i=1;i<=H+W;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[H+W]=ksm(fac[H+W],mod-2);for(int i=H+W;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	a[++n]=(node){1,1};a[++n]=(node){H,W};sort(a+1,a+n+1);f[1][1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<i;++j){
			if(a[j].y<=a[i].y){
				f[i][0]=(f[i][0]+1ll*f[j][1]*C(a[i].x-a[j].x+a[i].y-a[j].y,a[i].y-a[j].y)%mod)%mod;
				f[i][1]=(f[i][1]+1ll*f[j][0]*C(a[i].x-a[j].x+a[i].y-a[j].y,a[i].y-a[j].y)%mod)%mod;	
			}
		}
	}
	printf("%d\n",(f[n][0]-f[n][1]+mod)%mod);
	return 0;
}