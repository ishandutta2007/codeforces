#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define lson root<<1
#define rson root<<1|1
#define lowbit(x) (x&-x)
const int MAXN = 2e5+10;
ll n,s[MAXN],c[MAXN],Ans[MAXN];
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
inl void Update(ll x,ll k){
	for(int i=x;i<=n;i+=lowbit(i))c[i]+=k;
}
inl ll Query(ll x,ll ans=0){
	for(int i=x;i;i-=lowbit(i))ans+=c[i];
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	for(int i=1;i<=n;i++) read(s[i]),Update(i,i);
	for(int i=n;i>=1;i--){
		int l=0,r=n,ans;
		while(l<=r){
			ll Mid=l+r>>1,sum=Query(Mid);
			if(sum==s[i]) ans=Mid+1;
			if(sum>s[i])r=Mid-1;
			else l=Mid+1;
		}Update(ans,-ans);
		Ans[i]=ans;
	}
	for(int i=1;i<=n;i++) printf("%d ",Ans[i]);
	return 0;
}