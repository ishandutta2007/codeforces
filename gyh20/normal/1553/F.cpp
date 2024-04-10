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
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],mx=300001,sum;
struct BIT{
	int c[300002];
	inline void add(re int x,re int y){++x;for(;x<=mx;x+=x&(-x))c[x]+=y;};
	inline int ask(re int x){
		++x;
		if(x<=0)return 0;
		x=min(x,mx);
		re int s=0;
		for(;x;x^=x&(-x))s+=c[x];
		return s;
	}
}T1,T2,T3;
signed main(){
	n=read();
	for(re int i=1;i<=n;++i){
		a[i]=read();
		for(re int j=0;j<=mx;j+=a[i]){
			re int s1=T1.ask(j+a[i]-1)-T1.ask(j-1),s2=T2.ask(j+a[i]-1)-T2.ask(j-1);
			ans+=s1-s2*j;
		}
		ans+=a[i]*(i-1);
		ans-=T3.ask(a[i]);
		T1.add(a[i],a[i]),T2.add(a[i],1);
		for(re int j=0;j<=mx;j+=a[i])T3.add(j,j),T3.add(j+a[i],-j);
		printf("%lld ",ans);
	}
}