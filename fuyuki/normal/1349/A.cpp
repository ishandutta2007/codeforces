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
const int N=2e5+1,INF=0x3f3f3f3f;
int T,n,a[N][2],c[N];
ll Pow(ll t,int x){
	ll s=1;
	for(;x;x>>=1,t=t*t)if(x&1)s=s*t;
	return s;
}
int main(){
	n=getint();
	FOR(i,1,N-1)a[i][0]=a[i][1]=INF;
	FOR(i,1,n){
		int x=getint(),y=sqrt(x),cnt;
		FOR(j,2,y)if(x%j==0){
			for(cnt=0;x%j==0;x/=j)cnt++;
			if(cnt<a[j][0])a[j][1]=a[j][0],a[j][0]=cnt;
			else if(cnt<a[j][1])a[j][1]=cnt;
			c[j]++;
		}
		if(x!=1){
			if(1<a[x][0])a[x][1]=a[x][0],a[x][0]=1;
			else if(1<a[x][1])a[x][1]=1;
			c[x]++;
		}
	}
	ll ans=1;
	int x=0;
	FOR(i,1,N-1)if(c[i]==n)ans*=Pow(i,a[i][1]),x=0;
	else if(c[i]==n-1)ans*=Pow(i,a[i][0]);
	cout<<ans;
	return 0;
}