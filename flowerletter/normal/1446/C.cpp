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
#define ls rt<<1
#define rs rt<<1|1
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
const int MAXN = 2e5 + 10;
const int LOG = 30;
int n,a[MAXN];
struct _01trie{
	#define ls son[rt][0]
	#define rs son[rt][1]
	int son[MAXN*LOG][2],cnt[MAXN*LOG],dp[MAXN*LOG];
	int Nodecnt=1;
	inl void insert(int x){
		int nw=1;
		per(i,30,0) {
			if(!son[nw][(x>>i)&1]) son[nw][(x>>i)&1]=++Nodecnt;
			nw=son[nw][(x>>i)&1];
		}
		cnt[nw]++;
	}
	inl void dfs(int rt){
		if(!rt) return ;
		dfs(ls),dfs(rs);
		dp[rt]=max(dp[ls]+min(dp[rs],1),dp[rs]+min(dp[ls],1))+cnt[rt];
	}
}mjy;
int main(){
	//freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),mjy.insert(a[i]);
	mjy.dfs(1); 
	printf("%d\n",n-mjy.dp[1]);
	return 0;
}