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
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		for(re int i=n-m+1;i<=n;++i)scanf("%lld",&a[i]);
		if(m==1){
			puts("Yes");
			continue;
		}
		for(re int i=n;i>n-m+1;--i)a[i]-=a[i-1];
		re bool ia=1;
		for(re int i=n;i>n-m+2;--i)ia&=a[i]>=a[i-1];
		re int o=a[n-m+2];
		if(o*(n-m+1)<a[n-m+1]||ia==0)puts("No");
		else puts("Yes");
	}
}