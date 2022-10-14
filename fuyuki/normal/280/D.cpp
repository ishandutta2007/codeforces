#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e5+1,INF=0x3f3f3f3f;
ll ans;
int n,m,a[N];
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
#define tree int p,int L,int R
struct node{
	int l,r,sum;
	V init(){l=1,r=0,sum=-INF;}
	I operator<(const node&u)const{return sum<u.sum;}
	node operator+(const node&u)const{return(node){l,u.r,sum+u.sum};}
};
struct seg{
	int opt;
	struct ele{
		node lval,rval,maxn,sum;
		V clean(){lval.init(),rval.init(),maxn.init(),sum.init();}
		V init(int x){lval=rval=maxn=sum=(node){x,x,a[x]};}
		ele operator+(const ele&u)const{
			static ele out;
			out.sum=sum+u.sum;
			out.lval=max(lval,sum+u.lval);
			out.rval=max(rval+u.sum,u.rval);
			out.maxn=max(rval+u.lval,max(maxn,u.maxn));
			return out;
		}
	}t[N<<2],tmp;
	V build(tree){
		if(L==R)return t[p].init(L);
		int mid=L+R>>1;
		build(lson),build(rson),t[p]=t[lc]+t[rc];
	}
	V ask(tree,int l,int r){
		if(L==l&&R==r)return void(tmp=tmp+t[p]);
		int mid=L+R>>1;
		if(l>mid)return ask(rson,l,r);
		if(r<=mid)return ask(lson,l,r);
		ask(lson,l,mid),ask(rson,mid+1,r);
	}
	V modify(tree,int x){
		if(L==R)return t[p].init(L);
		int mid=L+R>>1;
		(x<=mid?modify(lson,x):modify(rson,x)),t[p]=t[lc]+t[rc];
	}
	node ask(int l,int r){return tmp.clean(),ask(root,l,r),tmp.maxn;}
}T[2];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	m=getint();
}
V init(){
	T[0].build(root),T[0].opt=-1;
	FOR(i,1,n)a[i]=-a[i];
	T[1].build(root),T[1].opt=1;
}
#define P pair<node,node>
priority_queue<P>q;
P mk(int l,int r,int p){
	return P(T[p].ask(l,r),(node){l,r,p});
}
I ask(int l,int r,int k){
	int p,ans=0;
	while(!q.empty())q.pop();
	q.push(mk(l,r,0));
	for(P x;k--;){
		x=q.top(),q.pop(),p=x.second.sum;
		if(x.first.sum<0)break;
		ans+=x.first.sum;
		if(x.second.l<x.first.l)q.push(mk(x.second.l,x.first.l-1,p));
		if(x.second.r>x.first.r)q.push(mk(x.first.r+1,x.second.r,p));
		q.push(mk(x.first.l,x.first.r,p^1));
	}
	return ans;
}
V work(){
	for(int opt,l,r,x;m--;){
		opt=getint();
		if(opt==0){
			x=getint(),a[x]=getint();
			T[0].modify(root,x),a[x]=-a[x];
			T[1].modify(root,x);
		}
		else l=getint(),r=getint(),x=getint(),cout<<ask(l,r,x)<<'\n';
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}