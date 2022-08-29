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
int t,n,m,a[1000002],ans,A,B,G[12],f[50002][1024],F[12];
char s[1000002];
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();
		F[x]|=(1<<y),F[y]|=(1<<x);
		if(x<y)G[y]|=(1<<x);
		else G[x]|=(1<<y);
	}
	f[0][0]=1;
	for(re int i=0;i<n;++i)
		for(re int j=0;j<1024;++j)
			if(f[i][j])
				for(re int k=0;k<10;++k){
					if(G[k]&j)continue;
					add(f[i+1][(j&F[k])|(1<<k)],f[i][j]);
				}
	re int ans=0;
	for(re int i=0;i<1024;++i)add(ans,f[n][i]);
	printf("%d",ans);
	
}