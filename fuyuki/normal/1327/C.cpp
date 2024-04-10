#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=2e5+1;
int n,m;
V input(){
	n=getint(),m=getint();
}
V init(){
	cout<<n+m-2+n*(m-1)+n-1<<'\n';
	FOR(i,1,m-1)cout<<'L';
	FOR(i,1,n-1)cout<<'U';
}
V work(){
	FOR(i,1,n){
		FOR(j,1,m-1)
			if(i&1)cout<<'R';
			else cout<<'L';
		if(i!=n)cout<<'D';
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
		input();
		init();
		work();
	return 0;
}