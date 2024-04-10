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
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define REP(u) for(rnt i=h[u],v;v=e[i].t,i;i=e[i].n)if(v!=fa)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+100;
int n,a[N],tag[N],cnt;
V input(){n=getint();FOR(i,1,n)a[i]=getint();}
V init(){
}
V work(){
	int flag=0;
	FOR(i,1,n){
		if(abs(a[i])%2==0)a[i]=a[i]/2;
		else{
			if(a[i]>0)tag[i]=1,cnt--;
			else tag[i]=-1,cnt++;
			a[i]=a[i]/2;
		}
	}
	cnt/=2;
	FOR(i,1,n)if(cnt<0&&tag[i]==1)a[i]++,cnt++;
	FOR(i,1,n)if(cnt>0&&tag[i]==-1)a[i]--,cnt--;
	FOR(i,1,n)cout<<a[i]<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	init();
	work();
	return 0;
}