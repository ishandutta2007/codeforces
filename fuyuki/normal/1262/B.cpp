#include<queue>
#include<cstdio>
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
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e5+1;
int n,a[N],b[N];
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
priority_queue<int>q;
V init(){while(!q.empty())q.pop();}
V work(){
	rnt cur=0;
	FOR(i,1,n){
		while(cur<a[i])q.push(++cur);
		if(q.empty())return void(cout<<"-1\n");
		b[i]=q.top(),q.pop();
	}
	FOR(i,1,n)cout<<b[i]<<" \n"[i==n];
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