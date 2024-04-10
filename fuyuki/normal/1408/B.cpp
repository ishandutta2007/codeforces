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
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
I gcd(int x,int y){return!y?x:gcd(y,x);}
const int N=1e6+1,mod=998244353;
int T,n,m,k,ans,a[N],b[N];
V input(){
	n=getint(),k=getint(),ans=m=0,a[0]=-1;
	FOR(i,1,n)a[i]=getint();
	FOR(i,1,n)if(a[i]!=a[i-1])b[++m]=a[i];
	if(k==1){
		if(m==1)return void(cout<<1<<'\n');
		return void(cout<<"-1\n");
	}
	cout<<max(1,(m-1+k-2)/(k-1))<<'\n';
}
V init(){
	
}
V work(){
	
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}