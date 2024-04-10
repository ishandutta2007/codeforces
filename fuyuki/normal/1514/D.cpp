#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
const int N=3e5+1,mod=1e9+7;
//V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int n,q,a[N];
vector<int>c[N];
struct ele{
	int x,c;
	ele operator+(const ele&u)const{
		if(x==u.x)return(ele){x,c+u.c};
		if(c>u.c)return(ele){x,c-u.c};
		else return (ele){u.x,u.c-c};
	}
}t[N<<2];
V input(){
	n=getint(),q=getint();
	FOR(i,1,n)a[i]=getint(),c[a[i]].push_back(i);
}
#define lc p<<1
#define rc lc|1
#define root 1,1,n
#define lson lc,L,mid
#define rson rc,mid+1,R
V build(int p,int L,int R){
	if(L==R)return t[p]=(ele){a[L],1},void();
	int mid=L+R>>1;
	build(lson),build(rson),t[p]=t[lc]+t[rc];
}
I ask(int x,int l,int r){
	return lower_bound(c[x].begin(),c[x].end(),r+1)-lower_bound(c[x].begin(),c[x].end(),l);
}
V init(){
	build(root);
}
ele ask(int p,int L,int R,int l,int r){
	if(L==l&&R==r)return t[p];
	int mid=L+R>>1;
	if(l>mid)return ask(rson,l,r);
	if(r<=mid)return ask(lson,l,r);
	return ask(lson,l,mid)+ask(rson,mid+1,r);
}
V work(){
	for(int l,r,x,c,d;q--;){
		l=getint(),r=getint(),x=ask(root,l,r).x;
		c=ask(x,l,r),d=r-l+1-c;
//		if(c>(r-l+2)/2)cout<<(c+d)/(d+1)<<'\n';
//		else cout<<1<<'\n';
//		cout<<c-d<<'\n';
		if(c>d)cout<<c-d<<'\n';
		else cout<<1<<'\n';
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}