#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
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
const int N=3e2+1,mod=1e9+7;
V input(){
	
}
V init(){
	
}
V work(){
	
}
int a[N][N];
int main(){
//	freopen("test.in","r",stdin);
	rnt n,m,tot=0;
	n=getint();
	FOR(i,1,n)
		if(i&1)FOR(j,1,n)a[j][i]=++tot;
		else ROF(j,n,1)a[j][i]=++tot;
	FOR(i,1,n)FOR(j,1,n)cout<<a[i][j]<<" \n"[j==n];
	return 0;
}