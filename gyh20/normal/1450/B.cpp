#include<bits/stdc++.h>
#define re register
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[102][102],t,ans,a[102],b[102];
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int ksm(re int x,re int y){
	re int ans=1;
	while(y){
		if(y&1)ans=1ll*ans*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return ans;
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read();
		int ans=0,ans1=1;
		for(re int i=1;i<=n;++i){
			int ia=1;
			for(re int j=1;j<=n;++j){
				 if(abs(a[i]-a[j])+abs(b[i]-b[j])>m)ia=0;
				 if(a[i]!=a[j]||b[i]!=b[j])ans1=0;
			}
			ans|=ia;
		}
		if(ans1)puts("0");
		else if(ans)puts("1");
		else puts("-1");
	}
}