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
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
template<class T>inl void ylmin(T &a,T b){a=a<b?a:b;}
template<class T>inl void ylmax(T &a,T b){a=a>b?a:b;}
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
const int MAXN = 1e6+10;
int T;
ll a,m,gcd;
/*int N,p,prime[MAXN],phi[MAXN],f[MAXN],s2[MAXN],inv;
bool mark[MAXN];
inl int sqr(int x){x%=p;return x*x%p;}
inl int g(int x){x%=p;return sqr((x*(1+x)>>1)%p);}
inl int pow(int a, int b, int p){
    int ans=1, t=a;
    for(;b;b>>=1,t=t*t%p)if(b&1)ans=ans*t%p;
    return ans;
}
inl void init(){
    phi[1]=1;
    for(int i=2;i<MAXN;i++){
        if(!mark[i])prime[++*prime]=i, phi[i]=i-1;
        for(int j=1;i*prime[j]<MAXN;j++){
            mark[i*prime[j]]=1;
            if(i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j]%p;break;}
            phi[i*prime[j]]=phi[i]*phi[prime[j]]%p;
        }
    }
    for(int i=1;i<MAXN;i++) phi[i]=(phi[i]+phi[i-1])%p;
}
inl ll get(int n,int x){
	phi[]
}*/
inl ll get(ll n,ll m){
	ll tmp=m;vector<ll> nmd;
	rep(i,2,sqrt(m)){
		if(m%i==0) {
			nmd.pb(i);
			while(m%i==0) m/=i; 
		}
	}
	if(m!=1) nmd.pb(m);
	m=tmp;
	ll ans=n;
	rep(s,1,(1<<size(nmd))-1){
		ll type=1,all=1;
		rep(i,0,size(nmd)-1) if(s&(1<<i)) all*=nmd[i],type*=-1;
		ans+=type*(n/all);
	}
	return ans;
}
int main(){
	for(read(T);T;T--){
		read(a),read(m);
		gcd=__gcd(a,m);
		a/=gcd,m/=gcd;
		printf("%lld\n",get(a+m-1,m)-get(a-1,m)); 
	}
	return 0;
}