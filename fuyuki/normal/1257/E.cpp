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
const int N=2e5+2;
int n,m1,m2,m3,a[N],b[N],c[N],d[N];
V input(){
	m1=getint(),m2=getint(),m3=getint(),n=m1+m2+m3;
	while(m1--)a[getint()]++;
	while(m2--)b[getint()]++;
	while(m3--)c[getint()]++;
}
I min(const int&x,const int&y){return x<y?x:y;}
I max(const int&x,const int&y){return x>y?x:y;}
V init(){
	FOR(i,1,n)a[i]+=a[i-1],b[i]+=b[i-1],c[i]+=c[i-1];
	d[n]=b[n]-c[n];
	ROF(i,n-1,0)d[i]=max(d[i+1],b[i]-c[i]);
}
I ask(rnt x,rnt y){return n-(a[x]+b[y]-b[x]+c[n]-c[y]);}
V work(){
	rnt cur=0,ans=n,now;
	FOR(i,0,n)ans=min(ans,n-(a[i]-b[i]+c[n]+d[i])); 
	cout<<ans;
}
int main(){
	input();
	init();
	work();
	return 0;
}