#include<cstdio>
#include<iostream>
#include<algorithm>
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(re int i=A;i<=B;i++)
#define ROF(i,A,B) for(re int i=A;i>=B;i--)
using namespace std;
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	const int flag[2]={1,-1};
	rnt _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=2e5+1;
int n,ans,a[N],dis[N];
V input(){
	re char ch=gc;
	while(!isnum(ch))ch=gc;
	while(isnum(ch))a[++n]=ch-'0',ch=gc;
}
V init(){FOR(i,1,n)dis[i]=a[i]?0:dis[i-1]+1;}
V work(){
	FOR(i,1,n){
		rnt now=0,cur=i,len=0;
		while(cur&&cur>i-20)
			now|=a[cur--]<<len++,ans+=now==i-cur;
		ans+=len+1<=now&&now<=len+dis[cur];
	}
	cout<<ans<<'\n';
}
V clean(){n=ans=0;}
int main(){
//	freopen("test.in","r",stdin);
	int T;
	T=getint();
	while(T--){
		input();
		init();
		work();
		clean();
	}
	return 0;
}