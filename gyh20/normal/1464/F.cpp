#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,head[200002],dep[200002],siz[200002],fa[200002],dfn[200002],pl[200002],son[200002],top[200002],cnt,tim,la,c[200002],A[800002],B[800002],num,S[800002],ans1,ans2;
inline void Add(re int x,re int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
inline int ask(re int x,re int s=0){for(;x;x^=x&(-x))s+=c[x];return s;}
struct edge{
	int to,next;
}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	dep[x]=dep[y]+1,fa[x]=y,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs1(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs1(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^son[x]&&e[i].to^fa[x])
			dfs1(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	}return dep[x]<dep[y]?x:y;
}
inline int kth(re int x,re int k){
	while(x){
		if(dep[x]-dep[top[x]]>=k)return pl[dfn[x]-k];
		k-=dep[x]-dep[top[x]]+1,x=fa[top[x]];
	}return 1;
}
inline int dis(re int x,re int y){if(x==0&&y==0)return -1;if(x==0||y==0)return 0;return dep[x]+dep[y]-(dep[lca(x,y)]<<1)+1;}
inline void upd(re int&x,re int&y,re int z){
	if(dis(x,z)>dis(x,y))swap(y,z);
	if(dis(y,z)>dis(x,y))swap(x,z);
}
inline void cg(re int p,re int l,re int r,re int x,re int y){
	if(l==r){A[p]=B[p]=y;return;}
	re int mid=l+r>>1;
	if(x<=mid)cg(p<<1,l,mid,x,y);
	else cg(p<<1|1,mid+1,r,x,y);
	A[p]=A[p<<1],B[p]=B[p<<1],upd(A[p],B[p],A[p<<1|1]),upd(A[p],B[p],B[p<<1|1]); 
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){upd(ans1,ans2,A[p]),upd(ans1,ans2,B[p]);return;}
	re int mid=l+r>>1;
	if(x<=mid)ask(p<<1,l,mid,x,y);
	if(y>mid)ask(p<<1|1,mid+1,r,x,y);
}
struct node{
	int x,y;
	bool operator <(const node A)const{return y==A.y?x<A.x:y<A.y;}
	bool operator ==(const node A)const{return x==A.x&&y==A.y;}
};
struct heap{
	priority_queue<node>q,d;
	inline void insert(re node x){q.push(x);}
	inline void del(re node x){d.push(x);}
	inline node first(){
		while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
		return q.top();
	}
}H;
int main(){
	n=read(),m=read();
	for(re int i=1,x,y;i<n;++i)x=read(),y=read(),add(x,y),add(y,x);dfs(1,0),dfs1(1,1);
	while(m--){
		re int o=read(),x=read(),y,z;
		if(o<=2)y=read();
		if(o<=2){
			z=lca(x,y);
			if(o==1)H.insert((node){z,dep[z]});else H.del((node){z,dep[z]});
			Add(dfn[x],o==1?1:-1),Add(dfn[y],o==1?1:-1),Add(dfn[z],o==1?-1:1),num+=o==1?1:-1;
			S[z]+=o==1?1:-1;
			if(S[z])cg(1,1,n,dfn[z],z);
			else cg(1,1,n,dfn[z],0);
		}
		else{
			int xx=H.first().x,y=kth(xx,x),z=kth(y,x);assert(num==ask(n));
			if(ask(dfn[z]+siz[z]-1)-ask(dfn[z]-1)!=num)puts("NO");
			else{
				ans1=ans2=0,ask(1,1,n,dfn[z],dfn[z]+siz[z]-1);
				if(dis(y,ans1)>x+1||dis(y,ans2)>x+1)puts("No");
				else puts("Yes");
			}
		}
	}
}