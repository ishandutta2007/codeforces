#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1;
int T,n;
int main(){
	for(T=getint();T--;){
    	int a,b,x,y;
    	x=getint(),y=getint(),a=getint(),b=getint();
    	ll ans=0;
    	if(x>y)swap(x,y);
    	ans=1ll*(y-x)*a;
    	ans+=1ll*min(a*2,b)*min(x,y);
    	cout<<ans<<'\n';
	}
	return 0;
}