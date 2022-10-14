#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define FOR(i,a,b) for(int i=a;i<=n;i++)
const int N=2e5;
int n,m,k,a[N];
struct ele{
	vector<P>c;int tag,len;
	V init(int x){c=vector<P>{P(x,len)},tag=x;}
	V output(){cout<<c.size()<<' ';for(auto v:c)cout<<v.first<<' ';}
	V ins(int x,int y){
		for(auto&v:c)if(v.first==x)return void(v.second+=y);
		if(c.size()<k)return c.push_back(P(x,y));
		for(auto&v:c)if(v.second<y)swap(v.first,x),swap(v.second,y);
		for(auto&v:c)v.second-=y;
	}
	V push(const ele&u){for(const auto&v:u.c)ins(v.first,v.second);}
}t[N<<2],tmp;
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V input(){
	scanf("%d%d%d",&n,&m,&k),k=100/k;
	FOR(i,1,n)scanf("%d",a+i);
}
V upd(int p){t[p].c=t[lc].c,t[p].push(t[rc]);}
V psd(int p){if(t[p].tag)t[lc].init(t[p].tag),t[rc].init(t[p].tag),t[p].tag=0;}
V build(int p,int L,int R){
	if(t[p].len=R-L+1,L==R)return t[p].init(a[L]);
	int mid=L+R>>1;
	build(lson),build(rson),upd(p);
}
V ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return tmp.push(t[p]);
	int mid=L+R>>1;psd(p);
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	ask(lson,l,mid),ask(rson,mid+1,r);
}
V modify(int p,int L,int R,int l,int r,int x){
	if(L==l&&R==r)return t[p].init(x);
	int mid=L+R>>1;psd(p);
	if(l>mid)return modify(rson,l,r,x),upd(p);
	if(r<=mid)return modify(lson,l,r,x),upd(p);
	modify(lson,l,mid,x),modify(rson,mid+1,r,x),upd(p);
}
V init(){build(root);}
V work(){
	for(int opt,l,r,x;m--;tmp.c.clear())
		if(scanf("%d%d%d",&opt,&l,&r),opt==1)
			scanf("%d",&x),modify(root,l,r,x);
		else ask(root,l,r),tmp.output(),cout<<'\n';
}
int main(){
	input();
	init();
	work();
	return 0;
}