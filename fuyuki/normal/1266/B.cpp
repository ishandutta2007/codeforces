#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
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
const int N=1e5+1;
V input(){
	
}
V init(){
	
}
V work(){
	int n;ll x;
	cin>>n;
	while(n--){
		cin>>x;
		if(x<15){
			cout<<"NO\n";
			continue;
		}
		x=x%14+14;
		if(15<=x&&x<=20)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}