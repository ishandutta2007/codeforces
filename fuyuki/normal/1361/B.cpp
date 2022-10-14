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
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e6+1,mod=1e9+7;
int T,n,p,ans,a[N],f[N];
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){
	n=getint(),p=getint(),ans=0;
	FOR(i,1,n)a[i]=getint();
	sort(a+1,a+1+n);
}
V init(){
	if(p==1)return void(cout<<n%2<<'\n');
	int now=0,cnt=0,need=0;
	FOR(i,1,n){
		while(a[i]>now&&cnt>0)now++,cnt/=p;
		now=a[i],f[i]=++cnt;
	}
	now=a[n],cnt=0,need=0;
	ROF(i,n,1){
		if(need||cnt){
			while(now>a[i]&&cnt<N)
				now--,need*=p,cnt=min(1ll*N,1ll*cnt*p);
		}
		now=a[i];
		if(cnt+need<=f[i])
			need+=cnt,cnt=0;
		if(need)need--,check(ans+=mod-Pow(p,now));
		else{
			if(cnt>0)cnt--,check(ans+=mod-Pow(p,now));
			else cnt++,check(ans+=Pow(p,now));
		}
	}
	cout<<ans<<'\n';
}
V work(){
	
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(T=getint();T--;){
		input();
		init();
		work();
	}
	return 0;
}