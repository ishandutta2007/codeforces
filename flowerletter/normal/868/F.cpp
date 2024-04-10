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
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define travel(i,u) for(auto i:u)
#define Travel(i,u) for(auto &i:u)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define mymax(a,b) ((a)<(b)?(a)=(b),1:0)
#define mymin(a,b) ((a)>(b)?(a)=(b),1:0)
#define lowbit(x) ((x)&(-(x)))
#define MOD(x) (x>=Mod?x-Mod:x)
#define lson root<<1
#define rson root<<1|1
#define mst0(x) memset(x,0,sizeof(x))
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
const int MAXN = 1e5+10;
int n,k,a[MAXN],cnt[MAXN],l=1,r;
ll dp[21][MAXN],ans;
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
inl void update(int x,int k){ans+=1ll*k*cnt[x]*(cnt[x]-1)/2;}
inl ll Query(int L,int R){
	while(l<L) update(a[l],-1),cnt[a[l]]--,update(a[l],1),l++;
	while(l>L) l--,update(a[l],-1),cnt[a[l]]++,update(a[l],1);
	while(r<R) r++,update(a[r],-1),cnt[a[r]]++,update(a[r],1);
	while(r>R) update(a[r],-1),cnt[a[r]]--,update(a[r],1),r--;
	return ans;
}
inl void Solve(int l,int r,int L,int R,int dep){
	if(l>r) return ;
	int mid=l+r>>1,Pos=L;
	rep(i,L,min(mid,R)) if(mymin(dp[dep][mid],dp[dep-1][i-1]+Query(i,mid))) Pos=i;
	Solve(l,mid-1,L,Pos,dep),Solve(mid+1,r,Pos,R,dep); 
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(k),memset(dp,0x3f,sizeof(dp));dp[0][0]=0;
	rep(i,1,n)read(a[i]);
	rep(i,1,k)Solve(1,n,1,n,i);
	printf("%lld\n",dp[k][n]);
	return 0;
}