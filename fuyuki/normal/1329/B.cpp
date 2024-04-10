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
const int N=2e5+1;
int T,n,d,mod;
int main(){
	for(T=getint();T--;){
    	d=getint(),mod=getint();
    	int p=1,ans=1;d++;
    	while(p*2<=d)
    		ans=1ll*ans*(p+1)%mod,p<<=1;
    	ans=1ll*ans*(d-p+1)%mod;
    	ans=(ans+mod-1)%mod;
    	cout<<ans<<'\n';
	}
	return 0;
}