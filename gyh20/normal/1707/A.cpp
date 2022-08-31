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
int t,n,m,a[1000002],ans,A,B,f[1000002];
char s[1000002];
int main(){
	t=read();
	while(t--){
		n=read(),m=read(),ans=0;
		for(re int i=1;i<=n;++i)a[i]=read();
		f[n]=1;
		for(re int i=n-1;i;--i){
			f[i]=f[i+1]+1;
			if(f[i+1]>=a[i])f[i]=f[i+1];
		}
		int k=0,pos=0;
		for(re int i=1;i<=n;++i){
			if(f[i]<=m){
				if(n-i+1+k>ans)ans=n-i+1+k,pos=i;
			}
			k+=a[i]<=m;
		}
		for(re int i=1;i<pos;++i)if(a[i]<=m)putchar('1');else putchar('0');
		for(re int i=pos;i<=n;++i)putchar('1');
		puts("");
	}
}