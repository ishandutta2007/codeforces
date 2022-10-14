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
const int N=2e5+1,mod=998244353;
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
V check(int&x){x-=mod,x+=x>>31&mod;}
int T,n,m;
ll a[N],b[N];
int main(){
	n=getint();
	FOR(i,1,n)a[i]=getint(),b[i]=a[i];
	if(n==1){
		cout<<1<<' '<<1<<'\n';
		cout<<-a[1]<<'\n';
		cout<<1<<' '<<1<<'\n'<<0<<'\n';
		cout<<1<<' '<<1<<'\n'<<0<<'\n';
        return 0;
	}
	cout<<1<<' '<<n-1<<'\n';
	FOR(i,1,n-1)cout<<1ll*a[i]*(n-1)<<' ',b[i]+=1ll*a[i]*(n-1);
	cout<<'\n';
	cout<<1<<' '<<n<<'\n';
	FOR(i,1,n)cout<<-1ll*a[i]*n<<' ',b[i]-=1ll*a[i]*n;
	cout<<n<<' '<<n<<'\n';
	cout<<-b[n]<<'\n';
	return 0;
}