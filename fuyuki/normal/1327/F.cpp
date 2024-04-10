#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
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
I min(const int&x,const int&y){return(x-y>>31)?x:y;}
I max(const int&x,const int&y){return(y-x>>31)?x:y;}
const int N=5e5+2,mod=998244353;
int n,m,k,ans=1;
int l[N],r[N],a[N],f[N],lim[N],d[N];
V check(int&x){x-=mod,x+=x>>31&mod;}
V input(){
	n=getint(),k=getint(),m=getint();
	FOR(i,1,m)l[i]=getint(),r[i]=getint(),a[i]=getint();
}
V init(){
	
}
V test(int p){
	int cur=0,sum=0;
	FOR(i,0,n+1)lim[i]=0,d[i]=0,f[i]=0;
	FOR(i,1,m)
		if(a[i]>>p&1)d[l[i]]++,d[r[i]+1]--;
		else lim[r[i]]=max(lim[r[i]],l[i]);
	f[0]=1,sum=1;
	FOR(i,1,n){
		if(!(d[i]+=d[i-1]))
			f[i]=sum,check(sum<<=1);
		while(cur<lim[i])
			check(sum+=mod-f[cur++]);
	}
//	if(cur==0)check(--sum);
	ans=1ll*ans*sum%mod;
}
V work(){
	FOR(i,0,k-1)
		test(i);
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	input();
	init();
	work();
	return 0;
}