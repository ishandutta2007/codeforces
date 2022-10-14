#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
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
const int N=2e6+5;
int n,tot,rt;
char st[N];
V input(){scanf("%d%s",&n,st+1);}
struct ele{
	int ls,rs,minn,maxn,sum;
}t[N<<1];
#define lc t[p].ls
#define rc t[p].rs
#define lson lc,L,mid
#define rson rc,mid+1,R
V build(int&p,rnt L,rnt R){
	p=++tot;if(L==R)return;
	rnt mid=L+R>>1;
	build(lson),build(rson);
}
V init(){
	build(rt,1,n);
}
V update(rnt p){
	t[p].sum=t[lc].sum+t[rc].sum;
	t[p].minn=min(t[lc].minn,t[lc].sum+t[rc].minn);
	t[p].maxn=max(t[lc].maxn,t[lc].sum+t[rc].maxn);
}
V modify(rnt p,rnt L,rnt R,rnt x,rnt w){
	if(L==R){
		t[p].sum=t[p].minn=t[p].maxn=w;
		return;
	}
	rnt mid=L+R>>1;
	if(x<=mid)modify(lson,x,w);
	else modify(rson,x,w);
	update(p);
}
V work(){
	rnt cur=1;
	FOR(i,1,n){
		rnt x=0;
		if(st[i]=='L')
			cur=max(1,cur-1);
		else if(st[i]=='R')
			cur++;
		else{
			if(st[i]=='(')x=1;
			if(st[i]==')')x=-1;
			modify(rt,1,n,cur,x);
		}
		if(t[rt].minn<0||t[rt].sum)cout<<"-1 ";
		else cout<<t[rt].maxn<<" ";
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}