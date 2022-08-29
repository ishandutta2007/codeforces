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
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
struct edge{int to,next;}e[2000002];
int t,n,m,f[1000002],ans,cnt;
signed main(){
	n=read(),f[1]=f[0]=ans=1;
	for(re int i=2;i<=n;++i){
		add(f[i],ans);
		add(f[i],1);
		for(re int j=i;j<=n;j+=i)add(f[j],1);
		add(ans,f[i]);	}
	printf("%d",f[n]);
}