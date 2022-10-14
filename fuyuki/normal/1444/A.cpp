#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e6+1;
ll p,tmp,poi;
int T,n,q;
V input(ll x=1){
	n=100000;
	scanf("%lld%d",&p,&q),tmp=poi=p;
	FOR(i,2,n)if(q%i==0){
		while(p%i==0&&q%i==0)p/=i,q/=i;
		if(q%i==0)return void(cout<<tmp<<'\n');
		else{
			x=1;
			while(p%i==0)x*=i,p/=i;
			if(poi/i>=x)
				poi=x*i;
		}
	}
	if(p%q!=0)return void(cout<<tmp<<'\n');
	else if(q!=1){
		x=1;
		while(p%q==0)x*=q,p/=q;
		if(poi>=x)poi=x;
	}
	cout<<tmp/poi<<'\n';
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