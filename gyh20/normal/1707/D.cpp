#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int M;
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
int t,n,m,a[1000002],ans,A,B,head[1000002],cnt,f[2002][2002],C[2002][2002],cur[2002],tmp[2002][2002],Tmp[2002],pre[2002][2002],suf[2002][2002],g[2002];
vector<int>G[2002];
inline void dfs(re int x,re int y){
	vector<int>son;
	for(auto z:G[x])if(z^y)dfs(z,x),son.push_back(z);
	memset(g,0,sizeof(g));
	for(re int i=1;i<=n;++i){
		f[x][i]=1;
		int num=0;
		for(re int ii=0;ii<son.size();++ii){
			re int s=0,z=son[ii];
			if(x^1)add(g[z],f[z][i]);
			s=g[z];
			if(x==1)add(g[z],f[z][i]);
			f[x][i]=1ll*f[x][i]*s%M,tmp[i][ii]=s;
		}
		Tmp[i]=f[x][i];
	}
	if(son.size()&&x!=1){
		for(re int i=1;i<=n;++i){
			for(re int j=0;j<son.size();++j){
				pre[i][j]=tmp[i][j];
				if(j)pre[i][j]=1ll*pre[i][j-1]*pre[i][j]%M;
			}
			for(re int j=son.size()-1;~j;--j){
				suf[i][j]=tmp[i][j];
				if(j!=son.size()-1)suf[i][j]=1ll*suf[i][j+1]*suf[i][j]%M;
			}
		}
		for(re int ii=0;ii<son.size();++ii){
			for(re int i=1;i<=n;++i){
				re int s=1;
				if(ii)s=1ll*s*pre[i][ii-1]%M;
				if(ii+1!=son.size())s=1ll*s*suf[i][ii+1]%M;
				cur[i]=s;
			}
			for(re int i=1;i<=n;++i)add(cur[i],cur[i-1]);
			for(re int i=1;i<=n;++i)add(f[x][i],1ll*f[son[ii]][i]*cur[i-1]%M);
		}
	}
}
int main(){
	n=read(),M=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
	C[0][0]=1;
	for(re int i=1;i<=n;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	dfs(1,1);
	for(re int i=1;i<=n;++i){
		for(re int j=1;j<i;++j)
			add(f[1][i],1ll*(M-f[1][j])*C[i-1][j-1]%M);
		if(i>1)printf("%d ",f[1][i]);
	}
}