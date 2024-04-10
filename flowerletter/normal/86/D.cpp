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
#define travel(i,u) for(int i=head[u];i;i=e[i].next)
#define lb(x) ((x)&(-(x)))
#define lson root<<1
#define rson root<<1|1
#define Mid (l+r>>1)
#define debug(x) cout<<#x":"<<x<<'\n'
#define myput puts("QaQ")
#define file(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
typedef long long ll;
const int MAXN = 2e5+10;
const int MAXA = 1e6+10;
const int block = 700;
struct Que{int l,r,id;}Q[MAXN];
int n,q,l=1,r,a[MAXN],cnt[MAXA];ll now,ans[MAXN]; 
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
inl bool cmp(Que a,Que b){return a.r/block==b.r/block?a.l<b.l:a.r<b.r;}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(q);
	rep(i,1,n) read(a[i]);
	rep(i,1,q) read(Q[i].l),read(Q[i].r),Q[i].id=i;
	sort(Q+1,Q+q+1,cmp);
	rep(i,1,q){
		while(l<Q[i].l) now-=1ll*a[l]*(cnt[a[l]]+(cnt[a[l]]-1)),cnt[a[l]]--,l++;
		while(l>Q[i].l) l--,now+=1ll*a[l]*(cnt[a[l]]+(cnt[a[l]]+1)),cnt[a[l]]++; 
		while(r<Q[i].r) r++,now+=1ll*a[r]*(cnt[a[r]]+(cnt[a[r]]+1)),cnt[a[r]]++;
		while(r>Q[i].r) now-=1ll*a[r]*(cnt[a[r]]+(cnt[a[r]]-1)),cnt[a[r]]--,r--;
		ans[Q[i].id]=now; 
	}
	rep(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}