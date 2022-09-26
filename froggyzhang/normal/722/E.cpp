#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
#define N 2020
#define M 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int fac[M<<1],inv[M<<1],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		inv[i]=1LL*inv[i+1]*(i+1)%mod;
	}
}
int C(int n,int m){
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int calc(int x,int y){
	return C(x+y,x);
}
int n,dp[N][24],S,k,m;
struct Point{
	int x,y;
	bool operator <(const Point b){
		return x==b.x?y<b.y:x<b.x;
	}
}a[N];
int main(){
	n=read(),m=read(),k=read(),S=read();
	init(n+m);
	for(int i=1;i<=k;++i){
		a[i].x=read(),a[i].y=read();
	}
	sort(a+1,a+k+1);
	a[0].x=1,a[0].y=1;
	a[++k].x=n,a[k].y=m;
	S<<=1;
	dp[0][0]=1;
	for(register int i=1;i<=k;++i){
		dp[i][0]=calc(a[i].x-1,a[i].y-1);
		for(int j=0;j<i;++j){
			if(a[i].x>=a[j].x&&a[i].y>=a[j].y){
				for(int p=1;p<=min(i,22);++p){
					dp[i][p]=(dp[i][p]+1LL*calc(a[i].x-a[j].x,a[i].y-a[j].y)*((dp[j][p-1]-dp[j][p]+mod)%mod))%mod;
				}
			}
		}
	}
	for(int i=1;i<=22;++i){
		S-=S>>1;
		ans=(ans+1LL*S*(dp[k][i]-dp[k][i+1]+mod))%mod;
	}
	ans=1LL*ans*qpow(calc(n-1,m-1),mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}