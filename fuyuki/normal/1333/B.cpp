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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=2e5+1;
int n,m,a[N],b[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)b[i]=getint();
}
V init(){
	int x=0,y=0;
	FOR(i,1,n){
		if(a[i]<b[i]&&!x)return void(cout<<"NO\n");
		if(a[i]>b[i]&&!y)return void(cout<<"NO\n");
		if(a[i]==1)x=1;
		if(a[i]==-1)y=1;
	}
	cout<<"YES\n";
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(int T=getint();T--;){
		input();
		init();
		work();
	}
	return 0;
}