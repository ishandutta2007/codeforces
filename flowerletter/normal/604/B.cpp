#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(r);i>=(l);i--)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mymax(a,b) ((a)<(b)?a=b,1:0)
#define mymin(a,b) ((a)>(b)?a=b,1:0)
#define lowbit(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 1e5+10;
int n,k,a[MAXN],Max;
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
inl bool check(int t){
	int x=n-k,y=2*k-n;
	int l=1,r=2*x;
	while(l<=r){
		if(a[l]+a[r]>t) return false;
		l++,r--;
	}return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	read(n),read(k);
	rep(i,1,n)read(a[i]);
	int l=a[n],r=a[n]+a[n-1],ans;
	while(l<=r){
		int Mid=l+r>>1;
		if(check(Mid)) ans=Mid,r=Mid-1;
		else l=Mid+1;
	}cout<<ans<<'\n'; 
	return 0;
}