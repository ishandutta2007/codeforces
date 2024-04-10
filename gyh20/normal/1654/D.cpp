#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,head[200002],A,B,ans,pri[200002],cnt,mx[200002],cur[200002],Ans;
char v[200002];
vector<int>D[200002];
struct edge{
	int to,next,w,w1;
}e[400002];
inline void add(re int x,re int y,re int w,re int w1){
	e[++cnt]=(edge){y,head[x],w,w1},head[x]=cnt;
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
inline void dfs(re int x,re int y,re int a,re int b){
	if(x>1){
		for(re int i=0;i<D[a].size();++i)--cur[D[a][i]];
		for(re int i=0;i<D[b].size();++i)++cur[D[b][i]],mx[D[b][i]]=max(mx[D[b][i]],cur[D[b][i]]);
	}
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs(e[i].to,x,e[i].w,e[i].w1);
	if(x>1){
		for(re int i=0;i<D[a].size();++i)++cur[D[a][i]];
		for(re int i=0;i<D[b].size();++i)--cur[D[b][i]];
	}	
}
inline void dfs1(re int x,re int y,re int z){
	add(Ans,z);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y)
			dfs1(e[i].to,x,1ll*z*e[i].w%M*ksm(e[i].w1,M-2)%M);
}
signed main(){
	t=read();
	n=2e5;
	for(re int i=2;i<=n;++i){
		re int x=i;
		for(re int j=2;j*j<=x;++j)while(x%j==0)D[i].push_back(j),x/=j;
		if(x>1)D[i].push_back(x);
	}
	while(t--){
		n=read(),ans=1,Ans=0,cnt=0;
		for(re int i=1;i<=n;++i)mx[i]=cur[i]=head[i]=0;
		for(re int i=1;i<n;++i){
			re int x=read(),y=read(),a=read(),b=read();
			add(x,y,b,a),add(y,x,a,b);
		}
		dfs(1,1,0,0);
		for(re int i=1;i<=n;++i)ans=1ll*ans*ksm(i,mx[i])%M;
		dfs1(1,1,ans),printf("%d\n",Ans);
	}
}