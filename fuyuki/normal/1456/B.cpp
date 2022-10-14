#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,INF=0x3f3f3f3f;
int T,n,ans,a[N],s[N];
V input(){
	n=getint(),ans=INF;
	FOR(i,1,n)a[i]=getint(),s[i]=s[i-1]^a[i];
}
V init(){
	FOR(i,3,n)
		if((a[i]^a[i+1])<a[i-1])
			cout<<1,exit(0);
}
V work(){
	FOR(i,1,n)FOR(j,i,n)FOR(k,j+1,n)FOR(p,k,n)
		if((s[j]^s[i-1])>(s[p]^s[k-1]))
			ans=min(ans,j-i+p-k);
	if(ans==INF)cout<<-1;
	else cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}