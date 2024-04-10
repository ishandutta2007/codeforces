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
const int N=2e5+2,mod=998244353,INF=0x3f3f3f3f,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
I Pow(ll t,int x,ll s=1){
	for(;x;x>>=1,t=t*t%mod)if(x&1)s=s*t%mod;
	return s;
}
int T,n,ans,a[N];
ll cnt;
V input(){
	n=getint(),ans=0,cnt=0;
	FOR(i,1,n)a[i]=getint();
}
V init(){
	
}
V dfs(int x){
	static char st[100];
	static ll sc,sp;
	static int lc,lp,c[100],p[100];
	if(x==n+1)return cnt++,void(ans+=sc<sp);
	if(lc<=1||c[lc]-c[lc-1]<=x-c[lc])c[++lc]=x,sc+=a[x],st[x]='C',dfs(x+1),c[lc--]=0,sc-=a[x];
	if(lp<=1||p[lp]-p[lp-1]>=x-p[lp])p[++lp]=x,sp+=a[x],st[x]='P',dfs(x+1),p[lp--]=0,sp-=a[x];
}
V force(){
	dfs(1),cout<<ans<<'\n';
	cerr<<cnt<<'\n';
}
vector<ll>c,d;
V once(ll lim,int l,int r){
	c.clear(),d.clear(),c.push_back(0ll);
	if(l)d.push_back(0ll);
	ll s1=0,s2=0;
	FOR(i,2,n-1)
		if(i&1)s1+=a[i],c.push_back(s1);
		else   s2+=a[i],d.push_back(s2);
	if(r)(n-1&1?c:d).pop_back();
	for(ll x:c)check(ans+=upper_bound(d.begin(),d.end(),lim-x)-d.begin());
	cnt+=1ll*c.size()*d.size();
//	cout<<"PC"[l]<<' '<<"PC"[r]<<' '<<c.size()<<' '<<d.size()<<' '<<1ll*c.size()*d.size()<<'\n';
}
V work(){
	if(n<=10)return force();
	ll sum=0,now=0;
	FOR(i,1,n)sum+=a[i];
	sum=sum-1>>1;
	ROF(i,n,0)ans+=now<=sum,now+=a[i],cnt++;
	once(sum,0,0);
	once(sum-a[1],1,0);
	once(sum-a[n],0,1);
	once(sum-a[1]-a[n],1,1);
	cout<<ans<<' ';
//	cout<<cnt<<'\n';
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
	}
	return 0;
}