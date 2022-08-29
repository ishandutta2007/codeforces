#include<bits/stdc++.h>
#define re register
#define int __int128
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
int t,n,m,a[1000002],ans,A,B;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		n=read();
		int m=n,pw=1;
		while(m%2==0)m>>=1,pw<<=1;
		if((pw*2)*(pw*2-1)/2<n)printf("%lld\n",(long long)pw*2);
		else if(m^1)printf("%lld\n",(long long)m);
		else puts("-1");
	}
}