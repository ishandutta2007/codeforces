#include<map>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    rnt _s=0;re char _ch=gc;
    while(!isnum(_ch))_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s;
}
map<int,int>mp;
int n,k,mod;
long long ans;
int main(){
	n=getint(),mod=getint(),k=getint();
	while(n--){
		rnt x=getint(),y;
		y=1ll*x*x%mod;
		y=1ll*y*y%mod;
		y-=1ll*k*x%mod;
		y+=mod,y%=mod;
		if(mp.find(y)==mp.end())mp[y]=0;
		ans+=mp[y]++;
	}
	cout<<ans;
}