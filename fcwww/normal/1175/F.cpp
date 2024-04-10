#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 300050
#define ls p<<1
#define rs p<<1|1
typedef long long ll;
int n,a[N],lb[N],pre[N],S[N],tp,now[N];
ll ans;
int tag[N<<2];
struct A {
	int x,v;
	A() {}
	A(int x_,int v_) {x=x_,v=v_;}
	A operator + (const A &u) const {
		if(x<u.x)return A(x,v);
		if(x>u.x)return A(u.x,u.v);
		return A(x,v+u.v);
	}
}tr[N<<2];
inline void giv(int l,int r,int p,int v) {
	tag[p]=v; tr[p].x=v+l-1; tr[p].v=1;
}
inline void pushdown(int l,int r,int p) {
	if(tag[p]!=-1) {
		int mid=(l+r)>>1;
		giv(l,mid,ls,tag[p]);
		giv(mid+1,r,rs,tag[p]);
		tag[p]=-1;
	}
}
A query(int l,int r,int x,int y,int p) {
	if(x<=l&&y>=r) return tr[p];
	int mid=(l+r)>>1; pushdown(l,r,p);
	if(y<=mid) return query(l,mid,x,y,ls);
	else if(x>mid) return query(mid+1,r,x,y,rs);
	return query(l,mid,x,y,ls)+query(mid+1,r,x,y,rs);
}
inline void pushup(int p) {
	tr[p]=tr[ls]+tr[rs];
}
void fix(int l,int r,int x,int y,int v,int p) {
	if(x<=l&&y>=r) {giv(l,r,p,v); return ;}
	int mid=(l+r)>>1; pushdown(l,r,p);
	if(x<=mid) fix(l,mid,x,y,v,ls);
	if(y>mid) fix(mid+1,r,x,y,v,rs);
	pushup(p);
}
void UPD(int l,int r,int x,int v,int p) {
	if(l==r) {tr[p].x=v; tr[p].v=1; return ;}
	int mid=(l+r)>>1; pushdown(l,r,p);
	if(x<=mid) UPD(l,mid,x,v,ls);
	else UPD(mid+1,r,x,v,rs);
	pushup(p);
}
void build(int l,int r,int p) {
	if(l==r) {
		tr[p].x=1<<30; tr[p].v=1; return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,ls),build(mid+1,r,rs);
	pushup(p);
}
int main() {
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) {
		pre[i]=now[a[i]]; now[a[i]]=i;
	}
	for(i=1;i<=n;i++) {
		while(tp&&a[S[tp]]<=a[i])tp--;
		if(tp)lb[i]=S[tp];
		else lb[i]=0;
		S[++tp]=i;
	}
	build(1,n,1);
	//for(i=1;i<=n;i++) printf("%d\n",lb[i]);
	memset(tag,-1,sizeof(tag));
	int nl=1;
	for(i=1;i<=n;i++) {
		nl=max(nl,pre[i]+1);
		int x=lb[i];
		UPD(1,n,i,a[i]+i-1,1);
		if(x+1<=i-1) {
			fix(1,n,x+1,i-1,a[i],1);
		}
		A t=query(1,n,nl,i,1);
		if(t.x==i) {
			//printf("%d %d t.x=%d t.v%d\n",i,nl,t.x,t.v);
			ans+=t.v;
		}
	}
	printf("%lld\n",ans);
}