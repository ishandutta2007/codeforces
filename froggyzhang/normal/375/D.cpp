#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define re register
#define N 100010
inline int read(){
	int x=0,f=1;
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
int n,m,c[N],siz[N];
int e_cnt=0,head[N],dfn[N],tot,g[N],l=0,r=0,s[N],cnt[N],len;
int Ans[N];
struct Edge{
	int to,nxt;
}edge[N<<1];
inline void add(int a,int b){
	e_cnt++;
	edge[e_cnt].nxt=head[a];
	edge[e_cnt].to=b;
	head[a]=e_cnt;
}
struct Mo{
	int l,r,k,id,pos;
}q[N];
bool cmp1(Mo x,Mo y){
	return (x.pos)^(y.pos)?x.l<y.l:(((x.pos)&1)?x.r<y.r:x.r>y.r);
}
void dfs(int u,int fa){
	siz[u]=1;
	g[++tot]=u;
	dfn[u]=tot;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
inline void add(int x){
	cnt[c[x]]++;
	s[cnt[c[x]]]++;
}
inline void del(int x){
	s[cnt[c[x]]]--;
	cnt[c[x]]--;
}
int main(){
	//freopen("count.in","r",stdin);
	//freopen("count.out","w",stdout);
	n=read();m=read();
	len=sqrt(n);
	for(re int i=1;i<=n;i++){
		c[i]=read();
	}
	for(re int i=1;i<=n-1;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	for(re int i=1;i<=m;++i){
		int x=read();
		q[i].l=dfn[x];
		q[i].r=dfn[x]+siz[x]-1;
		q[i].k=read();
		q[i].id=i;
		q[i].pos=q[i].l/len;
	}
	sort(q+1,q+m+1,cmp1);
	s[0]=n;
	for(re int i=1;i<=m;++i){
		int ql=q[i].l,qr=q[i].r;
		while(l<ql)del(g[l++]);
		while(l>ql)add(g[--l]);
		while(r<qr)add(g[++r]);
		while(r>qr)del(g[r--]);
		Ans[q[i].id]=s[q[i].k];
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",Ans[i]);
	}
	return 0;
}