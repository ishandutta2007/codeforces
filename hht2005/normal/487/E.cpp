#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define enter pc('\n')
#define space pc(' ')
const int MAXL=1<<22;
char i_str[MAXL],o_str[MAXL],*i_s,*i_t;
int o_t;
inline char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
inline int read() {
	int x=0,f=0;
	char ch=gc();
	for(; ch<'0'||ch>'9'; ch=gc())
		if(ch=='-')f=1;
	for(; ch>='0'&&ch<='9'; ch=gc())
		x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
inline void gs(char *s) {
	*s=gc();
	while(*s==' '||*s=='\n'||*s=='	')*s=gc();
	while(*s!=' '&&*s!='\n'&&*s!='	')*++s=gc();
	*s='\0';
}
#define fl fwrite(o_str,1,o_t,stdout),o_t=0
inline void pc(char x) {
	o_str[o_t++]=x;
	if(o_t==MAXL)fl;
}
inline void write(int x) {
	if(x<0)x=-x,pc('-');
	if(x>9)write(x/10);
	pc(x%10^48);
}
const int maxn=8e5+10;
int hea[maxn],nxt[maxn],to[maxn],w[maxn],c[maxn],Top,tot;
int A[maxn],B[maxn],dfn[maxn],low[maxn],Min[maxn<<2],cnt,dfns,M,n;
int siz[maxn],son[maxn],fa[maxn],dep[maxn],pos[maxn],top[maxn];
multiset<int>s[maxn];
void add(int a,int b) {
	nxt[++tot]=hea[a];
	hea[a]=tot;
	to[tot]=b;
}
void tarjan(int x) {
	dfn[x]=low[x]=++dfns;
	c[++Top]=x;
	for(int i=hea[x];i;i=nxt[i])
		if(!dfn[to[i]]) {
			tarjan(to[i]);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>=dfn[x]) {
				cnt++;
				while(c[Top]!=to[i]) {
					A[++M]=cnt;
					B[M]=c[Top--];
				}
				A[++M]=cnt;
				B[M]=c[Top--];
				A[++M]=cnt;
				B[M]=x;
			}
		} else low[x]=min(low[x],dfn[to[i]]);
}
void dfs1(int x) {
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa[x]) {
			if(x>n)s[x].insert(w[to[i]]);
			fa[to[i]]=x;
			dfs1(to[i]);
			siz[x]+=siz[to[i]];
		}
}
void dfs2(int x) {
	if(x>n)w[x]=*s[x].begin();
	pos[dfn[x]=++dfns]=x;
	if(son[fa[x]]==x)top[x]=top[fa[x]];
	else top[x]=x;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa[x]&&siz[son[x]]<siz[to[i]])
			son[x]=to[i];
	if(son[x])dfs2(son[x]);
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]!=fa[x]&&to[i]!=son[x])
			dfs2(to[i]);
}
void build(int p,int l,int r) {
	if(l==r) {
		Min[p]=w[pos[l]];
		return;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}
void change(int p,int l,int r,int x) {
	if(l==r) {
		Min[p]=w[pos[l]];
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)change(p<<1,l,mid,x);
	else change(p<<1|1,mid+1,r,x);
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return Min[p];
	int mid=(l+r)>>1,Min=1e9;
	if(x<=mid)Min=min(Min,qry(p<<1,l,mid,x,y));
	if(y>mid)Min=min(Min,qry(p<<1|1,mid+1,r,x,y));
	return Min;
}
int qry(int x,int y) {
	int Min=1e9;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		Min=min(Min,qry(1,1,cnt,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])swap(x,y);
	Min=min(Min,qry(1,1,cnt,dfn[y],dfn[x]));
	if(y>n)Min=min(Min,w[fa[y]]);
	return Min;
}
int main() {
	int m,q,a,b;
	n=read(),m=read(),q=read();
	char opt[3];
	for(int i=1;i<=n;i++)
		w[i]=read();
	cnt=n;
	for(int i=1;i<=m;i++) {
		a=read(),b=read();
		add(a,b);
		add(b,a);
	}
	tarjan(1);
	memset(hea,tot=0,sizeof(hea));
	for(int i=1;i<=M;i++) {
		add(A[i],B[i]);
		add(B[i],A[i]);
	}
	memset(dfn,dfns=0,sizeof(dfn));
	dfs1(1);
	dfs2(1);
	build(1,1,cnt);
	while(q--) {
		gs(opt),a=read(),b=read();
		if(*opt=='C') {
			if(fa[a]) {
				s[fa[a]].erase(s[fa[a]].find(w[a]));
				s[fa[a]].insert(b);
				w[fa[a]]=*s[fa[a]].begin();
			}
			w[a]=b;
			change(1,1,cnt,dfn[fa[a]]);
			change(1,1,cnt,dfn[a]);
		} else write(qry(a,b)),enter;
	}
	return fl;
}