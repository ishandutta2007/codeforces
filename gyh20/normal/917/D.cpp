#include<cstdio>
#include<cstring>
#include<vector>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int n,m,head[8002],cnt,iv,siz[8002],nw[2][8002],fac[8002],inv[8002],g[8002];
vector<int>f[8002][2];
struct edge{int to,next;}e[16002];
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline void dfs(re int x,re int y){
	re int sz=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x),sz+=siz[e[i].to];
	f[x][0].resize(sz+1),f[x][1].resize(sz+1),siz[x]=1,f[x][0][0]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			memset(nw,0,sizeof(nw));
			for(re int a=0;a<=siz[x];++a)
				for(re int b=0;b<=siz[e[i].to];++b)
					for(re int c=0;c<=1;++c)
						for(re int d=0;d<=1;++d){
							if(c!=1||d!=1)add(nw[c|d][a+b],1ll*f[x][c][a]*f[e[i].to][d][b]%M);
						}
			siz[x]+=siz[e[i].to];
			for(re int a=0;a<=siz[x];++a)
				for(re int b=0;b<=1;++b)
					f[x][b][a]=nw[b][a];
			vector<int>().swap(f[e[i].to][0]),vector<int>().swap(f[e[i].to][1]);
		}
	if(x^1){
		memset(nw,0,sizeof(nw));
		for(re int a=0;a<=siz[x];++a)
			for(re int b=0;b<=1;++b){
				add(nw[0][a],1ll*f[x][b][a]*n%M),
				add(nw[b][a+1],f[x][b][a]);
				if(b==0)add(nw[1][a+1],f[x][b][a]);
			}
		for(re int a=0;a<=siz[x];++a)
			for(re int b=0;b<=1;++b)
				f[x][b][a]=nw[b][a];
	}
}
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
int main(){
	n=read(),iv=ksm(n,M-2);
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	dfs(1,1);
	for(re int a=0;a<=n;++a)
		for(re int b=0;b<=1;++b)
			add(g[a],f[1][b][a]);
	g[n-1]=1;
	for(re int a=0;a<n-1;++a)g[a]=1ll*g[a]*iv%M;
	for(re int i=0;i<n;++i)
		for(re int j=i+1;j<=n;++j)
			if((j-i)&1)add(g[i],M-1ll*C(j,i)*g[j]%M);
			else add(g[i],1ll*C(j,i)*g[j]%M);
	for(re int i=0;i<n;++i)printf("%d ",g[i]);
}