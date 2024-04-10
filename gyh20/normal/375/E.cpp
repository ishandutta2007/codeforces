#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,head[502],cnt,L[502],R[502],a[502],X,s,siz[502],tim,pl[502];
ll G[502][502];
struct edge{int to,next;}e[1002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
unsigned char f[502][502][502],u[502][502],Mn[502][502],tmp[502][502];
inline void gmn(re unsigned char &x,re unsigned char y){y<x&&(x=y);}
inline void dfs(re int x,re int y){
	L[x]=++tim,siz[x]=1,pl[tim]=x;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x);
	R[x]=tim;
}
inline void dfs1(re int x,re int y){
	for(re int i=1;i<=n;++i)if(x^i&&u[x][i])f[x][i][0]=0;
	f[x][x][1]=1-a[x];
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs1(e[i].to,x);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			for(re int j=0;j<=siz[x]+siz[e[i].to];++j)
				for(re int l=1;l<=n;++l)
					tmp[l][j]=255;
			for(re int l=1;l<=n;++l)
				for(re int j=0;j<=siz[x];++j)
					if(f[x][l][j]<=250)
						for(re int k=0;k<=siz[e[i].to];++k){
							if(f[e[i].to][l][k]<=250)gmn(tmp[l][j+k],f[x][l][j]+f[e[i].to][l][k]);
							if(Mn[e[i].to][k]<=250&&(!(L[l]>=L[e[i].to]&&L[l]<=R[e[i].to])))gmn(tmp[l][j+k],f[x][l][j]+Mn[e[i].to][k]);
						}
			siz[x]+=siz[e[i].to];
			for(re int j=0;j<=siz[x];++j)
				for(re int k=1;k<=n;++k)
					f[x][k][j]=tmp[k][j];
		}
	for(re int j=0;j<=siz[x];++j){
		Mn[x][j]=255;
		for(re int k=1;k<=n;++k)if(L[k]>=L[x]&&L[k]<=R[x])Mn[x][j]=min(Mn[x][j],f[x][k][j]);
	}
}
int main(){
	n=read(),X=read(),memset(G,0x3f,sizeof(G));
	for(re int i=1;i<=n;++i)a[i]=read(),s+=a[i];
	for(re int i=1;i<=n;++i)G[i][i]=0;
	for(re int i=1,x,y,z;i<n;++i)x=read(),y=read(),z=read(),add(x,y),add(y,x),G[x][y]=G[y][x]=z;
	for(re int k=1;k<=n;++k)for(re int i=1;i<=n;++i)for(re int j=0;j<=n;++j)f[i][k][j]=255,G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)u[i][j]=G[i][j]<=X;
	dfs(1,1);re unsigned char ans=255;dfs1(1,1);
	for(re int i=0;i<=s;++i)for(re int j=1;j<=n;++j)gmn(ans,f[1][j][i]);
	if(ans>250)puts("-1");
	else printf("%d",ans);
}