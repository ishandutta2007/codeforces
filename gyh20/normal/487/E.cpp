#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
void print(int x)
{
	if(x>9)print(x/10);
	pc(x%10^48,false);
}
inline void printnum(int x,char ch)
{
	print(x),pc(ch,false);
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,stk[100002],tot,head[100002],cnt,dfn[200002],low[100002],tim,val[200002],siz[200002],sum,tp,pl[200002],son[200002],tr[800002],top[200002],fa[200002],dep[200002],a[200002],ans,q;
struct heap{
	priority_queue<int>q,d;
	inline void insert(re int x){q.push(x);}
	inline void del(re int x){d.push(x);}
	inline int first(){
		while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();
		return q.top();
	}
}s[200002];
struct edge{int to,next;}e[400002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
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
    inline T* allocate(size_t n){
        T *result=(T*)sp;sp+=n*sizeof(T);
        return result;
    }
    inline void deallocate(T* p,size_t n){}
};
vector<int,myalloc<int> >g[200002];
inline char nc(){
	re char v=gc();
	while(v!='A'&&v!='C')v=gc();
	return v;
}
inline void tj(re int x){
	dfn[x]=low[x]=++tim,stk[++tp]=x,++sum;
	for(re int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to]){
			tj(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
			if(low[e[i].to]==dfn[x]){
				++tot;
				while(1){
					g[tot].push_back(stk[tp]);
					g[stk[tp]].push_back(tot);
					if(stk[tp--]==e[i].to)break;
				}
				g[x].push_back(tot);
				g[tot].push_back(x);
			}
		}
		else low[x]=min(low[x],dfn[e[i].to]);
}
inline void dfs1(re int x,re int y){
	siz[x]=1,fa[x]=y,dep[x]=dep[y]+1;
	for(re int i=0;i<g[x].size();++i)
		if(g[x][i]^y){
			dfs1(g[x][i],x);
			siz[x]+=siz[g[x][i]];
			if(siz[g[x][i]]>siz[son[x]])son[x]=g[x][i];
		}
}
inline void dfs2(re int x,re int y){
	dfn[x]=++tim,pl[tim]=x,top[x]=y;
	if(son[x])dfs2(son[x],y);
	for(re int i=0;i<g[x].size();++i)if(g[x][i]!=fa[x]&&g[x][i]!=son[x])dfs2(g[x][i],g[x][i]);
}
inline void mdf(re int p,re int l,re int r,re int x){
	if(l==r){
		tr[p]=pl[l]>n?-s[pl[l]].first():1e9;
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)mdf(p<<1,l,mid,x);
	else mdf(p<<1|1,mid+1,r,x);
	tr[p]=min(tr[p<<1],tr[p<<1|1]);
}
inline void cg(re int x,re int y,re int z){
	s[x].del(-y);
	s[x].insert(-z);
	mdf(1,1,tot,dfn[x]);
}
inline void ask(re int p,re int l,re int r,re int x,re int y){
	if(tr[p]>=ans)return;
	if(l>=x&&r<=y){ans=tr[p];return;}
	re int mid=l+r>>1;
	if(y<=mid)ask(p<<1,l,mid,x,y);
	else if(x>mid)ask(p<<1|1,mid+1,r,x,y);
	else{
		if(tr[p<<1]<tr[p<<1|1])ask(p<<1,l,mid,x,y),ask(p<<1|1,mid+1,r,x,y);
		else ask(p<<1|1,mid+1,r,x,y),ask(p<<1,l,mid,x,y);
	}
}
inline void build(re int p,re int l,re int r){
	if(l==r){
		tr[p]=pl[l]>n?-s[pl[l]].first():1e9;
		return;
	}
	re int mid=l+r>>1;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	tr[p]=min(tr[p<<1],tr[p<<1|1]);
}
inline int ask(re int x,re int y){
	ans=1e9;
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ask(1,1,tot,dfn[top[x]],dfn[x]),x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ask(1,1,tot,dfn[x],dfn[y]);
	if(x>n&&fa[x])ans=min(ans,a[fa[x]]);
	else if(x<=n)ans=min(ans,a[x]);
	return ans;
}
int main(){
	tot=n=read(),m=read(),q=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x);
	tj(1),tim=0,dfs1(tot,0),dfs2(tot,tot);
	for(re int i=1;i<=n;++i)s[fa[i]].insert(-a[i]);
	build(1,1,tot);
	while(q--){
		re int x=nc(),y=read(),z=read();
		if(x=='A')printnum(ask(y,z),'\n');
		else{
			cg(fa[y],a[y],z);
			a[y]=z;
		}
	}
	pc('o',1);
}