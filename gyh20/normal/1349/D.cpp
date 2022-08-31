#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int add(re int x,re int y){return ((x+=y)>=M)?x-M:x;}
int n,a[500002],m,b[500002],ans,inv[1000002],invmn,g[1000002],sum;
inline void addd(re int &x,re int y){(x+=y)>=M?x-=M:x;}
struct node{
	int k,b;
	node operator *(int a)const{return (node){1ll*k*a%M,1ll*b*a%M};}
	node operator +(node a)const{return (node){add(k,a.k),add(b,a.b)};}
	node operator -(node a)const{return (node){add(k,M-a.k),add(b,M-a.b)};}
	node operator /(int a)const{return (node){1ll*k*inv[a]%M,1ll*b*inv[b]%M};}
}f[1000002];
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
signed main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	n=read(),inv[1]=1;
	for(re int i=1;i<=n;++i)m+=(a[i]=read());
	if(m<=1)return puts("0"),0;
	for(re int i=2;i<=m;++i)inv[i]=1ll*(M-M/i)*inv[M%i]%M;
	f[m-1]=(node){1,0},invmn=ksm(1ll*m*(n-1)%M,M-2);
	for(re int i=m-1;i;--i)f[i-1]=(f[i]*(1ll*add(1,M-1ll*(m-i)*(n-2)%M*invmn%M))-f[i+1]*(1ll*(m-i)*invmn%M))*(1ll*m*inv[i]%M),f[i-1].b=add(f[i-1].b,M-1ll*m*inv[i]%M);
	re int K=add(f[0].k,M-f[1].k),B=add(f[0].b,M-f[1].b),X=add(n-1,M-B);
	X=1ll*X*ksm(K,M-2)%M;
	for(re int i=m;~i;--i)g[i]=add(1ll*f[i].k*X%M,f[i].b);
	for(re int i=1;i<=n;++i)addd(ans,g[a[i]]);
	addd(ans,M-1ll*(n-1)*g[0]%M);
	printf("%lld",1ll*ans*ksm(n,M-2)%M);
}