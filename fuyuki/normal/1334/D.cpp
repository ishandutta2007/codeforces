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
ll getint(){
	ll _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=3e5+1;
int T,n,k,p;//,a[N];
ll l,r,S,sum;
V input(){
	n=getint(),l=getint(),r=getint();
	p=1,k=n+n-2,sum=0;
	S=1ll*(n-1)*n;
}
I f(ll x){
	if(x==S+1)return 1;
	while(x>sum+k)
		sum+=k,k-=2,p++;
	x-=sum;
	if(x%2==1)return p;
	else return p+x/2;
}
V work(){
	while(l<=r)
		cout<<f(l++)<<' ';
	cout<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(T=getint();T--;){
		input();
		work();
	}
	return 0;
}