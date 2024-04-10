#include<cstdio>
#include<cstdlib>
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
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=2e5+1;
char st[N];
int n,tot,m,ans[N],id[N];
V input(){
	n=tot=m=0;
	re char ch=gc;
	while(ch<'a')ch=gc;
	while(ch>='a'){
		st[++n]=ch,id[n]=++tot;
		if(n>=5&&st[n-4]=='t'&&st[n-3]=='w'&&st[n-2]=='o'&&st[n-1]=='n'&&st[n]=='e')
			ans[++m]=id[n-2],st[n-2]='n',st[n-1]='e',n--;
		ch=gc;
	}
}
V init(){
	FOR(i,2,n-1)if(st[i-1]=='t'&&st[i]=='w'&&st[i+1]=='o')
		ans[++m]=id[i],st[i]='z';
	FOR(i,2,n-1)if(st[i-1]=='o'&&st[i]=='n'&&st[i+1]=='e')
		ans[++m]=id[i],st[i]='z';
	sort(ans+1,ans+1+m);
	cout<<m<<'\n';
	FOR(i,1,m)cout<<ans[i]<<' ';
	cout<<'\n';
}
V work(){
	
}
int main(){
	int T;T=getint();
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}