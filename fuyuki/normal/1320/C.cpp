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
const int N=5e5+1,INF=0x7fffffff;
int n,m,k,tot,rt,ans=-INF;
struct node{
	int v,c;
	V input(){
		v=getint(),c=getint();
	}
	B operator<(const node&u)const{
		return v<u.v;
	}
}a[N],b[N],tmp[N];
struct data{
	int a,b,c;
	V input(){
		a=getint(),b=getint(),c=getint();
	}
	B operator<(const data&u)const{
		return a<u.a;
	}
}c[N];
int maxn[N<<2],tag[N<<2];
V input(){
	n=getint(),m=getint(),k=getint();
	FOR(i,1,n)a[i].input();
	FOR(i,1,m)b[i].input();
	FOR(i,1,k)c[i].input();
}
#define lc p<<1
#define rc lc|1
#define root 1,1,m
#define lson lc,L,mid
#define rson rc,mid+1,R
V update(int p){
	maxn[p]=max(maxn[lc],maxn[rc]);
}
V solve(int p){
	if(!tag[p])return;
	tag[lc]+=tag[p],maxn[lc]+=tag[p];
	tag[rc]+=tag[p],maxn[rc]+=tag[p];
	tag[p]=0;
}
V build(int p,int L,int R){
	if(L==R)return void(maxn[p]=-b[L].c);
	int mid=L+R>>1;
	build(lson),build(rson),update(p);
}
V init(){
	sort(a+1,a+1+n),sort(b+1,b+1+m),sort(c+1,c+1+k);
	build(root);
}
V add(int p,int L,int R,int l,int r,int x){
	if(L==l&&R==r)return maxn[p]+=x,tag[p]+=x,void();
	int mid=L+R>>1;solve(p);
	if(r<=mid)return add(lson,l,r,x),update(p);
	if(l>mid)return add(rson,l,r,x),update(p);
	add(lson,l,mid,x),add(rson,mid+1,r,x),update(p);
}
I find(int x){
	int l=1,r=m+1,mid;
	while(mid=l+r>>1,l^r)
		if(b[mid].v>x)
			r=mid;
		else l=mid+1;
	return mid;
}
V work(){
	int cur=0,p;
	b[m+1].v=INF;
	FOR(i,1,n){
		while(cur<k&&c[cur+1].a<a[i].v){
			cur++;
			p=find(c[cur].b);
			if(p<=m)
				add(root,p,m,c[cur].c);
		}
		ans=max(ans,maxn[1]-a[i].c);
	}
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}