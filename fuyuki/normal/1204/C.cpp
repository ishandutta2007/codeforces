#include<cstdio>
#include<iostream>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
    rnt _s=0;re char _ch=gc;
    while(!isnum(_ch))_ch=gc;
    while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
    return _s;
}
const int N=2e2+1,M=1e6+1,tag[2]={N,1};
int n,m,a[M],dis[N][N];
char ch='-';
int ans,b[M];
I min(const int&x,const int&y){return x<y?x:y;}
int main(){
	n=getint();
	FOR(i,1,n){
		while(!isnum(ch))ch=gc;
		FOR(j,1,n)
			dis[i][j]=tag[ch-48],ch=gc;
	}
	FOR(i,1,n)dis[i][i]=0;
	FOR(k,1,n)FOR(i,1,n)FOR(j,1,n)
		dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	m=getint();FOR(i,1,m)a[i]=getint();
	b[++ans]=a[1];
	FOR(i,2,m-1)if(dis[b[ans]][a[i]]+dis[a[i]][a[i+1]]!=dis[b[ans]][a[i+1]])
		b[++ans]=a[i];b[++ans]=a[m];
	cout<<ans<<'\n';
	FOR(i,1,ans)cout<<b[i]<<' ';
	return 0;
}