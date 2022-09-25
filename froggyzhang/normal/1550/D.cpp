#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
inline ll read(){
	ll x=0,f=1;
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
int T,n,l,r,fac[N],ifac[N];
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
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void Solve(){
	n=read(),l=read()-1,r=read()-n;
	int t=n>>1;
	int ans=2LL*min(-l,r)*C(n,t)%mod;
	for(int i=min(-l,r)+1;;++i){
		int a=n-max(0,l+i),b=n-max(0,i-r);
		if(a<t||b<t)break;
		int c=a+b-n;
		a-=c,b-=c;
		ans=((ans+C(c,t-a))%mod+C(c,n-t-a))%mod;
	}
	if(n%2==0)ans=1LL*ans*(mod+1)/2%mod;
	printf("%d\n",ans);
}
int main(){
	init(200000);
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}