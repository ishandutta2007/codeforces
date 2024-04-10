#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e5+1;
int a[N];
I check(rnt x){
	int a[10];
	FOR(i,0,9)a[i]=0;
	while(x)
		if(a[x%10])return 0;
		else a[x%10]=1,x/=10;
	return 1;
}
V input(){}
V work(){
	rnt l,r;
	l=getint(),r=getint();
	FOR(i,l,r)if(check(i))
		return void(cout<<i);
		cout<<"-1";
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}