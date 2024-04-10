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
const int N=5e5+1,INF=0x3f3f3f3f;
vector<P>q[N];
int n,m,a[N],ans[N],t[N<<2];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint();
	int l,r;
	FOR(i,1,m)l=getint(),r=getint(),q[n-r].push_back(P(i,l));
}
#define lc p<<1
#define rc lc|1
#define root 1,0,n+1
#define lson lc,L,mid
#define rson rc,mid+1,R
V add(int p,int L,int R,int x){
	if(t[p]++,L==R)return;
	int mid=L+R>>1;
	x<=mid?add(lson,x):add(rson,x);
}
I ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p];
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)+ask(rson,mid+1,r);
}
I calc(int p,int L,int R,int x){
	if(L==R)return L;
	int mid=L+R>>1;
	if(t[rc]>=x)return calc(rson,x);
	else return calc(lson,x-t[rc]);
}
V init(){
	FOR(i,1,n){
		if(a[i]<=i&&i-a[i]<=t[1])add(root,min(i-1,calc(root,i-a[i])));
		for(P v:q[i])ans[v.first]=ask(root,v.second,i);
	}
}
V work(){FOR(i,1,m)cout<<ans[i]<<'\n';}
int main(){
	input();
	init();
	work();
	return 0;
}