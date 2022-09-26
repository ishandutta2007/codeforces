#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],c[N],t[N],now,pos[N],d[N],f[N],dep[N],son[N];
int siz[N],dfn[N],num;
int h[N];
vector<int> G[N];
ll ans;
void dfs1(int u){
	siz[u]=1;
	dfn[u]=++num;
	for(auto v:G[u]){
		f[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
		siz[u]+=siz[v];
	}
}
int qwq;
void dfs2(int u){
	sort(G[u].begin(),G[u].end(),[&](int i,int j){return c[i]<c[j];});
	++qwq;
	if(c[u]^qwq){
		puts("NO");
		exit(0);
	}
	for(auto v:G[u]){
		dfs2(v);
	}	
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		pos[a[i]]=i;
	}
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		G[u].push_back(v);
	}
	for(int i=1;i<=n;++i){
		d[i]=G[i].size();
	}
	dfs1(1);
	int Z=n;
	for(int i=1;i<=n;++i){
		int u=pos[i];
		static vector<int> tp;
		tp.clear();
		for(int v=u,las=0;v;las=v,v=f[v]){
			if(c[v])break;
			son[v]=las;
			tp.push_back(v);
		}
		reverse(tp.begin(),tp.end());
		for(auto v:tp){
			c[v]=++now;
		}
		ans+=dep[u];
		h[u]=1;
		if(d[u]){
			Z=i;
			break;
		}
		--d[f[u]];
	}
	for(int i=1;i<=n;++i){
		if(!c[i])c[i]=a[i];
	}
	dfs2(1);
	for(int i=1;i<=n;++i){
		t[c[i]]=i;
	}
	for(int i=Z+1;i<=n;++i){
		int u=pos[i];
		if(dfn[t[i]]<dfn[u]||dfn[t[i]]>dfn[u]+siz[u]-1){
			puts("NO");
			return 0;
		}	
		if(son[u]&&!h[son[u]]){
			if(a[u]+1!=a[son[u]]){
				puts("NO");
				return 0;
			}	
		}
	}
	printf("YES\n");
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		printf("%d ",c[i]);
	}
	return 0;
}