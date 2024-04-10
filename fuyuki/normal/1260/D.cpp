#include<vector>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define B inline bool
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
const int N=3e5+1;
int m,n,k,t;
int a[N],x[N],y[N],d[N],c[N];
V input(){
	m=getint(),n=getint(),k=getint(),t=getint();
	FOR(i,1,m)a[i]=getint();
	FOR(i,1,k)x[i]=getint(),y[i]=getint(),d[i]=getint();
}
V init(){sort(a+1,a+1+m);}
B check(rnt mid){
	rnt r=0,out=0;
	FOR(i,1,n)c[i]=0;
	FOR(i,1,k)if(d[i]>mid)
		c[x[i]]=max(c[x[i]],y[i]);
	FOR(i,1,n){
		if(c[i]>r)out+=c[i]-r<<1,r=c[i];
		r=max(r,i);
	}
	return out+n+1<=t;
}
V work(){
	rnt l=0,r=m,mid;
	while(mid=l+r>>1,l^r)
		if(check(a[m-mid]))
			l=mid+1;
		else r=mid;
	cout<<mid<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}