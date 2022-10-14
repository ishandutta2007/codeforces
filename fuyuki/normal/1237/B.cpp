#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+100;
int n;
struct node{
	int x,y;
	V input(){x=getint(),y=getint();}
	B operator<(const node&u)const{
		return x<u.x;
	}
}a[N];
int ans;
V input(){
	n=getint();rnt x;
	FOR(i,1,n)x=getint(),a[x].x=i;
	FOR(i,1,n)x=getint(),a[x].y=i;
}
V init(){sort(a+1,a+1+n);}
I lowbit(const int&x){
	return x&-x;
}
int t[N];
V add(rnt x){while(x)t[x]++,x^=lowbit(x);}
I test(rnt x){
	while(x<=n)
		if(t[x])return 1;
		else x+=lowbit(x);
	return 0;
}
V work(){
	FOR(i,1,n)
		ans+=test(a[i].y),add(a[i].y);
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}