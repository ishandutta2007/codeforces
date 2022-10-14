#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define cl(x) memset(x,0,l<<2)
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,A,B) for(rnt i(A);i<=B;i++)
#define ROF(i,A,B) for(rnt i(A);i>=B;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
const int N=1e3+1;
I getint() {
	rnt _s=0;
	re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
int T,n,m,ans;
int a[5][N];
int f[N][16];
V input(){
	n=getint(),m=getint();
	memset(f,0,sizeof(f));
	FOR(i,1,n)FOR(j,1,m)a[i][j]=getint();
}
V work(){
	rnt s=1<<n;s--;
	FOR(i,1,m)FOR(j,0,s)FOR(k,0,n-1){
			rnt up=0;
			FOR(p,1,n)if((1<<p-1)&j)up+=a[(p+k-1)%n+1][i];
			FOR(l,0,s)if(!(l&j))f[i][l|j]=max(f[i-1][l]+up,f[i][l|j]);
		}
	cout<<f[m][s]<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	T=getint();
	while(T--)input(),work();
	return 0;
}