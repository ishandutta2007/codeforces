#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(int deg=10){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*deg+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e3+50;
const int num[]={119,18,93,91,58,107,111,82,127,123};
int T,n,m;
int a[N],f[N][N];
I cnt(int x){return __builtin_popcount(x);}
V input(){
	n=getint(),m=getint(),f[n+1][m]=1;
	FOR(i,1,n)a[i]=getint(2);
}
V init(){
	ROF(i,n,1)FOR(j,0,m)FOR(k,0,9)if((a[i]&num[k])==a[i])
		f[i][j]|=f[i+1][j+cnt(a[i]^num[k])];
}
V work(){
	int x=0;
	if(!f[1][0])return void(cout<<"-1");
	FOR(i,1,n)ROF(j,9,0)if((a[i]&num[j])==a[i]&&f[i+1][x+cnt(a[i]^num[j])]){
		cout<<j,x+=cnt(a[i]^num[j]);break;
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}