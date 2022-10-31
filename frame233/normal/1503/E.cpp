#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2025,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll fac[N+N],inv[N+N],ifac[N+N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N+N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int f[N][N],g[N][N];
int main(){
	init();
	int n,m,ans=0;read(n,m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]=C(i+j-2,i-1)*C(i+m-j,i)%mod;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)g[i][j]=C(n-(i-1)+j-1,j-1)*C(n-i+m-j,n-i)%mod;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)add(g[i][j],g[i][j-1]);
	for(int i=1;i<n;++i)for(int j=1;j<=m;++j)add(ans,1LL*f[i][j]*g[i+1][j-1]%mod);
	std::swap(n,m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)f[i][j]=C(i+j-2,i-1)*C(i+m-j,i)%mod;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)g[i][j]=C(n-(i-1)+j-1,j-1)*C(n-i+m-j,n-i)%mod;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)add(g[i][j],g[i][j-1]);
	for(int i=1;i<n;++i)for(int j=2;j<=m;++j)add(ans,1LL*f[i][j]*g[i+1][j-2]%mod);
	printf("%d\n",2*ans%mod);
	return 0;
}