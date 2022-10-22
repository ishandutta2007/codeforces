/*mjytxdy!*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define size(x) ((int)x.size())
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define trv(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl bool ylmin(T &a,T b){return a<b?0:(a=b,1);}
template<class T>inl bool ylmax(T &a,T b){return a>b?0:(a=b,1);}
template<class T>inl T abs(T x){return x<0?-x:x;}
inl char read(){
	static const int IO_LEN=1024*1024;
	static char buf[IO_LEN],*ioh,*iot;
	if(ioh==iot){
		iot=(ioh=buf)+fread(buf,1,IO_LEN,stdin);
		if(ioh==iot) return -1;
	}
	return *ioh++;
}
template<class T>inl void read(T &x){
	static int iosig;static char ioc;
	for(iosig=0,ioc=read();!isdigit(ioc);ioc=read()) if(ioc=='-') iosig=1;
	for(x=0;isdigit(ioc);ioc=read())x=(x<<1)+(x<<3)+(ioc^'0');
	if(iosig) x=-x;
}
int T,n,ansk;
string s,ans,pre[5010],sub[5010],rev[5010];
inl string qwq(string a){
	int n=size(a);string b;
	per(i,n-1,0) b+=a[i]; 
	return b;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);ans="";s="";sub[n+1]="";cin>>s;
		rep(i,1,n) pre[i]=pre[i-1]+s[i-1];
		per(i,n,1) sub[i]=s[i-1]+sub[i+1];
		for(int i=1;i<=n;i++){
			string now=sub[i]+(((n-i+1)&1)?qwq(pre[i-1]):pre[i-1]);
			if(ans=="" || ans>now) ans=now,ansk=i;
		}
		cout<<ans<<'\n'<<ansk<<'\n';
	}
	return 0;
}