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
const int N=2e2;
const char mp[N]=" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
int T,n,m,k,sum;
char a[N][N];
int cnt[N];
V input(){
	FOR(i,1,n)FOR(j,1,m)a[i][j]='\000';
	scanf("%d%d%d",&n,&m,&k),sum=0;
	FOR(i,1,n)scanf("%s",a[i]+1);
	FOR(i,1,n)FOR(j,1,m)if(a[i][j]=='R')sum++;
}
V init(){
	FOR(i,1,k)cnt[i]=sum/k;
	FOR(i,1,sum%k)cnt[i]++;
}
V work(){
	rnt x=1,y=1,dx=1;
	FOR(i,1,k)
		while(cnt[i]--){
			while(a[x][y]=='.'){
				a[x][y]=mp[i],x+=dx;
				if(x==0)x=1,dx=1,y++;
				if(x==n+1)x=n,dx=-1,y++;
			}
			a[x][y]=mp[i],x+=dx;
			if(x==0)x=1,dx=1,y++;
			if(x==n+1)x=n,dx=-1,y++;
		}
	while(y<=m){
		a[x][y]=mp[k],x+=dx;
		if(x==0)x=1,dx=1,y++;
		if(x==n+1)x=n,dx=-1,y++;
	}
	FOR(i,1,n)cout<<a[i]+1<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&T);
	while(T--){
		input();
		init();
		work();
	}
	return 0;
}