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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,a[1000002],k;
inline int ask(re int x,re int y){
	printf("or %lld %lld\n",x,y);
	fflush(stdout);
	re int s=read();
	printf("and %lld %lld\n",x,y);
	fflush(stdout);
	s+=read();
	return s;
}
signed main(){
	n=read(),k=read();
	for(re int i=2;i<=n;++i)a[i]=ask(1,i);
	re int x=ask(2,3);
	re int s=(a[2]+a[3]-x)/2;
	a[1]=s;
	for(re int i=2;i<=n;++i)a[i]-=a[1];
	sort(a+1,a+n+1);
	printf("finish %lld",a[k]);fflush(stdout);
}