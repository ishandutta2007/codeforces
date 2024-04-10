//2018.10.25 by ljz
#include<bits/stdc++.h>
using namespace std;
#define res register int
#define LL long long
#define inf 0x3f3f3f3f
#define eps 1e-15
inline int read(){
    res s=0;
    bool w=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return w?-s:s;
}
inline void _swap(res &x,res &y){
    x^=y^=x^=y;
}
inline int _abs(const res &x){
    return x>0?x:-x;
}
inline int _max(const res &x,const res &y){
    return x>y?x:y;
}
inline int _min(const res &x,const res &y){
    return x<y?x:y;
}
const int N=1e5+10;
namespace MAIN{
	int n;
	int rt[N],rtx;
	struct E{
		int next,to;
		E() {}
		E(res next,res to):next(next),to(to) {}
	}edge[N];
	int head[N],cnt;
	inline void addedge(const res &u,const res &v){
		edge[++cnt]=E(head[u],v),head[u]=cnt;
	}
	int dep[N],F[N][21],siz[N],fa[N],son[N];
	void Dfs(const res &x,const res &fax,const res &depx){
		dep[x]=depx,fa[x]=fax,F[x][0]=fax,siz[x]=1;
		for(res i=1;i<=20;i++)F[x][i]=F[F[x][i-1]][i-1];
		for(res i=head[x];~i;i=edge[i].next){
			res tox=edge[i].to;
			if(tox==fax)continue;
			Dfs(tox,x,depx+1);
			siz[x]+=siz[tox];
			if(siz[son[x]]<siz[tox])son[x]=tox;
		}
	}
	typedef pair<int,int> Pair;
#define mp make_pair	
#define fi first
#define se second
	vector<Pair> vec[N];
#define pb push_back	
	int m;
	int tot[N],ans[N];
	bool vis[N];
	void update(const res &x,const res &va){
		tot[dep[x]]+=va;
		for(res i=head[x];~i;i=edge[i].next){
			res tox=edge[i].to;
			if(tox==fa[x]||vis[tox])continue;
			update(tox,va);
		}
	}
	void dfs(const res &x,const res &flag){
		for(res i=head[x];~i;i=edge[i].next){
			res tox=edge[i].to;
			if(tox==fa[x]||tox==son[x])continue;
			dfs(tox,0);
		}
		if(son[x])dfs(son[x],1),vis[son[x]]=1;
		update(x,1);for(res i=0,siz=vec[x].size();i<siz;i++)ans[vec[x][i].fi]=tot[vec[x][i].se]-1;vis[son[x]]=0;
		if(!flag)update(x,-1);
	}
	inline void MAIN(){
		memset(head,-1,sizeof(head));
		n=read();
		for(res i=1;i<=n;i++){
			res fa=read();
			if(!fa)rt[++rtx]=i;
			else addedge(fa,i);
		}
		for(res i=1;i<=rtx;i++)Dfs(rt[i],0,1);
		m=read();
		for(res t=1;t<=m;t++){
			res x=read(),k=read(),d=dep[x];
			for(res i=20;~i;i--)if(k&(1<<i))x=F[x][i];
			vec[x].pb(mp(t,d));
		}
		for(res i=1;i<=rtx;i++)dfs(rt[i],0);
		for(res i=1;i<=m;i++)printf("%d ",ans[i]);
	}
}
int main(){
    MAIN::MAIN();
    return 0;
}