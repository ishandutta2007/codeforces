#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=3e5+1,mod=998244353;
int n,a[N],q[N],pos[N],tmpos[N];
struct node{
	int minn,maxn,sum;
	node operator+(const node&u)const{
		return(node){min(minn,sum+u.minn),max(maxn+u.sum,u.maxn),sum+u.sum};
	}
}t[N<<2];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint(),pos[a[i]]=i;
	FOR(i,1,n)q[i]=getint();
}
V init(){
	
}
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V upd(int p){t[p]=t[lc]+t[rc];}
V add(int p,int L,int R,int x,int y){
	if(L==R)return t[p].minn+=y,t[p].sum+=y,t[p].maxn=max(0,t[p].sum),tmpos[x]+=y,void();
	int mid=L+R>>1;
	if(x<=mid)add(lson,x,y);
	else add(rson,x,y);
	upd(p);
}
node ask(int p,int L,int R,int l,int r){
	if(l>r)return t[0];
	if(L==l&&R==r)return t[p];
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)+ask(rson,mid+1,r);
}
B check(int x){return ask(root,1,pos[x]-1).maxn+ask(root,pos[x],n).minn<=0;}
V work(){
	int ans=n;
	add(root,pos[ans],1);
	FOR(i,1,n){
		while(check(ans))add(root,pos[--ans],1);
		cout<<ans<<' ',add(root,q[i],-1);
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}