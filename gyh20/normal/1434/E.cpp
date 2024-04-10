#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,f[452],sum,a[100002],vis[452],ans[452],T[452][100002],fa[452][100002],P[100002],b[100002],N[100002];
inline int root(re int y,re int x){return x==fa[y][x]?x:fa[y][x]=root(y,fa[y][x]);}
inline void solve(){
	n=read(),memset(ans,0,sizeof(ans));
	for(re int i=1;i<=n;++i)a[i]=read(),P[i]=a[i];P[n+1]=1e9;
	sort(P+1,P+n+1),memset(N,0,sizeof(N)),N[100001]=n+1;
	for(re int i=n;i;--i)N[P[i]]=i;
	for(re int i=100000;~i;--i)if(!N[i])N[i]=N[i+1];
	for(re int i=1;i<=n;++i)b[i]=lower_bound(P+1,P+n+1,a[i])-P;
	int K=450;
	for(re int i=0;i<=K;++i){
		for(re int j=0;j<=n+1;++j)fa[i][j]=j,T[i][j]=-1;
	}
	for(re int i=0;i<=n+1;++i)T[0][i]=a[n];
	for(re int i=n-1;i;--i){
		for(re int k=0;k<=K;++k)vis[k]=max(-1,T[k][b[i]]-a[i]);
		f[0]=1e5;
		re int pp=0;
		for(re int j=1;j<=K;++j){
			f[j]=min(f[j-1],vis[j-1]);
			if(~f[j])pp=j;
		}
		for(re int j=1;j<K;++j){
			re int l=a[i]-f[j],r=a[i]-f[j+1];l=max(l,-1),r=min(r,100000);if(l>=r)continue;
			l=N[l+1],r=N[r+1]-1;
			for(re int k=root(j,l);k<=r;k=root(j,k))T[j][k]=a[i],fa[j][k]=k+1;
		}
		ans[pp]=1;
	}ans[0]=1;
	re int pos=0;
	while(ans[pos])++pos;
	sum^=pos;
}
int main(){
	t=read();
	while(t--)solve();
	puts(sum?"YES":"NO");
}