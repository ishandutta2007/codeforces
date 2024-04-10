#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define LL inline ll
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
LL getint(){
	re ll _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e5+100;
int n,A,B,X,Y;
ll k;
int a[N],b[N];
bool cmp(const int&x,const int&y){return x>y;}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint()/100;
	X=getint(),A=getint();
	Y=getint(),B=getint();
	k=getint();
}
LL sum(rnt x){
	FOR(i,1,x)b[i]=0;
	FOR(i,1,x/A)b[i*A]+=X;
	FOR(i,1,x/B)b[i*B]+=Y;
	sort(b+1,b+1+x,cmp);
	ll out=0;
	FOR(i,1,x)out+=1ll*a[i]*b[i];
//	cout<<out<<'\n';
	return out;
}
V work(){
	sort(a+1,a+1+n,cmp);
	if(sum(n)<k)return void(cout<<"-1\n");
	rnt l=1,r=n,mid;
	while(mid=l+r>>1,l^r)
		if(sum(mid)>=k)r=mid;
		else l=mid+1;
	cout<<mid<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	int T;T=getint();
	while(T--){
		input();
		work();
	}
	return 0;
}