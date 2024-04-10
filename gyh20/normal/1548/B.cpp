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
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],GCD[22][200002],L[200002];
inline int Gcd(re int x,re int y){return y?Gcd(y,x%y):x;}
inline int ask(re int l,re int r){
	re int x=L[r-l+1];
	return Gcd(GCD[x][l],GCD[x][r-(1<<x)+1]);
}
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(); 
		for(re int i=1;i<n;++i)a[i]-=a[i+1];
		--n;
		for(re int i=1;i<=n;++i)if(a[i]<0)a[i]=-a[i];L[0]=-1;
		for(re int i=1;i<=n;++i)L[i]=L[i>>1]+1,GCD[0][i]=a[i];
		for(re int i=1;i<=20;++i)for(re int j=1;j+(1<<i)-1<=n;++j)GCD[i][j]=Gcd(GCD[i-1][j],GCD[i-1][j+(1<<i-1)]);
		re int pos=1;ans=1;
		for(re int i=1;i<=n;++i){
			while(pos<i)++pos;
			while(pos<=n&&ask(i,pos)!=1)++pos;
			ans=max(ans,pos-i+1);
		}
		printf("%lld\n",ans);
	}
}