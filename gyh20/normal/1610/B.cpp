#include<bits/stdc++.h>
#define re register
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
int t,n,m,a[1000002],ans,b[1000002],num;
inline void ck(re int x){
	m=0;
	for(re int i=1;i<=n;++i)if(a[i]^x)b[++m]=a[i];
	re int l=1,r=m;
	while(l<=r&&b[l]==b[r])++l,--r;
	if(l>=r)ans=1;
}
int main(){
	t=read();
	while(t--){
		n=read();ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		re int L=1,R=n;
		while(a[L]==a[R]&&L<=R)++L,--R;
		if(L>=R)puts("YES");
		else{
			ck(a[L]),ck(a[R]);
			puts(ans?"YES":"NO");
		}
		
	}
}