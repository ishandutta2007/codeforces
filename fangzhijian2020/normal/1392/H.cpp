#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
long long read(){
	long long a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;n>>=1;
	}
	return ans;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,m,N,inv[4000005],f[2000005],rd,sum;
int main(){
	n=read();m=read();N=n+m;
	inv[1]=1;for(int i=2;i<=N;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	f[0]=1;for(int i=1;i<=n;++i)f[i]=Mod(f[i-1]+1ll*m*inv[i]%mod);
	int tmp=1,tps=0;
	for(int i=1;i<=n+1;++i){
		Add(tps,1ll*tmp*m%mod*inv[n+m-i+1]%mod);
		Add(sum,1ll*tmp*i%mod*m%mod*inv[n+m-i+1]%mod);
		tmp=1ll*tmp*(n-i+1)%mod*inv[n+m-i+1]%mod;
	}
	cout<<1ll*sum*f[n]%mod<<"\n";
	return 0;
}