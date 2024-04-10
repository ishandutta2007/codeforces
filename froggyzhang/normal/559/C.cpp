#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 200020
const ll mod=1e9+7;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int w,h,n;
ll dp[N],fac[N],inv[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
struct Point{
	int x,y;
	bool operator <(const Point b)const{
		return x==b.x?y<b.y:x<b.x;
	}
}a[N];
int main(){
	h=read(),w=read(),n=read();
	init(w+h+1);
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
	}
	a[++n].x=h,a[n].y=w;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dp[i]=C(a[i].x+a[i].y-2,a[i].x-1);
		for(int j=1;j<i;j++){
			if(a[j].x<=a[i].x&&a[j].y<=a[i].y){
				dp[i]=(dp[i]-dp[j]*C(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x)%mod+mod)%mod;
			}
		}
	} 
	printf("%I64d\n",dp[n]);
	return 0;
}