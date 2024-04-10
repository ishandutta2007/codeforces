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
const int N=1e5+2,mod=1e9+7,INF=0x3f3f3f3f;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(ll&x,ll y){if(y-x>>63)x=y;}
int n,m,k;
char s[N],t[N];
int Ss[N],St[N],inv[N],pw[N],f[N][31];
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
V input(){
	scanf("%d%s%d%s%d",&n,s+1,&m,t+1,&k);
}
I ask(int*p,int l,int r){
	return 1ll*inv[l-1]*(p[r]-p[l-1]+mod)%mod;
}
I lcp(int p1,int p2){
	if(s[p1]!=t[p2])return 0;
	int l=1,r=min(m-p2,n-p1)+1,mid;
	while(mid=l+r>>1,l^r)
		if(ask(Ss,p1,p1+mid)==ask(St,p2,p2+mid))
			l=mid+1;
		else r=mid;
	return mid;
}
V init(){
	pw[0]=inv[0]=1;
	FOR(i,1,n)pw[i]=1ll*pw[i-1]*233%mod,inv[i]=Pow(pw[i],mod-2);
	FOR(i,1,n)Ss[i]=(1ll*s[i]*pw[i]+Ss[i-1])%mod;
	FOR(i,1,m)St[i]=(1ll*t[i]*pw[i]+St[i-1])%mod;
}
V work(){
	int len=0;
	FOR(i,1,n)FOR(j,1,k){
		len=lcp(i,f[i][j-1]+1);
		cmax(f[i+len][j],f[i][j-1]+len);
		if(f[i][j-1]+len==m)
			return void(cout<<"YES");
		cmax(f[i][j],f[i-1][j]);
	}
	cout<<"NO";
//	if(f[n+1][k]==m)cout<<"YES";
//	else cout<<"NO";
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}