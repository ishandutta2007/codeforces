#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define cl(x) memset(x,0,l<<2)
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(rnt i(A);i<=B;i++)
#define ROF(i,A,B) for(rnt i(A);i>=B;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=1<<20|1,mod=998244353,G=3,inv3=332748118,inv2=499122177,lim=5e4;
I getint() {
	rnt _s=0;
	re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
int T,n,a[N],b[N],t[N];
V input(){
	n=getint();
	re char ch=gc;
	while(!isnum(ch))ch=gc;
	FOR(i,1,n)a[i]=b[i]=ch-'0',ch=gc;
}
V work(){
	sort(b+1,b+1+n);
	rnt tot=1;
	FOR(i,1,n)if(a[i]==b[tot])tot++,t[i]=1;
	FOR(i,1,n)if(a[i]==b[tot]&&t[i]!=1)tot++,t[i]=2;
	if(tot<=n)cout<<"-";
	else FOR(i,1,n)cout<<t[i];
	cout<<"\n";FOR(i,1,n)t[i]=0;
}
int main(){
//	freopen("test.in","r",stdin);
	T=getint();
	while(T--)input(),work();
	return 0;
}