#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,a[500002],mx,pos,f[500002],g[500002],h[500002][2],ans,inf=2e9;
inline void solve(){
	for(re int i=1;i<=n;++i)mx=max(mx,a[i]);
	for(re int i=1;i<=n;++i)if(mx==a[i])pos=i;
	for(re int i=1;i<=n;++i){
		f[i]=inf;
		if(a[i]>a[i-1])f[i]=min(f[i],f[i-1]);
		if(a[i]>f[i-1])f[i]=min(f[i],a[i-1]);
	}
	g[n+1]=0;
	for(re int i=n;i;--i){
		g[i]=inf;
		if(a[i]>a[i+1])g[i]=min(g[i],g[i+1]);
		if(a[i]>g[i+1])g[i]=min(g[i],a[i+1]);
	}
	h[pos][0]=f[pos],h[pos][1]=-1;
	for(re int i=pos+1;i<=n;++i){
		h[i][0]=inf,h[i][1]=-1;
		if(a[i]<a[i-1])h[i][0]=min(h[i][0],h[i-1][0]);
		if(a[i]<h[i-1][1])h[i][0]=min(h[i][0],a[i-1]);
		if(a[i]>a[i-1])h[i][1]=max(h[i][1],h[i-1][1]);
		if(a[i]>h[i-1][0])h[i][1]=max(h[i][1],a[i-1]);
		if(h[i][1]>g[i])++ans;
	}
}
int main(){
	n=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	solve(),reverse(a+1,a+n+1),solve();
	printf("%d",ans);
}