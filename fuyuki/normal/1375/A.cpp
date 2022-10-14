#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+1,sgn[2]={1,-1};
int T,n,a[N];
int main(){
	for(scanf("%d",&T);T--;){
    	n=getint();
    	FOR(i,1,n)a[i]=getint();
    	FOR(i,1,n)cout<<sgn[i&1]*a[i]<<" \n"[i==n];
	}
	return 0;
}