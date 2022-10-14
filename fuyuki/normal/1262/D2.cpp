#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e5+1;
int n,m,tot,rt;
int a[N],b[N],ans[N];
struct opt{
	int k,p,id;
	B operator<(const opt&u)const{
		return k<u.k;
	}
	V input(){k=getint(),p=getint();}
}q[N];
B cmp(const int&x,const int&y){
	return a[x]==a[y]?x<y:a[x]>a[y];
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	m=getint();
	FOR(i,1,m)q[i].input(),q[i].id=i;
}
struct ele{
	int ls,rs,siz;
}t[N<<1];
#define lc t[p].ls
#define rc t[p].rs
#define lson lc,L,mid
#define rson rc,mid+1,R
V build(int&p,rnt L,rnt R){
	p=++tot;
	if(L==R)return;
	rnt mid=L+R>>1;
	build(lson),build(rson);
}
V init(){
	FOR(i,1,n)b[i]=i;
	sort(b+1,b+1+n,cmp),sort(q+1,q+1+m);
	build(rt,1,n);
}
V add(rnt p,rnt L,rnt R,rnt x){
	t[p].siz++;
	if(L==R)return;
	rnt mid=L+R>>1;
	if(x<=mid)add(lson,x);
	else add(rson,x);
}
I ask(rnt p,rnt L,rnt R,rnt x){
	if(L==R)return L;
	rnt mid=L+R>>1;
	if(x<=t[lc].siz)return ask(lson,x);
	else return ask(rson,x-t[lc].siz);
}
V work(){
	rnt p=0;
	FOR(i,1,m){
		while(p<q[i].k)
			add(rt,1,n,b[++p]);
		ans[q[i].id]=a[ask(rt,1,n,q[i].p)];
	}
	FOR(i,1,m)cout<<ans[i]<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}