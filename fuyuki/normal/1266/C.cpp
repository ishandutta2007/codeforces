#include<cstdio>
#include<cstring>
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
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=2e3;
int n,m,tot,a[N][N],b[N],tag[N];
V input(){cin>>n>>m;}
I gcd(rnt x,rnt y){return !y?x:gcd(y,x%y);}
I lcm(rnt x,rnt y){return x*y/gcd(x,y);}
V init(){
	if(n==1&&m==1)return;
	if(n==1){
		FOR(i,1,m)a[1][i]=i+1;
		return;
	}
	if(m==1){
		FOR(i,1,n)a[i][1]=i+1;
		return;
	}
	tot=1;
	if(n<m){
		FOR(i,1,n)a[i][1]=i*2,tag[i*2]=1;
		FOR(i,2,m){
			while(tag[++tot]);
			a[1][i]=tot;
		}
	}
	else{
		FOR(i,1,m)
			a[1][i]=i*2,tag[i*2]=1;
		FOR(i,2,n){
			while(tag[++tot]);
			a[i][1]=tot;
		}
		
	}
	FOR(i,2,n)FOR(j,2,m)
		a[i][j]=lcm(a[i][1],a[1][j]);
}
V work(){
	FOR(i,1,n)FOR(j,1,m)
		cout<<a[i][j]<<" \n"[j==m];
}
int main(){
	input();
	init();
	work();
	return 0;
}