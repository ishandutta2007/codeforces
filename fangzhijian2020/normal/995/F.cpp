#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
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
int n,m,N,ans,fa[3005],fac[3005],ifac[3005];
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int C(int n,int m){
	if(n<m)return 0;
	if(n<=N)return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
	int ans=ifac[m];for(int i=0;i<m;++i)ans=1ll*ans*(n-i)%mod;
	return ans;
}
int h[3005],cnt,f[3005][3005],s[3005][3005],g[3005];
struct edge{int to,next;}e[3005];
void add(int x,int y){e[++cnt]=(edge){y,h[x]};h[x]=cnt;}
void dfs(int x){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;dfs(y);
		for(int j=1;j<=N;++j){
			f[x][j]=1ll*f[x][j]*s[y][j]%mod;
		}
	}
	for(int j=1;j<=N;++j)s[x][j]=Mod(s[x][j-1]+f[x][j]);
}
int main(){
	n=read();m=read();for(int i=2;i<=n;++i){fa[i]=read();add(fa[i],i);}
	N=min(n,m);fac[0]=1;for(int i=1;i<=N;++i)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N]=ksm(fac[N],mod-2);for(int i=N;i;--i)ifac[i-1]=1ll*ifac[i]*i%mod;
	for(int i=1;i<=n;++i)for(int j=1;j<=N;++j)f[i][j]=1;dfs(1);
	for(int i=1;i<=N;++i){
		g[i]=f[1][i];
		for(int j=1;j<i;++j){
			Add(g[i],mod-1ll*g[j]*C(i-1,j-1)%mod);
		}
	}
	for(int i=1;i<=N;++i){Add(ans,1ll*g[i]*C(m,i)%mod);}
	cout<<ans;
	return 0;
}