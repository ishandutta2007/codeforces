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
#define int long long 
const int MAXN = 2e5+10;
struct Node{
    int id,l,r;
	friend bool operator < (const Node &a,const Node &b){
		return a.r>b.r;
	}
}a[MAXN];
priority_queue<Node> Q;
int n,ans,start,id[MAXN];
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
signed main(){
	//freopen("road2.in","r",stdin);
	//freopen("road.out","w",stdout);
	read(n),start=clock();a[0].r=a[n+1].r=1e9+7;
	for(int i=1;i<=n;i++)read(a[i].l),read(a[i].r),a[i].r+=a[i].l,a[i].id=i,id[i]=i;
	for(int i=1;i<=n;i++)a[i].r=min(a[i].r,min(a[i-1].r,a[i+1].r)+1);
	while(((double)clock()-(double)start)/CLOCKS_PER_SEC<=2.9){
		random_shuffle(id+1,id+n+1);
		for(int i=1;i<=n;i++)a[id[i]].r=min(a[id[i]].r,min(a[id[i]-1].r,a[id[i]+1].r)+1);
	}
	for(int i=n;i>=1;i--)a[i].r=min(a[i].r,min(a[i-1].r,a[i+1].r)+1);
	for(int i=1;i<=n;i++)if(a[i].l>a[i].r)puts("-1"),exit(0);else ans+=a[i].r-a[i].l;
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++)printf("%d ",a[i].r);
	return 0;
}