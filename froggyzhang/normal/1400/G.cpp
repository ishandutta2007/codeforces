#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int mod=998244353;
#define N 300030
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
int cnt[N],n,m,l[N],r[N],a[23],b[23],tot;
int vis[N],ans;
int s[42][N];
int fac[N],inv[N];
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
	inv[n]=qpow(fac[n],mod-2)%mod;
	for(int i=n-1;i>=0;--i){
		inv[i]=1LL*inv[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<m)return 0;
	return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
    
	n=read(),m=read();
	init(n);
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
		++cnt[l[i]],--cnt[r[i]+1];
	}
	for(int i=1;i<=n;++i){
		cnt[i]+=cnt[i-1];
	}
	for(int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
	}
	tot=(1<<m)-1;
	for(int i=0;i<=tot;++i){
		int val=1,myh=0;
		int L=1,R=n;
		for(int j=1;j<=m;++j){
			vis[a[j]]=vis[b[j]]=0;
		}
		for(int j=1;j<=m;++j){
			if((i>>(j-1))&1){
				R=min(R,min(r[a[j]],r[b[j]]));
				L=max(L,max(l[a[j]],l[b[j]]));
				val=-val;
				if(!vis[a[j]])++myh;
				if(!vis[b[j]])++myh;
				vis[a[j]]=vis[b[j]]=1;
			}
		}
		if(L>R)continue;
		s[myh][L]+=val,s[myh][R+1]-=val;
	}
	for(int i=0;i<=40;++i){
		for(int j=1;j<=n;++j){
			s[i][j]=(s[i][j]+s[i][j-1])%mod;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<=min(i,40);++j){
			ans=(ans+1LL*s[j][i]*C(cnt[i]-j,i-j))%mod;
		}
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}