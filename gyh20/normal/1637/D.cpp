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
int t,n,m,a[102],b[102],ans,A,B,f[102][10002];
char s[1000002];
inline void gmn(re int &x,re int y){y<x&&(x=y);}
int main(){
	t=read();
	while(t--){
		n=read();memset(f,0x3f,sizeof(f)),f[1][0]=0;ans=0;
		for(re int i=1;i<=n;++i)a[i]=read(),ans+=a[i]*a[i]*(n-1);
		for(re int i=1;i<=n;++i)b[i]=read(),ans+=b[i]*b[i]*(n-1);
		re int s=0,s1=0;
		for(re int i=1;i<=n;++i){
			for(re int j=0;j<=s1;++j){
				gmn(f[i+1][j+a[i]],f[i][j]+a[i]*j+b[i]*(s-j));
				gmn(f[i+1][j+b[i]],f[i][j]+b[i]*j+a[i]*(s-j));
			}
			s+=a[i]+b[i],s1+=max(a[i],b[i]); 
		}
		re int mn=1e9;
		for(re int j=0;j<=s1;++j)gmn(mn,f[n+1][j]);
		printf("%d\n",ans+mn+mn);
	}
}