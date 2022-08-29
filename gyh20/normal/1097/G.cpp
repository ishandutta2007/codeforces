#include<cstdio>
#define re register
#define gc getchar
inline int min(re int x,re int y){return x<y?x:y;}
using namespace std;
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int s[302][302],n,k,fac,f[100002][202],head[100002],cnt,ans[202],siz[100002],g[302],sum;
struct edge{int to,next;}e[200002];
const int M=1e9+7;
inline void addd(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline void dfs(re int x,re int y){
	siz[x]=1,f[x][0]=2;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x);
			for(re int j=0;j<=k;++j)g[j]=0;
			for(re int ii=0;ii<=min(k,siz[x]);++ii)for(int j=0;j<=min(k-ii,siz[e[i].to]);++j)add(g[ii+j],1ll*f[x][ii]*f[e[i].to][j]%M);
			for(re int j=0;j<=k;++j)f[x][j]=g[j],add(ans[j],M-f[e[i].to][j]);
			siz[x]+=siz[e[i].to];
		}
	for(re int i=k;i;--i)add(ans[i],f[x][i]),add(f[x][i],f[x][i-1]);
	add(ans[0],f[x][0]),add(f[x][1],M-1);
}
int main(){
	n=read(),k=read(),s[1][1]=1;
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),addd(x,y),addd(y,x);
	for(re int i=2;i<=k;++i)for(re int j=1;j<=i;++j)s[i][j]=(1ll*s[i-1][j]*j+s[i-1][j-1])%M;
	dfs(1,1);
	for(re int i=fac=1;i<=k;++i){
		fac=1ll*fac*i%M;
		add(sum,1ll*s[k][i]*fac%M*ans[i]%M);
	}
	printf("%d",sum);
}