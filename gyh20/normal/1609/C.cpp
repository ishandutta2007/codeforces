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
int t,n,m,a[1000002],A,B,b[1000002],f[1000002],g[1000002];
char s[1000002],v[1000002];
int main(){
	n=1e6;
	for(re int i=2;i<=n;++i)
		for(re int j=i+i;j<=n;j+=i)
			v[j]=1;
	t=read();
	while(t--){
		n=read(),m=read();
		long long ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		for(re int i=n;i;--i){
			if(v[a[i]])f[i]=g[i]=0;
			else if(a[i]==1){
				f[i]=g[i]=1;
				if(i+m<=n)f[i]=f[i+m]+1,g[i]=g[i+m]+1;
			}
			else{
				f[i]=0,g[i]=1;
				if(i+m<=n)g[i]=f[i+m]+1;
			}
			ans+=g[i]-f[i];
			if(f[i]==0&&g[i]>0)--ans;
		}
		printf("%lld\n",ans);
	}
}