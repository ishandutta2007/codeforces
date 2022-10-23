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
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}return s;
}
int n,m,t,a[1000002],ans,f[100002],g[100002],sum,fst;
vector<int>A,B;
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		re int num=0;fst=0;
		for(re int i=n;i;--i)if(a[i]==1)++num;
		re int o=0;
		for(re int i=1;i<=n-num;++i)if(a[i]==1)++o;
		num=o;
		sum=(1ll*n*(n-1)>>1)%M;
		int iv=ksm(sum,M-2);
		for(re int i=1;i<=num;++i){
			f[i]=f[i-1];
			add(f[i],1ll*sum*ksm(1ll*i*i%M,M-2)%M);
		}
		printf("%d\n",f[num]);
	}
}