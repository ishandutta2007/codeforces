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
int t,n,m,k,f[502][502],a[502],d[502];
int main(){
	n=read(),m=read(),k=read();
	memset(f,0x3f,sizeof(f)),f[1][1]=0;
	for(re int i=1;i<=n;++i)d[i]=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=2;i<=n;++i)
		for(re int j=2;j<=i;++j)
			for(re int k=1;k<i;++k)
				f[i][j]=min(f[i][j],f[k][j-1]+a[k]*(d[i]-d[k]));
	re int ans=1e9;
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=i;++j)
			if(i-j+n-i<=k)
				ans=min(ans,f[i][j]+a[i]*(m-d[i]));
	printf("%d",ans);
}