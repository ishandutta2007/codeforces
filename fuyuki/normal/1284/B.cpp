#include<cstdio>
#include<iostream>
#include<algorithm>
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
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=2e6+1,INF=0x7fffffff;
int n,m;
ll ans;
int maxn[N],minn[N],tag[N],cnt[N];
int main(){
	n=getint();
	FOR(i,1,n){
		minn[i]=INF;rnt x;
		m=getint();
		while(m--){
			x=getint()+1;
			if(x>minn[i])tag[i]=1;
			maxn[i]=max(maxn[i],x);
			minn[i]=min(minn[i],x);
		}
	}
	FOR(i,1,n)if(!tag[i])cnt[maxn[i]]++;
	FOR(i,1,N-1)cnt[i]+=cnt[i-1];
	FOR(i,1,n)if(!tag[i])ans+=cnt[minn[i]];
	cout<<1ll*n*n-ans;
	return 0;
}