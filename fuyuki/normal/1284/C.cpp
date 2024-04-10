#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e6+1;
int n,mod,ans,fac[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
int main(){
	cin>>n>>mod,fac[0]=1;
	FOR(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	FOR(i,1,n)
		check(ans+=1ll*(n-i+1)*fac[n-i]%mod*fac[i]%mod*(n-i+1)%mod);
	cout<<ans;
	return 0;
}