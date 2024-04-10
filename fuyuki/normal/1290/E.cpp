#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=15e4+1,INF=0x3f3f3f3f;
ll ans[N];
int n,a[N],b[N],c[N];
I lowbit(int x){return x&-x;}
V add(int x){while(x<=n)c[x]++,x+=lowbit(x);}
I ask(int x){return!x?0:(c[x]+ask(x^lowbit(x)));}
struct ele{
	struct node{
		int val,cnt;
		V set(int x,int y){val=x,cnt=y;}
		B operator<(const node&u)const{return val<u.val;}
		node operator+(const node&u)const{
			return(val==u.val)?(node){val,cnt+u.cnt}:max(*this,u);
		}
	}x,y;
	ll sum;int tag_max,tag_sum,siz;
	I val(){return x.val;}
	V add_max(int w){sum+=1ll*w*x.cnt,x.val+=w,tag_max+=w;}
	V add_sum(int w){
		sum+=1ll*w*siz,tag_sum+=w;
		if(x.cnt)x.val+=w;
		if(y.cnt)y.val+=w;
	}
	V clean(){sum=tag_max=tag_sum=siz=0,x.set(0,0),y.set(-INF,0);}
}t[N<<2];
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
#define tree int p,int L,int R
V upd(int p){
	t[p].sum=t[lc].sum+t[rc].sum,t[p].x=t[lc].x+t[rc].x;
	if(t[lc].val()==t[rc].val())t[p].y=t[lc].y+t[rc].y;
	else t[p].y=t[lc].y+t[rc].y+min(t[lc].x,t[rc].x);
}
V psd(int p){
	int tmp=max(t[lc].val(),t[rc].val());
	if(t[lc].val()==tmp)t[lc].add_max(t[p].tag_max);
	if(t[rc].val()==tmp)t[rc].add_max(t[p].tag_max);
	t[lc].add_sum(t[p].tag_sum),t[rc].add_sum(t[p].tag_sum);
	t[p].tag_max=t[p].tag_sum=0;
}
V input(){scanf("%d",&n);FOR(i,1,n)scanf("%d",a+i);}
V build(tree){
	t[p].clean();
	if(L==R)return;
	int mid=L+R>>1;
	build(lson),build(rson),upd(p);
}
V dfs(int p,int x){
	if(t[p].val()<=x)return;
	if(t[p].y.val<x)
		return t[p].add_max(x-t[p].val());
	psd(p),dfs(lc,x),dfs(rc,x),upd(p);
}
V modify(tree,int l,int r,int x){
	if(l==L&&R==r)return dfs(p,x);
	int mid=L+R>>1;psd(p);
	if(r<=mid)modify(lson,l,r,x);
	else if(l>mid)modify(rson,l,r,x);
	else modify(lson,l,mid,x),modify(rson,mid+1,r,x);
	upd(p);
}
V ins(tree,int l,int r,int x,int flag){
	t[p].siz+=flag;
	if(l==L&&R==r){
		if(flag)t[p].x.cnt=1;
		return t[p].add_sum(x);
	}
	int mid=L+R>>1;psd(p);
	if(r<=mid)ins(lson,l,r,x,flag);
	else if(l>mid)ins(rson,l,r,x,flag);
	else ins(lson,l,mid,x,flag),ins(rson,mid+1,r,x,flag);
	upd(p);
}
V init(){
	build(1,1,n),memset(c,0,n+1<<2);
	FOR(i,1,n)b[a[i]]=i;
}
V solve(){
	init();
	FOR(i,1,n){
		modify(root,1,b[i],ask(b[i])),ins(root,b[i],b[i],i-1,1);
		ins(root,b[i],n,1,0),add(b[i]),ans[i]+=t[1].sum;
	}
}
V work(){
	solve(),reverse(a+1,a+1+n),solve();
	FOR(i,1,n)cout<<ans[i]-1ll*i*i<<'\n';
}
int main(){
	input();
	work();
	return 0;
}