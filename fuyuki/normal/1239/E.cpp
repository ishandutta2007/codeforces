#include<set>
#include<bitset>
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
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=(_ch=='-')?-1:1,_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
const int N=26,M=2e6;
multiset<int>mp;
int n,m,sum,ans,a[N<<1],b[N];
bitset<M>f[N<<1][N];
V input(){
	n=getint(),m=n<<1;
	FOR(i,1,m)a[i]=getint(),sum+=a[i];
}
V init(){
	sort(a+1,a+1+m,greater<int>()),f[0][0][0]=1;
}
V work(){
	FOR(i,1,m-2)FOR(j,0,n-1){
		f[i][j]|=f[i-1][j];
		if(j)f[i][j]|=f[i-1][j-1]<<a[i];
	}
}
V output(){
	rnt x,y,tot=n;ans=M,sum-=a[m]+a[m-1];
	FOR(i,1,m-2)FOR(j,1,sum)
		if(f[i][n-1][j]&&max(sum-j,j)<ans)
			ans=max(sum-j,j),x=i,y=j;
	b[tot--]=a[m],mp.insert(a[m]);
	ROF(i,x,1)if(y>=a[i]&&f[i-1][tot-1][y-a[i]])
		b[tot--]=a[i],mp.insert(a[i]),y-=a[i];
	cerr<<ans+a[m]+a[m-1]<<'\n';
	x=1;
	ROF(i,n,1)cout<<b[i]<<" \n"[i==1];
	FOR(i,1,n){
		while(mp.count(a[x])>0)
			mp.erase(mp.find(a[x++]));
		cout<<a[x++]<<' ';
	}
}
int main(){
	input();
	init();
	work();
	output();
	return 0;
}