#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,d[100002],f[100002],A[100002],B[100002],fa[100002],siz[100002],P1,P2,dis[100002],ia;
vector<int>G[100002],H[100002],E[100002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Merge(re int x,re int y){fa[root(x)]=root(y);}
inline void Add(re int x,re int y){G[x].push_back(y),++d[y];}
inline void chk(){if(ia)return;
	re long long s=0;
	for(re int i=1;i<=m;++i)s+=1ll*f[A[i]]*f[B[i]];
	for(re int i=1;i<=n;++i)s-=1ll*f[i]*f[i];
	assert(s>=0);if(s<0)while(1);
	puts("YES");
	for(re int i=1;i<=n;++i)printf("%d ",f[i]);
	ia=1;
}
inline void dfs(re int x,re int y){
	f[x]=2;
	if(x==P1){
		for(auto z:G[P1])if(!f[z])f[z]=1;
		for(auto z:G[P2])if(!f[z])f[z]=1;
		chk();
	}
	for(auto z:G[x])if(z^y)dfs(z,x);
	f[x]=0;
}
inline void dfs1(re int x,re int y){
	dis[x]=1;
	for(auto z:G[x])if(z^y)dfs1(z,x),dis[x]=max(dis[x],dis[z]+1);
}
inline bool cmp(re int x,re int y){return dis[x]<dis[y];}
inline void solve(vector<int>&X,vector<int>&Y){if(ia)return;
	re int p1=0,p2=0;
	for(re int i=0;i<X.size();++i)if(d[X[i]]==3)p2=p1,p1=X[i];
	if(p2)P1=p1,P2=p2,dfs(p2,p2);
	if(!p1)return;int tim=0;
	f[p1]=1;
	while(1){
		++tim;
		re bool ia=0;
		for(auto z:X){
			re int s=0;
			for(auto o:G[z])s+=f[o];
			if(s>=f[z]+f[z]+1)++f[z],ia=1;
		}
		if(tim>100)break;
		if(!ia)break;
	}
	re long long s=0;
	for(auto i:Y)s+=1ll*f[A[i]]*f[B[i]];
	for(auto i:X)s-=1ll*f[i]*f[i];
	if(s>=0)chk();
	for(auto i:X)f[i]=0;
}
int main(){
	int t=read();
	while(t--){
		n=read(),m=read(),ia=0;
		for(re int i=0;i<=max(n,m);++i){
			d[i]=f[i]=A[i]=B[i]=fa[i]=siz[i]=P1=P2=dis[i]=0;
			G[i].clear(),H[i].clear(),E[i].clear();
		}
		for(re int i=1;i<=m;++i)A[i]=read(),B[i]=read(),Add(A[i],B[i]),Add(B[i],A[i]);
		for(re int i=1;i<=n;++i)
			if(d[i]>=4){
				f[i]=2;
				for(auto z:G[i])f[z]=1;
				chk();
			}
		for(re int i=1;i<=n;++i)fa[i]=i;
		for(re int i=1;i<=m;++i)Merge(A[i],B[i]);
		for(re int i=1;i<=m;++i)++siz[root(A[i])],E[root(A[i])].push_back(i);
		for(re int i=1;i<=n;++i)H[root(i)].push_back(i);
		for(re int i=1;i<=n;++i)
			if(H[i].size()&&siz[i]>=H[i].size()){
				for(auto z:H[i])f[z]=1;
				chk();
			}
		for(re int i=1;i<=n;++i)if(H[i].size())solve(H[i],E[i]);
		if(!ia)puts("NO");
	}
}