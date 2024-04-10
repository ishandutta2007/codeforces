#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
typedef long long ll;
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
int n,Q,fac[N],ifac[N],pw2[N],sum;
char s[N];
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
	fac[0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<m||m<0||n<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int x,y,g0,g1;
const int inv2=(mod+1)/2;
int c_g0(){
	int tot=0;
	for(int i=0;i<=min(-x,y-1);++i){
		tot=(tot+2LL*(-x)*C(y-1,i))%mod;
	}
	return tot;
}
int c_g1(){
	int tot=0;
	if(y==1){
		if((-x)>=1&&x%2)tot=(tot+mod-2)%mod;
	}
	else{
		for(int i=0;i<=min(-x,y-1);++i){
			tot=(tot+2LL*(-y)*C(y-2,i-1))%mod;
		}	
	}
	return tot;
}
int qcnt;
void Change(int opt,int z){
	if(opt==0)x+=z;
	else y+=z;
	if(qcnt<=3){
		g0=c_g0();
		g1=c_g1();
		sum=(g0+g1)%mod;
	sum=(sum+mod)%mod;
		return;
	}
	if((-x)<=10||y<=10){
		g0=c_g0();
		g1=c_g1();
	}
	else{
		if(opt==0){
			g0=1LL*qpow(abs(-x+z),mod-2)*abs(-x)%mod*g0%mod;
			if(z==1)g0=(g0-2LL*(-x)*C(y-1,-x+z))%mod;
			else g0=(g0+2LL*(-x)*C(y-1,-x))%mod;
			if(z==1)g1=(g1-2LL*(-y)*C(y-2,-x+z-1))%mod;
			else g1=(g1+2LL*(-y)*C(y-2,-x-1))%mod;
		}
		else{
			if(z==1)g0=(2*g0-2LL*(-x)*C(y-1-z,-x))%mod,g1=(2*g1-2LL*(-y+z)*C(y-2-z,-x-1))%mod;
			else g0=(g0+2LL*(-x)*C(y-1,-x))%mod*inv2%mod,g1=(g1+2LL*(-y+z)*C(y-2,-x-1))%mod*inv2%mod;
			g1=1LL*qpow(abs(-y+z),mod-2)*abs(-y)%mod*g1%mod;
		}
	}
	sum=(g0+g1)%mod;
	sum=(sum+mod)%mod;
}
int calc(){
	int ans=sum;
	ans=(ans+(y==0?(x%2==0?x:0):1LL*x*pw2[y-1]))%mod;
	ans=(ans+(y<2?(y==1&&(x-1)%2==0?y:0):1LL*y*pw2[y-2]))%mod;
	ans=(ans+mod)%mod;
	ans=1LL*ans*qpow(pw2[y],mod-2)%mod;
	if(!y)ans=1LL*ans*inv2%mod;
	return ans;
}
int main(){
	n=read(),Q=read();
	init(n);
	scanf("%s",s+1);
	int A=0,B=0,t=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='?')i&1?++A:++B;
		else if(s[i]=='b')i&1?++t:--t;
	}
	x=t-B,y=A+B;
	g0=c_g0();
	g1=c_g1();
	sum=(g0+g1)%mod;
	printf("%d\n",calc());
	while(Q--){
		++qcnt;
		int p=read();
		char c;
		do{c=getchar();}while(c!='w'&&c!='b'&&c!='?');
		if(s[p]=='?')p&1?Change(1,-1):(Change(1,-1),Change(0,1));
		else if(s[p]=='b')p&1?Change(0,-1):Change(0,1);
		s[p]=c;
		if(s[p]=='?')p&1?Change(1,1):(Change(1,1),Change(0,-1));
		else if(s[p]=='b')p&1?Change(0,1):Change(0,-1);
		printf("%d\n",calc());	
	}
	return 0;
}