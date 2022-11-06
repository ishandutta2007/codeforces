#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,x,y,z,h[300005],cnt,vis[300005],opt;long long sum;
struct edge{int to,next;}e[600005];
void add(int x,int y){
	e[++cnt]=(edge){y,h[x]};h[x]=cnt;
}
struct node{int id,v;};vector<node>v[300005];
int tot,root[300005],val[300005],id[300005],d[300005],ls[300005],rs[300005],tag[300005];
void Tag(int x,int v){val[x]+=v;tag[x]+=v;}
int newnode(int v,int p){
	++tot;val[tot]=v;id[tot]=p;d[tot]=1;return tot;
}
void pushdown(int x){
	if(tag[x]){
		if(ls[x])Tag(ls[x],tag[x]);
		if(rs[x])Tag(rs[x],tag[x]);
		tag[x]=0;
	}
}
int merge(int p,int q){
	if(!p||!q)return p+q;
	pushdown(p);pushdown(q);
	if(val[q]<val[p])swap(p,q);
	rs[p]=merge(rs[p],q);
	if(d[ls[p]]<d[rs[p]])swap(ls[p],rs[p]);
	d[p]=d[rs[p]]+1;return p;
}
int top(int x){
	while(vis[id[x]]){
		pushdown(x);
		x=merge(ls[x],rs[x]);
	}
	return x;
}
void dfs(int x,int prt){
	int i,y;
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;if(y==prt)continue;
		dfs(y,x);root[x]=merge(root[x],root[y]);
	}
	for(i=0;i<v[x].size();++i){
		if(v[x][i].v!=-1)root[x]=merge(root[x],newnode(v[x][i].v,v[x][i].id));
		else vis[v[x][i].id]=1;
	}
	if(x!=1){
		root[x]=top(root[x]);
		if(root[x]==0){opt=1;return;}
		sum+=val[root[x]];
		Tag(root[x],-val[root[x]]);
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	for(int i=1;i<=m;++i){
		x=read();y=read();z=read();
		v[x].push_back((node){i,z});
		v[y].push_back((node){i,-1});
	}
	dfs(1,0);
	if(opt)puts("-1");
	else cout<<sum<<"\n";
	return 0;
}