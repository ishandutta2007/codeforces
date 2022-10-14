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
const int N=1e6+1,INF=0x3f3f3f3f;
int T,n,k,a[N];
ll ans,s[N],d[N],b[N];
V input(){
	n=getint(),k=getint();
	FOR(i,1,n)a[i]=getint();
	sort(a+1,a+1+n);
	FOR(i,1,n)s[i]=s[i-1]+a[i],d[i]=d[i-1]+1ll*a[i]*(i-1);
	ll sum=0;int x;
	ans=d[n];
	FOR(i,1,n){
		x=(i-1)/(k+1),sum+=1ll*x*a[i];
		ans=max(ans,sum+d[n]-d[i]-1ll*(i-x-1)*(s[n]-s[i]));
	}
	cout<<ans;
}
V init(){
	
}
V work(){
	
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