#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2e6,mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){
	return x<mod?x:x-mod;
}
void Add(int&x,int y){x=Mod(x+y);}
int n,ans,s,a[20],f[1<<20],size[1<<20],inv[2000005];
int solve(int A,int B){
	int ans=1;
	for(int i=1;i<=n;++i){
		if(A&(1<<i-1)){
			for(int j=1;j<=n;++j){
				if(B&(1<<j-1)){
					ans=1ll*ans*a[i]%mod*inv[a[i]+a[j]]%mod;
				}
			}
		}
	}
	return ans;
}
int main(){
	inv[1]=1;for(int i=2;i<=N;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	f[0]=1;s=(1<<n)-1;
	for(int i=1;i<(1<<n);++i){
		f[i]=1;size[i]=size[i>>1]+(i&1);
		for(int j=(i-1)&i;j;j=(j-1)&i){
			Add(f[i],mod-1ll*f[j]*solve(j,i-j)%mod);
		}
		Add(ans,1ll*f[i]*size[i]%mod*solve(i,s-i)%mod);
	}
	cout<<ans<<"\n";
	return 0;
}