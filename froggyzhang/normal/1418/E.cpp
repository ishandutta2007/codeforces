#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 400010
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
int a[N],b[N],d[N],n,m,num[N],len,sum[N],tot[N],inv[N];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		d[i]=read();
		num[++len]=d[i];
	}
	for(int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
		num[++len]=b[i];
	}
	sort(num+1,num+len+1);
	len=unique(num+1,num+len+1)-num-1;
	for(int i=1;i<=n;++i){
		int t=lower_bound(num+1,num+len+1,d[i])-num;
		sum[t]=(sum[t]+d[i])%mod;
		++tot[t];
	}
	for(int i=len-1;i>=1;--i){
		sum[i]=(sum[i]+sum[i+1])%mod;
		tot[i]+=tot[i+1];
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=1;i<=m;++i){
		int t=lower_bound(num+1,num+len+1,b[i])-num;
		int k=tot[t];
		int ans=0;
		if(k+1>a[i])ans=(ans+1LL*inv[k+1]*(k+1-a[i])%mod*(sum[1]-sum[t]))%mod;
		if(k>a[i])ans=(ans+1LL*inv[k]*(k-a[i])%mod*sum[t])%mod;
		printf("%d\n",(ans+mod)%mod);
	}
	return 0;
}