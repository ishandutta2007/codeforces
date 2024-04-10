#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cstdio>
#include<vector>
#define re register
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=gc();
	}
	return t;
}
int fa[4000002],siz[4000002],tp,stx[4000002],sty[4000002],l[4000002],r[4000002],n,m,opt,x[4000002],y[4000002],typ[4000002],X[4000002],Y[4000002],aa[4000002];
vector<int>vv[4000002];
inline int root(re int p){
	while(p!=fa[p])p=fa[p];
	return p;
}
inline void merge(re int u,re int v){
	u=root(u),v=root(v);
	if(u==v)return;
	if(siz[u]>siz[v])u^=v^=u^=v;
	X[++tp]=u,Y[tp]=v;
	siz[v]+=siz[u];
	fa[u]=v;
}
inline void undo(re int p){
	while(tp>p){
		if(fa[X[tp]]==Y[tp])siz[fa[X[tp]]]-=siz[X[tp]];
		fa[X[tp]]=X[tp];
		--tp;
	}
}
inline void solve(re int p,re int L,re int R){
	bool ia=1;
	int sz=vv[p].size(),q=tp;
	for(re int i=0;i<sz;++i){
		int X=root(x[vv[p][i]]),Y=root(y[vv[p][i]]);
		if(X==Y){
			undo(q);
			return;
		}
	merge(x[vv[p][i]]+n,y[vv[p][i]]),merge(x[vv[p][i]],y[vv[p][i]]+n);}
	if(ia){
	if(L==R)aa[L]=1;
	else{
		solve(p<<1,L,L+R>>1);
		solve(p<<1|1,(L+R>>1)+1,R);
	}
	}
	undo(q);
}
inline void add(re int p,re int L,re int R,re int u,re int v,re int w){
	if(v<L)return;
	if(u>R)return;
	if(L>=u&&R<=v){vv[p].push_back(w);return;}
	add(p<<1,L,L+R>>1,u,v,w);
	add(p<<1|1,(L+R>>1)+1,R,u,v,w);
}
int main(){
	n=read();m=read();if(m==0)return puts("0"),0;
	for(re int i=1;i<=m;++i){
		x[i]=read(),y[i]=read();
		add(1,1,m,1,i-1,i);
		add(1,1,m,i+1,m,i);
	}
	for(re int i=1;i<=n;++i)fa[i]=i,fa[i+n]=i+n,siz[i]=1,siz[i+n]=1;
	solve(1,1,m);
	re int anss=0;
	for(re int i=1;i<=m;++i)anss+=aa[i];
	//if(n==10000&&m==9999&&aa[6394]&&aa[6395]&&aa[6396]&&anss<=10)printf("%d %d\n%d %d\n%d %d\n",x[6394],y[6394],x[6395],y[6395],x[6396],y[6396]);
	printf("%d\n",anss);
	for(re int i=1;i<=m;++i)if(aa[i])printf("%d ",i);
}