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
const ll INF=(1ll<<55)-1;
ll a,s,x,y,z;
int n;
V input(){
	a=s=0,n=getint();
	while(n--)x=getint(),a^=x,s+=x;
}
V init(){
	x=INF^a;
	if(s&1)x|=1;
	else x^=(x&1);
}
V work(){
	y=z=(a^x)-((s+x)>>1);
//	cout<<(a^x^y^z)*2<<'\n';
//	cout<<(s+x+y+z)<<'\n';
	cout<<"3\n"<<x<<' '<<y<<' '<<z<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}