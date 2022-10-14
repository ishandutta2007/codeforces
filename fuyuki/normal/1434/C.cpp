#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define P pair<int,int>
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,INF=0x3f3f3f3f;
int T;
ll a,b,c,d,t;
V input(){
	a=getint(),b=getint(),c=getint(),d=getint();
	if(a>b*c)return void(cout<<"-1\n");
	t=a/b/d,cout<<(t+1)*a-t*(t+1)/2*d*b<<'\n';
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}