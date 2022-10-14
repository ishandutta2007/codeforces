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
	static const int flag[2]={1,-1};
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
//int T,n,m,a[N];
int T,n,k,a[301][301],r[301],c[301];
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V input(){
	cin>>n>>k;
	FOR(i,1,n)FOR(j,1,n)a[i][j]=0;
	FOR(i,1,n)r[i]=c[i]=0;
	int x=1,y=1,ans=0;
	while(k--){
		a[x][y]=1,r[x]++,c[y]++;
		x++,y++;
		if(x>n)
			x=1,y++;
		if(y>n)
			y=(y-1)%n+1;
	}
	x=mod,y=0;
	FOR(i,1,n)cmax(y,c[i]),cmin(x,c[i]);
	ans+=(x-y)*(x-y);
	x=mod,y=0;
	FOR(i,1,n)cmax(y,r[i]),cmin(x,r[i]);
	ans+=(x-y)*(x-y);
	cout<<ans<<'\n';
	FOR(i,1,n){
		FOR(j,1,n)cout<<a[i][j];
		cout<<'\n';
	}
}
V init(){
	
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
	for(cin.tie(0),cin>>T;T--;){
		input();
		init();
		work();
	}
	return 0;
}