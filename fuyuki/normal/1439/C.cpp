#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int T,n,m,a[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint();
}
struct ele{
	int maxn,minn,tag,len;ll sum;
	V init(int x){maxn=minn=tag=sum=x;}
	V pia(int x){maxn=minn=x,sum=1ll*len*x,tag=x;}
}t[N<<2];
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V upd(int p){
	t[p].sum=t[lc].sum+t[rc].sum;
	t[p].maxn=max(t[lc].maxn,t[rc].maxn);
	t[p].minn=min(t[lc].minn,t[rc].minn);
}
V build(int p,int L,int R){
	if(t[p].len=R-L+1,L==R)return t[p].init(a[L]);
	int mid=L+R>>1;
	build(lson),build(rson),upd(p);
}
V init(){build(root);}
V psd(int p){if(t[p].tag)t[lc].pia(t[p].tag),t[rc].pia(t[p].tag),t[p].tag=0;}
V dfs(int p,int x){
	if(t[p].maxn<=x)return t[p].pia(x);
	if(t[p].minn>=x)return;
	dfs(lc,x),dfs(rc,x),upd(p);
}
V modify(int p,int L,int R,int l,int r,int x){
	if(L==l&&R==r)return dfs(p,x);
	int mid=L+R>>1;psd(p);
	if(l>mid)return modify(rson,l,r,x),upd(p);
	if(r<=mid)return modify(lson,l,r,x),upd(p);
	modify(lson,l,mid,x),modify(rson,mid+1,r,x),upd(p);
}
ll ask(int p,int L,int R,int l,int r){
	if(l>r)return 0;
	if(L==l&&R==r)return t[p].sum;
	int mid=L+R>>1;psd(p);
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)+ask(rson,mid+1,r);
}
I findsum(int p,int L,int R,ll x){
	if(L==R)return L;
	int mid=L+R>>1;psd(p);
	if(t[lc].sum+t[rc].maxn<=x)
		return findsum(rson,x-t[lc].sum);
	else return findsum(lson,x);
}
I findval(int p,int L,int R,int x){
	if(t[p].minn>x)return n+1;
	if(L==R)return L;
	int mid=L+R>>1;psd(p);
	if(t[lc].minn<=x)return findval(lson,x);
	else return findval(rson,x);
}
V work(){
//	cout<<ask(root,3,10)<<'\n';
	for(int opt,x,y,p,out;out=0,m--;){
		opt=getint(),x=getint(),y=getint();
		if(opt==1)modify(root,1,x,y);
		else{
			while(cmax(x,findval(root,y)),x<=n){
				p=findsum(root,ask(root,1,x-1)+y);
				y-=ask(root,x,p),out+=p-x+1,x=p+1;
			}
			cout<<out<<'\n';
		}
	}
}
int main(){
//	freopen("test.in","r",stdin);  
//	freopen(".out","w",stdout);
	input();
	init();
	work();
	return 0;
}