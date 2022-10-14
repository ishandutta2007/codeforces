#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<unordered_map>
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
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e4+1,INF=1e6;
int n,a[N],b[N];
int tot,ans[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint()+INF,b[i]=getint()+INF;
}
I val(rnt x){return (a[x]&1)<<1|(b[x]&1);}
B same(rnt x){FOR(i,2,n)if(val(i)!=x)return false;return true;}
B test(rnt x){FOR(i,2,n)if((val(i)&1)^x)return false;return true;}
V init(){while(same(val(1)))FOR(i,1,n)a[i]>>=1,b[i]>>=1;}
V work(){
	FOR(i,1,n)if(a[i]+b[i]&1)ans[++tot]=i;
	start:
	if(1<=tot&&tot<n){
		cout<<tot<<'\n';
		FOR(i,1,tot)cout<<ans[i]<<' ';
	}
	else{
		tot=0;
		FOR(i,1,n)if(val(i)<=1)ans[++tot]=i;
		goto start;
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}