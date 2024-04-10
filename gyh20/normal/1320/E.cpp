#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	int k=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0'){
		k=k*10+ch-48;
		ch=getchar();
	}
	return k;
}
const int maxn=2e5+5;
const int inf=1e9;
int n,m,Q,num1,num2;
int h[maxn],H[maxn],Cnt,cnt;
struct d{
	int to,next;
}a[maxn*2],A[maxn*2];
inline void add(int x,int y){
	a[++cnt]=(d){y,h[x]};
	h[x]=cnt;
}
int fa[maxn],dept[maxn],siz[maxn],son[maxn],top[maxn],dfn[maxn],Sign;
void dfs1(int x,int father){
	fa[x]=father;dept[x]=dept[fa[x]]+1;siz[x]=1;
	for(int i=h[x];i;i=a[i].next){
		if(a[i].to==fa[x])continue;
		dfs1(a[i].to,x);
		siz[x]+=siz[a[i].to];
		if(siz[a[i].to]>siz[son[x]])son[x]=a[i].to;
	}
}
void dfs2(int x,int Top){
	top[x]=Top;dfn[x]=++Sign;
	if(!son[x])return;
	dfs2(son[x],Top);
	for(int i=h[x];i;i=a[i].next){
		if(a[i].to==fa[x]||a[i].to==son[x])continue;
		dfs2(a[i].to,a[i].to);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dept[top[x]]<dept[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dept[x]<dept[y])swap(x,y);
	return y;
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void Add(int x,int y){
//	cout<<x<<' '<<y<<'\n';
	A[++Cnt]=(d){y,H[x]};
	H[x]=Cnt;
}
int num,s[maxn];
void insert(int x){
	if(x==1){return;}
	if(num==1){s[++num]=x;return;}
	int lca=LCA(s[num],x);
	while(num>1&&dfn[s[num-1]]>=dfn[lca]){
		Add(s[num-1],s[num]);
		--num;
	}
	if(lca!=s[num]){
		Add(lca,s[num]);
		s[num]=lca;
	}
	s[++num]=x;
	return;
}
int p[maxn*2],q[maxn];
void build(){
	num=0;s[++num]=1;
	sort(p+1,p+1+p[0],cmp);
	p[0]=unique(p+1,p+1+p[0])-p-1;
	for(int i=1;i<=p[0];++i)insert(p[i]);
	while(num>1)Add(s[num-1],s[num]),--num;
}
struct point{
	int x,y;
	bool operator<(const point& A)const{
		return x==A.x?y<A.y:x<A.x;
	}
}c[maxn],col[maxn];
const point Inf=(point){inf,inf};
int lj[maxn],bel[maxn];
point Get(int x,int y){
	int lca=LCA(x,c[y].x),dis=dept[x]+dept[c[y].x]-2*dept[lca];
	return (point){(dis-1)/c[y].y+1,y};
}
void dfs3(int x,int father){
	lj[++lj[0]]=x;
	if(!bel[x])col[x]=Inf;
	for(int i=H[x];i;i=A[i].next){
		if(A[i].to==father)continue;
		dfs3(A[i].to,x);
		int k=bel[A[i].to];
		if(!k)continue;
		point now=Get(x,k);
		if(now<col[x])col[x]=now,bel[x]=bel[A[i].to];
	}
}
void dfs4(int x,int father){
	if(father&&x!=c[bel[x]].x){
		point k=Get(x,bel[father]);
		if(k<col[x])col[x]=k,bel[x]=bel[father];
	}
	for(int i=H[x];i;i=A[i].next){
		if(A[i].to==father)continue;
		dfs4(A[i].to,x);
	}
}
void Solve(){
	build();dfs3(1,0);dfs4(1,0);
}
void Clear(){
	for(int i=1;i<=lj[0];++i){
		bel[lj[i]]=0;H[lj[i]]=0;
	}
	Cnt=0;p[0]=0;lj[0]=0;
}
int main(){
	n=read();
	int x,y;
	for(int i=1;i<n;++i){
		x=read();y=read();
		add(x,y);add(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	Q=read();
	for(int i=1;i<=Q;++i){
		num1=read();num2=read();
		for(int i=1;i<=num1;++i){
			c[i]=(point){read(),read()};
			bel[c[i].x]=i;p[++p[0]]=c[i].x;
			col[c[i].x]=(point){0,i};
		}
		for(int i=1;i<=num2;++i){
			q[i]=read();p[++p[0]]=q[i];
		}
		Solve();
		for(int i=1;i<=num2;++i)cout<<col[q[i]].y<<' ';cout<<'\n';
		Clear();
	}
	return 0;
}