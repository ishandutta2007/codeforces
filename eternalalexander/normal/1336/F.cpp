#include <bits/stdc++.h>
#define maxn 200005
int n,m,k,u[maxn],v[maxn],ch[maxn<<6][2]={0},sum[maxn<<6]={0},pt[maxn],head[maxn]={0},tail=0,cnt=0,root[maxn]={0},
anc[maxn][19]={0},son[maxn]={0},depth[maxn]={0},dfn[maxn],size[maxn],idx=0;
long long ans=0;
std::vector<int>in[maxn],vec[maxn];
struct edge {
	int v,next;
}edges[maxn<<1];
void add_edge(int u,int v){
	edges[++tail].v=v;
	edges[tail].next=head[u];
	head[u]=tail;
}
namespace BIT {
	int sum[maxn<<2]={0};
	void add(int p,int x) {if (p==0) return;while (p<=n) {sum[p]+=x;p+=p&-p;}}
	int query(int p) {int ans=0;while (p>0) {ans+=sum[p];p-=p&-p;}return ans;}
	void Add(int l,int r){add(l,1);add(r+1,-1);}
}
void update(int x){sum[x]=sum[ch[x][0]]+sum[ch[x][1]];}
int insert(int rt,int l,int r,int p){
	if (!rt) rt=++cnt;
	if (l==r) {sum[rt]++;return rt;}
	int mid=(l+r)>>1;
	if (p<=mid) ch[rt][0]=insert(ch[rt][0],l,mid,p);
	else ch[rt][1]=insert(ch[rt][1],mid+1,r,p);
	update(rt);
	return rt;
} int merge(int u,int v){
	if (!u||!v)return u+v;
	ch[u][0]=merge(ch[u][0],ch[v][0]);
	ch[u][1]=merge(ch[u][1],ch[v][1]);
	sum[u]=sum[u]+sum[v];return u;
} int query(int rt,int L,int R,int l,int r){
	if (l>R||r<L)return 0;
	if (l<=L&&R<=r){return sum[rt];}
	return query(ch[rt][0],L,(L+R)>>1,l,r)+query(ch[rt][1],((L+R)>>1)+1,R,l,r);
}

void dfs1(int u,int f){
	anc[u][0]=f;depth[u]=depth[f]+1;size[u]=1;
	for (int i=1;i<=18;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==f) continue;
		dfs1(v,u);size[u]+=size[v];
		if (size[v]>size[son[u]])son[u]=v;
	}
} void dfsn(int u){
	dfn[u]=++idx;
	for (int i=head[u];i;i=edges[i].next){
		int v=edges[i].v;
		if (v==son[u]||v==anc[u][0])continue;
		dfsn(v);
	}if (son[u]) dfsn(son[u]);
}

int lift(int u,int x){
	for (int i=18;i>=0;i--)if (x>=(1<<i)) {u=anc[u][i];x-=(1<<i);}
	return u;
}

int lca(int u,int v){
	if (depth[u]<depth[v])std::swap(u,v);
	for (int i=18;i>=0;i--)if (depth[anc[u][i]]>=depth[v])u=anc[u][i];
	if (u==v)return u;
	for (int i=18;i>=0;i--)if (anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
	return anc[u][0];
} 

void dfs3(int x,int rt){
	pt[x]=x;root[x]=0;
	for (int i=0;i<in[x].size();++i) {
		int d=in[x][i];
		int rd=std::max(0,k-(depth[u[d]]-depth[rt]));
		if (depth[v[d]]-depth[rt]>=rd){
			int l=lift(v[d],depth[v[d]]-depth[rt]-rd);
			ans+=query(root[x],1,n,dfn[l],dfn[l]+size[l]-1);
		}root[x]=insert(root[x],1,n,dfn[v[d]]);
	}for (int i=head[x];i;i=edges[i].next){
		int t=edges[i].v;
		if (t==anc[x][0]||(rt==x&&t==son[x])) continue;
		dfs3(t,rt);
		if (in[pt[x]].size()<in[pt[t]].size()){
			std::swap(pt[x],pt[t]);
			std::swap(root[x],root[t]);
		}while (!in[pt[t]].empty()){
			int d=in[pt[t]][in[pt[t]].size()-1];in[pt[t]].pop_back();
			int rd=std::max(0,k-(depth[x]-depth[rt]));
			if (depth[v[d]]-depth[rt]>=rd) {
				int l=lift(v[d],(depth[v[d]]-depth[rt]-rd));
				ans+=query(root[x],1,n,dfn[l],dfn[l]+size[l]-1);
			}in[pt[x]].push_back(d);
		}root[x]=merge(root[x],root[t]);
	}
}

void dfs2(int x){
	int len=vec[x].size();
	for (int i=head[x];i;i=edges[i].next)if (edges[i].v!=anc[x][0])dfs2(edges[i].v);
	for (int i=0;i<len;++i)ans+=BIT::query(dfn[v[vec[x][i]]]);
	for (int i=0;i<len;++i){
		int j=vec[x][i];
		if (depth[v[j]]-depth[x]>=k) {
			int l=lift(v[j],depth[v[j]]-depth[x]-k);
			BIT::Add(dfn[l],dfn[l]+size[l]-1);
		}
	}for (int i=0;i<len;++i){ans+=BIT::query(dfn[u[vec[x][i]]]);in[u[vec[x][i]]].push_back(vec[x][i]);}
	dfs3(x,x);
	while (!in[pt[x]].empty())in[pt[x]].pop_back();
	for (int i=0;i<len;++i){
		int j=vec[x][i];
		if (depth[u[j]]-depth[x]>=k) {
			int l=lift(u[j],depth[u[j]]-depth[x]-k);
			BIT::Add(dfn[l],dfn[l]+size[l]-1);
		}
	}
}
	
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}dfs1(1,0);dfsn(1);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&u[i],&v[i]);
		if (dfn[u[i]]>dfn[v[i]]) std::swap(u[i],v[i]);
		int l=lca(u[i],v[i]);
		vec[l].push_back(i);
	} dfs2(1);
	std::cout<<ans;
	return 0;
}