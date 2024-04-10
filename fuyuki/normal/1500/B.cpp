#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define ld long double
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
const int N=1e6+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
ll gcd(ll x,ll y){return!y?x:gcd(y,x%y);}
V exgcd(ll a,ll b,ll&x,ll&y){
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
ll mul(ll x,ll y,ll p){return(x*y-(ll)((ld)x/p*y)*p+p)%p;}
V merge(ll&a,ll&p,ll b,ll q){
	ll x,y,w=b-a,d=gcd(p,q);
	if(w%d)a=p=-2;
	else{
		exgcd(p,q,x,y),a+=p*mul(w/d,x,q/d),p=p/d*q,a=(a%p+p)%p;
	}
}
ll k,w[N];
int n,m,len;
int a[N],b[N],ida[N],idb[N];
V input(){
	cin>>n>>m>>k,len=2*max(n,m);
	FOR(i,1,n)a[i]=getint(),ida[a[i]]=i;
	FOR(i,1,m)b[i]=getint(),idb[b[i]]=i;
}
V init(){
	ll a,p,b,q;
	FOR(i,1,len)if(ida[i]&&idb[i]){
		a=ida[i]-1,b=idb[i]-1,p=n,q=m;
		merge(a,p,b,q),w[i]=a+1;
	}
	else w[i]=-1;
}
ll check(ll x){
	ll out=x,tot=1ll*n*m/gcd(n,m);
	FOR(i,1,len)if(~w[i])
		out-=(x-1)/tot+(w[i]<=(x-1)%tot+1);
	return out;
}
V work(){
	ll l=1,r=1e18,mid;
	while(mid=l+r>>1,l^r)
		if(check(mid)>=k)r=mid;
		else l=mid+1;
	cout<<mid;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
////	}
	return 0;
}