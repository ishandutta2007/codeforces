#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=5e2+1,sgn[2]={1,-1};
int T,n,m,a[N][N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)FOR(j,1,m)a[i][j]=getint();
}
I val(int x,int y){
	int p=x==1||x==n,q=y==1||y==m;
	if(p&&q)return 2;
	if(p||q)return 3;
	return 4;
}
V work(){
	FOR(i,1,n)FOR(j,1,m)
		if(a[i][j]>val(i,j))return void(cout<<"NO\n");
		else a[i][j]=val(i,j);
	cout<<"YES\n";
	FOR(i,1,n)FOR(j,1,m)cout<<a[i][j]<<" \n"[j==m];
}
int main(){
	for(scanf("%d",&T);T--;){
		input();
		work();
	}
	return 0;
}