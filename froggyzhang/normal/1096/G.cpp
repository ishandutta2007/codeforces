#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2000100
const int mod=998244353;
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
int n,k,f[N],t,inv[N],g[N],ans;
int main(){
	n=read()>>1,k=read();
	if(k==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=k;++i){
		int x=read();
		f[x]=1;
		t=max(t,x);
	}
	int dig=0;
	while(!f[dig])++dig;
	for(int i=0;i<t;++i){
		f[i]=f[i+dig];
	}
	t-=dig;
	int mx=t*n;
	inv[1]=1;
	for(int i=2;i<=mx;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
	g[0]=1;
	ans=1;
	for(int i=0;i<mx;++i){
		for(int j=0;j<=min(i,t-1);++j){
			g[i+1]=(g[i+1]+1LL*n*f[j+1]%mod*(j+1)%mod*g[i-j]%mod)%mod;
		}
		for(int j=1;j<=min(i,t);++j){
			g[i+1]=(g[i+1]-1LL*f[j]*g[i-j+1]%mod*(i-j+1)%mod+mod)%mod;
		}
		g[i+1]=1LL*g[i+1]*inv[i+1]%mod;
		ans=(ans+1LL*g[i+1]*g[i+1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}