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
const int MAXN = 1e6+10;
int n;ll dp[MAXN],ans;
struct Node{ll x,y,val;}a[MAXN];
struct Decide{int l,r,s;}; 
deque<Decide> Q;
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
inl bool cmp(Node a,Node b){
	return a.x<b.x;
}
inl ll cacl(int x,int y){
	return dp[x]+(a[y].x-a[x].x)*a[y].y-a[y].val;
}
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("myout.txt","w",stdout); 
	read(n);
	rep(i,1,n) read(a[i].x),read(a[i].y),read(a[i].val);
	sort(a+1,a+n+1,cmp);
	Q.push_front((Decide){1,n,0});
	rep(i,1,n){
		while(Q.front().r<i) Q.pop_front();
		dp[i]=cacl(Q.front().s,i);
		while(!Q.empty() && cacl(Q.back().s,Q.back().l)<cacl(i,Q.back().l)) Q.pop_back();
		if(Q.empty()) Q.pb((Decide){1,n,i});
		else {
			Decide x=Q.back();
			int l=x.l,r=x.r,s=x.s,ans=-1;
			while(l<=r){
				int mid=l+r>>1;
				if(cacl(s,mid)<cacl(i,mid)) ans=mid,r=mid-1;
				else l=mid+1;
			}
			if(ans!=-1){
				Q.pop_back();
				Q.pb((Decide){x.l,ans-1,x.s});
				Q.pb((Decide){ans,n,i});
			}else if(x.r!=n){
				Q.pb((Decide){x.r+1,n,i});
			}
		} 
		
	}
	rep(i,1,n) ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}