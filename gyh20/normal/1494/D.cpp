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
struct node{int x,y;};
int t,n,m,a[502][502],val[50002],fa[50002],rt[50002],tot,f[50002];
vector<node>v[5002];
inline int root(re int x){return x==f[x]?x:f[x]=root(f[x]);}
inline void dfs(re int x,re int y){
//	printf("%d %d\n",x,y);
	for(re int j=1;j<=n;++j){
		rt[j]=root(rt[j]);
		if(a[x][j]==y&&val[rt[j]]!=y)fa[rt[j]]=f[rt[j]]=tot,rt[j]=root(rt[j]),dfs(j,y);
	}
}
signed main(){
	n=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)a[i][j]=read(),(i!=j&&(v[a[i][j]].push_back((node){i,j}),0));tot=n;
	for(re int i=1;i<=n;++i)val[i]=a[i][i],rt[i]=i;
	for(re int i=1;i<=10000;++i)f[i]=i;
	for(re int i=1;i<=5000;++i){
		for(re int j=0;j<v[i].size();++j){
			rt[v[i][j].x]=root(rt[v[i][j].x]);
			rt[v[i][j].y]=root(rt[v[i][j].y]);
		//	printf("%d %d %d %d\n",v[i][j].x,v[i][j].y,rt[v[i][j].x],rt[v[i][j].y]);
			if(val[rt[v[i][j].x]]==i)continue;
		//	printf("aaa%d %d\n",v[i][j].x,v[i][j].y);
			++tot;
			val[tot]=i;
			fa[rt[v[i][j].x]]=fa[rt[v[i][j].y]]=f[rt[v[i][j].x]]=f[rt[v[i][j].y]]=tot;
			rt[v[i][j].x]=root(rt[v[i][j].x]);
			rt[v[i][j].y]=root(rt[v[i][j].y]);
			dfs(v[i][j].x,i),dfs(v[i][j].y,i);
		}
	}
	assert(tot<=5000);
	printf("%d\n",tot);
	for(re int i=1;i<=tot;++i)printf("%d ",val[i]);
	puts("");
	printf("%d\n",tot);
	for(re int i=1;i<tot;++i)printf("%d %d\n",i,fa[i]);
}