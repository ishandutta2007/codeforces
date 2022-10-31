#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
int a[N],dg[N],_q[N],_l,_r,dep[N],L,bel[N],CUR,ID[N],id;
std::vector<int> e[N];bool mark[N],vis[N];
void dfs1(int x){vis[x]=1,bel[x]=CUR,ID[x]=id;for(auto v:e[x])if(!vis[v])dep[v]=dep[x]+1,dfs1(v);else L=dep[x]+1;}
struct qry{ll m;int id;};
std::vector<qry> Q1[N],Q2[N];
int cnt[N],ans[N],mx;std::vector<int> vec[N];
void dfs2(int x){
	mx=std::max(mx,dep[x]),vec[dep[x]%L].pb(dep[x]);
	vis[x]=1;for(const auto &it:Q1[x])ans[it.id]-=cnt[it.m+dep[x]];
	++cnt[dep[x]];for(auto v:e[x])if(!vis[v])dfs2(v);
	for(const auto &it:Q1[x])ans[it.id]+=cnt[it.m+dep[x]];
}
int main(){
	int n;read(n);
	for(int i=1,x;i<=n;++i)read(x),e[x].pb(i),++dg[x],a[i]=x;
	_l=1,_r=0;for(int i=1;i<=n;++i)if(dg[i]==0)_q[++_r]=i;
	while(_l!=_r+1){
		int x=_q[_l++];
		if(--dg[a[x]]==0)_q[++_r]=a[x];
	}
	for(int i=1;i<=n;++i)if(dg[i])mark[i]=1;
	std::vector<int> rts,len;
	for(int i=1;i<=n;++i)if(mark[i]&&!vis[i])CUR=i,id=SZ(rts),dfs1(i),rts.pb(i),len.pb(L);
	int q;read(q);ll m;int y;
	for(int i=1;i<=q;++i){
		read(m,y);
		if(!mark[y]){if(m<=n)Q1[y].pb({m,i});}
		else{
			int z=bel[y];
			if(m+dep[y]-len[ID[y]]>=0)Q2[z].pb({m+dep[y]-len[ID[y]],i});
			if(m<=n)Q1[y].pb({m,i});
		}
	}
	memset(vis,0,sizeof(vis));int p=0,to;
	for(auto x:rts){
		L=len[p++],mx=0,dfs2(x);
		for(int i=0;i<=mx;++i)std::sort(vec[i].begin(),vec[i].end());
		for(const auto &it:Q2[x])to=it.m%L,ans[it.id]+=std::upper_bound(vec[to].begin(),vec[to].end(),it.m)-vec[to].begin();
		for(int i=0;i<=mx;++i)vec[i].clear();
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}