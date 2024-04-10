#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 500050 
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,Q,a[N],f[N][20],ans[N],dfn[N],siz[N],tot,num,p[N];
vector<int> qs[N];
vector<int> G[N];
struct Query{
	int opt,x;
}q[N];
struct Link{
	int x,y,w;
}l[N];
struct Union_Set{
	int f[N];
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i;
		}
	}
	inline int getf(int x){
		return f[x]==x?x:f[x]=getf(f[x]);
	}
}S;
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	void Add(int x,int d){
		while(x<=tot){
			b[x]+=d;
			x+=lowbit(x);
		}
	}
	int Ask(int x){
		int ans=0;
		while(x){
			ans+=b[x];
			x-=lowbit(x);
		}
		return ans;
	}
}D;
void dfs1(int u,int dep){
	dfn[u]=++num;
	siz[u]=1;
	D.Add(dfn[u],dep);
	D.Add(dfn[u]+1,-dep);
	for(int j=1;j<=18;++j){
		f[u][j]=f[f[u][j-1]][j-1];
	}
	for(auto v:G[u]){
		f[v][0]=u;
		dfs1(v,dep+1);
		siz[u]+=siz[v];
	}
}
void Del(int u){
	D.Add(dfn[u],-1);
	D.Add(dfn[u]+siz[u],1);
}
int Get(int u,int x){
	for(int i=18;i>=0;--i){
		if((x>>i)&1)u=f[u][i];
	}
	return u;
}
void dfs2(int u){
	if(!qs[u].empty())return;
	Del(u);
	for(auto v:G[u]){
		dfs2(v);
	}
}
int main(){
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;++i){
		p[i]=read(),a[i]=i;
	}
	for(int i=1;i<=m;++i){
		l[i].x=read(),l[i].y=read();
	}
	for(int i=1;i<=Q;++i){
		q[i].opt=read(),q[i].x=read();
		if(q[i].opt==2)ans[i]=-1,l[q[i].x].w=i;
	}
	tot=n;
	S.init(n<<1);
	for(int i=1;i<=m;++i){
		if(!l[i].w){
			int fx=S.getf(l[i].x),fy=S.getf(l[i].y);
			if(fx==fy)continue;
			++tot;
			G[tot].push_back(fx),G[tot].push_back(fy);
			S.f[fx]=S.f[fy]=tot; 
		}
	}
	for(int i=Q;i>=1;--i){
		if(q[i].opt==1){
			qs[S.getf(q[i].x)].push_back(i);
		}
		else{
			int fx=S.getf(l[q[i].x].x),fy=S.getf(l[q[i].x].y);
			if(fx==fy)continue;
			++tot;
			G[tot].push_back(fx),G[tot].push_back(fy);
			S.f[fx]=S.f[fy]=tot; 
		}
	}
	for(int i=tot;i>=1;--i){
		if(!dfn[i]){
			dfs1(i,0);
			dfs2(i);
		}
	}
	sort(a+1,a+n+1,[&](int i,int j){return p[i]>p[j];});
	for(int i=1;i<=n;++i){
		int u=a[i];
		int dep=D.Ask(dfn[u]);
		if(dep==-1)continue;
		int fa=Get(u,D.Ask(dfn[u]));
		ans[qs[fa].back()]=p[u];
		qs[fa].pop_back();
		dfs2(fa);
	}
	for(int i=1;i<=Q;++i){
		if(~ans[i])printf("%d\n",ans[i]);
	}
	return 0;
}