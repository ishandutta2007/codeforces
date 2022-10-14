#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=3e5+2,sgn[2]={1,-1},INF=0x3f3f3f3f;
int T,n;
int a[N],nxt[N];
V input(){
	n=getint(),a[n+1]=0,nxt[n+1]=0;
	FOR(i,1,n)a[i]=getint();
}
V work(){
	ROF(i,n,1)nxt[i]=max(a[i],nxt[i+1]);
	FOR(i,1,n)
		if(a[i]<a[1]&&a[i]==nxt[i])
			return void(cout<<"NO\n");
	cout<<"YES\n";
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		work();
	}
	return 0;
}