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
const int MAXN = 4010;
int n,k,size[MAXN],dp[MAXN];
int w[MAXN][MAXN],v[MAXN][MAXN];
struct Node{
	int s,l,r;
};
inl int calc(int i,int j,int x){
	return dp[i]+v[i+1][j]+x;
}
inl int check(int x){
	deque<Node> Q;
	Q.push_front((Node){0,1,n});
	rep(i,1,n) {
		while(Q.front().r<i) Q.pop_front();
		int u=Q.front().s;
		dp[i]=calc(u,i,x);
		size[i]=size[u]+1;
		if(calc(i,n,x)>=calc(Q.back().s,n,x)) continue;
		while(calc(Q.back().s,Q.back().l,x)>calc(i,Q.back().l,x)) Q.pop_back();
		Node last=Q.back();
		int l=last.l,r=last.r,ans=last.r+1;
		while(l<=r){
			int mid=l+r>>1;
			if(calc(last.s,mid,x)>calc(i,mid,x)) ans=mid,r=mid-1;
			else l=mid+1;
		} 
		Q.pop_back(),Q.push_back((Node){last.s,last.l,ans-1}),Q.push_back((Node){i,ans,n});
	}
	return size[n];
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(k);
	rep(i,1,n) rep(j,1,n) read(w[i][j]),w[i][j]+=w[i-1][j]+w[i][j-1]-w[i-1][j-1];
	rep(i,1,n) rep(j,i,n) v[i][j]=(w[j][j]+w[i-1][i-1]-w[i-1][j]-w[j][i-1])/2;
	int l=0,r=1e9,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)>k) l=mid+1;
		else ans=mid,r=mid-1; 
	}
	check(ans);
	cout<<dp[n]-ans*k;
	return 0;
}