#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=5e3+1;
int n,m,p=1,maxn=0;
int mp[N*N];
int a[N];
V input(){
	n=getint(),m=getint();
}
V init(){
	FOR(i,1,n){
		while(mp[p]>m)p++;
		m-=mp[p],a[i]=p++;
		FOR(j,1,i-1)mp[a[j]+a[i]]++;
	}
	if(m)return void(cout<<-1<<'\n');
	FOR(i,1,n)cout<<a[i]<<' ';
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	for(int T=getint();T--;){
		input();
		init();
		work();
//	}
	return 0;
}