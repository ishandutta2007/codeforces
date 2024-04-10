#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline int Abs(re int x){return x<0?-x:x;}
struct edge{int to,next;}e[2000002];
int t,n,m,a[1000002],ans,cnt,head[1000002],b[1000002],sum,c[1000002],f[1000002][2];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
}
inline void dfs(re int x,re int y){
	f[x][0]=f[x][1]=0;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			f[x][0]+=max(f[e[i].to][0]+Abs(a[x]-a[e[i].to]),f[e[i].to][1]+Abs(a[x]-b[e[i].to]));
			f[x][1]+=max(f[e[i].to][0]+Abs(b[x]-a[e[i].to]),f[e[i].to][1]+Abs(b[x]-b[e[i].to]));
		}
}
signed main(){
	t=read();
	while(t--){
		n=read(),ans=0,cnt=0;
		for(re int i=1;i<=n;++i)head[i]=0;
		for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read();
		for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}