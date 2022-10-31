#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=20005,NC=N*25;typedef long long ll;
int a[N],f[N],g[N],nxt[N],pre[N],tot=0;
inline ll cross(int x1,int y1,int x2,int y2){return 1LL*x1*y2-1LL*y1*x2;}
struct Hull{
	int head,tail,s;
	Hull(){head=tail=s=0;}
	void push_back(int x){
		if(!s)head=tail=x,pre[x]=nxt[x]=0,s=1;
		else{
			while(s>=2&&cross(tail-x,f[tail]-f[x],pre[tail]-x,f[pre[tail]]-f[x])>=0)tail=pre[tail],--s;
			nxt[tail]=x,pre[x]=tail,nxt[x]=0,tail=x,++s;
		}
	}
	void push_front(int x){
		if(!s)head=tail=x,pre[x]=nxt[x]=0,s=1;
		else{
			while(s>=2&&cross(head-x,f[head]-f[x],nxt[head]-x,f[nxt[head]]-f[x])<=0)head=nxt[head],--s;
			pre[head]=x,nxt[x]=head,pre[x]=0,head=x,++s;
		}
	}
	int ask(int x){
		if(!s)return 1e9;
		while(s>=2&&f[nxt[head]]-f[head]<x*(nxt[head]-head))head=nxt[head],--s,++tot;
		return f[head]-head*x;
	}
};
int st[N],top;Hull b[N];
Hull merge(Hull a,Hull b){
	if(a.s<b.s){
		int u,to=a.tail;
		do{u=to,to=pre[u],b.push_front(u);}while(u!=a.head);
		return b;
	}
	else{
		int u,to=b.head;
		do{u=to,to=nxt[u],a.pb(u);}while(u!=b.tail);
		return a;
	}
}
struct line{int k,b;inline int get(int x)const{return k*x+b;}};
namespace DS{
int ls[NC],rs[NC],nc;line f[NC];
void build(int l,int r,int &u){
	u=++nc;if(l==r)return;
	int mid=(l+r)>>1;build(l,mid,ls[u]),build(mid+1,r,rs[u]);
}
void Update(const line &o,int l,int r,int &rt){
	int u=++nc;f[u]=f[rt],ls[u]=ls[rt],rs[u]=rs[rt];rt=u;
	if(!f[u].k)return f[u]=o,void();
	int al=f[u].get(l),ar=f[u].get(r),bl=o.get(l),br=o.get(r);
	if(al<=bl&&ar<=br)return;
	if(al>=bl&&ar>=br)return f[u]=o,void();
	int mid=(l+r)>>1;
	if(f[u].get(mid)<=o.get(mid)){
		if(al<=bl)Update(o,mid+1,r,rs[u]);
		else Update(o,l,mid,ls[u]);
	}
	else{
		if(al<=bl)Update(f[u],l,mid,ls[u]),f[u]=o;
		else Update(f[u],mid+1,r,rs[u]),f[u]=o;
	}
}
int ask(int x,int l,int r,int u){
	if(!f[u].k)return 1e9;
	if(l==r)return f[u].get(x);
	int mid=(l+r)>>1;
	return std::min(f[u].get(x),x<=mid?ask(x,l,mid,ls[u]):ask(x,mid+1,r,rs[u]));
}
}
int rt[N];
int main(){
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)read(a[i]);
	memset(f,63,sizeof(f)),f[0]=0;
	while(k--){
		memset(g,63,sizeof(g));
		for(int i=0;i<=n;++i)pre[i]=nxt[i]=0;
		for(int i=0;i<=top;++i)b[i]=Hull();
		top=0,DS::nc=0,rt[0]=0,DS::build(1,n,rt[0]);
		for(int i=1;i<=n;++i){
			Hull cur;cur.pb(i-1);
			while(top&&a[i]>a[st[top]])cur=merge(b[top],cur),--top;
			st[++top]=i,rt[top]=rt[top-1],DS::Update({a[i],cur.ask(a[i])},1,n,rt[top]),b[top]=cur;
			g[i]=DS::ask(i,1,n,rt[top]);
		}
		memcpy(f,g,sizeof(f));
	}
	printf("%d\n",f[n]);
	return 0;
}