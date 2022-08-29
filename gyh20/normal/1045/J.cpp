
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
#define O4 __inline__ __attribute__((always_inline))
int n,m,siz[600002],son[600002],g[1200002],cnt,fa[600002],fs[600002],dep[600002],tim,dfn[600002],top[600002],pl[600002],ans[600002],b[600002],head[600002],head1[600002],cnt1;
char a[600002];
struct edge{int to,next,w;}e[1200002],e1[1200002];
inline void add(re int x,re int y,re int z){
	e[++cnt]=(edge){y,head[x],z};
	head[x]=cnt;
}
inline void add1(re int x,re int y,re int z){
	e1[++cnt1]=(edge){y,head1[x],z};
	head1[x]=cnt1;
}
static char space[8000005],*sp=space;
template<typename T>
struct myalloc:allocator<T>{
    myalloc(){}
    template<typename T2>
    myalloc(const myalloc<T2> &a){}
    template<typename T2>
    myalloc<T>& operator=(const myalloc<T2> &a){return *this;}
    template<typename T2>
    struct rebind{typedef myalloc<T2> other;};
    O4 T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    O4 void deallocate(T* p,size_t n){}
};
vector<int,myalloc<int> >v[600002];
inline void dfs1(re int x,re int y){
	fa[x]=y,siz[x]=1,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			fs[e[i].to]=e[i].w;
			dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void dfs2(re int x,re int y){
	dfn[x]=++tim,top[x]=y,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)if((e[i].to^fa[x])&&(e[i].to^son[x]))dfs2(e[i].to,e[i].to);
}
inline int kth(re int x,re int y){
	while(dep[x]-dep[top[x]]<y)y-=dep[x]-dep[top[x]]+1,x=fa[top[x]];
	return pl[dfn[x]-y];
}
inline int lca(re int x,re int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
namespace KMP{
	int nxt[1000002];
	inline void cross(int x,int y,int z,int len,int&ret) {
		int t=0,i,j,A=kth(x,dep[x]-min(dep[z]+len-1,dep[x])),B=kth(y,dep[y]-min(dep[z]+len-1,dep[y]));
		for(nxt[0]=j=-1,i=1; i<len; nxt[i++]=j) {
			while(~j&&a[j+1]!=a[i])j=nxt[j];
			if(a[j+1]==a[i])j++;
		}
		for(j=-1; A!=z; A=fa[A]) {
			while(~j&&a[j+1]!=fs[A])j=nxt[j];
			if(a[j+1]==fs[A])j++;
			if(j==len-1)ret++,j=nxt[j];
		}
		while(B!=z)b[++t]=fs[B],B=fa[B];
		while(t) {
			while(~j&&a[j+1]!=b[t])j=nxt[j];
			if(a[j+1]==b[t])j++;
			if(j==len-1)ret++,j=nxt[j];
			t--;
		}
	}
}
struct AC{
	struct edg{int to,next;}e[1000002];
	int n,cnt,tot,f[1000002],ch[1000002][26],head[1000002],dfn[1000002],tim,siz[1000002],c[1000002],q[1000002],hd,tl;
	inline void add(re int x){for(;x<=tot;x+=x&(-x))++c[x];}
	inline void del(re int x){for(;x<=tot;x+=x&(-x))--c[x];}
	inline int ask(re int x){re int sum=0;for(;x;x-=x&(-x))sum+=c[x];return sum;}
	inline void add(re int x,re int y){e[++cnt]=(edg){y,head[x]};head[x]=cnt;}
	inline int ins(re int len){
		re int nw=0;
		for(re int i=0;i<len;++i){
			if(!ch[nw][a[i]])ch[nw][a[i]]=++tot;
			nw=ch[nw][a[i]];
		}
		return nw;
	}
	inline int ins1(re int len){
		re int nw=0;
		for(re int i=len-1;~i;--i){
			if(!ch[nw][a[i]])ch[nw][a[i]]=++tot;
			nw=ch[nw][a[i]];
		}
		return nw;
	}
	inline void dfs(re int x){
		dfn[x]=++tim,siz[x]=1;
		for(re int i=head[x];i;i=e[i].next)dfs(e[i].to),siz[x]+=siz[e[i].to];
	}
	inline int askk(re int x){return ask(dfn[x]+siz[x]-1)-ask(dfn[x]-1);}
	inline void pre(){
		hd=1;
		for(re int i=0;i<26;++i)if(ch[0][i])q[++tl]=ch[0][i];f[1]=0;
		while(hd<=tl){
			for(re int i=0;i<26;++i)
				if(ch[q[hd]][i]){
					q[++tl]=ch[q[hd]][i];
					f[ch[q[hd]][i]]=ch[f[q[hd]]][i];
				}
				else ch[q[hd]][i]=ch[f[q[hd]]][i];
			++hd;
		}
		for(re int i=1;i<=tot;++i)add(f[i],i);++tot;
		dfs(0);
	}
}T;
inline void dfs(re int x,re int y){
	T.add(T.dfn[y]);
	for(re int i=head1[x];i;i=e1[i].next){
		re int xx=e1[i].to,yy=e1[i].w;
		if(yy>0)ans[yy]+=T.askk(xx);
		else ans[-yy]-=T.askk(xx);
	}
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^fa[x])dfs(e[i].to,T.ch[y][e[i].w]);
	T.del(T.dfn[y]);
}
int main(){
	n=read();
	for(re int i=1,x,y;i<n;++i){
		x=read(),y=read(),scanf("%s",a);
		add(x,y,a[0]-'a'),add(y,x,a[0]-'a');
	}
	dfs1(1,1);dfs2(1,1),m=read();
	re int kk=m;
	for(re int ii=1;(ii-1)*10000<=kk;++ii){
		memset(&T,0,sizeof(AC));
		memset(head1,0,sizeof(head1)),cnt1=0;
		memset(ans,0,sizeof(ans));
		if(ii*10000>kk)m=kk%10000;
		else m=10000;
		for(re int i=1,x,y,z,len;i<=m;++i){
			x=read(),y=read(),scanf("%s",a),len=strlen(a);z=lca(x,y);
			for(re int j=0;j<len;++j)a[j]-='a';
			KMP::cross(x,y,z,len,ans[i]);
			if(dep[x]-dep[z]>=len){
				re int j=T.ins1(len),xx=kth(x,dep[x]-dep[z]-len+1);
				add1(x,j,i);
				add1(xx,j,-i);
			}
			if(dep[y]-dep[z]>=len){
				re int j=T.ins(len),xx=kth(y,dep[y]-dep[z]-len+1);
				add1(y,j,i);
				add1(xx,j,-i);
			}
		}
		T.pre();
		dfs(1,0);
		for(re int i=1;i<=m;++i)printf("%d\n",ans[i]);
	}
}