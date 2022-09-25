#include<bits/stdc++.h>
using namespace std;
#define N 10005
const int mod=998244353;
typedef long long ll;
int n,m,R,fac[N],ifac[N],inv[N];
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
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;	
	}
}
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
inline int calc(int n,int m){
	if(!n&&!m)return 1;
	return C(n+m-1,n-1);	
}
int Solve(int n,int m,int lim){
	int ans=0;
	for(int i=0;i<=n&&m>=0;++i){
		ans=(ans+1LL*(i&1?mod-C(n,i):C(n,i))*calc(n,m))%mod;
		m-=lim;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>R;
	init(n+m);
	int A=0,B=0;
	B=calc(n,m-R);
	for(int i=R;i<=m;++i){
		for(int j=1;j<=n;++j){
			A=(A+1LL*inv[j]*Solve(n-j,m-i*j,i)%mod*C(n-1,j-1))%mod;	
		}
	}
	cout<<1LL*A*qpow(B,mod-2)%mod<<'\n';
	return 0;
}