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
const int LOG = 29;
int n,a[MAXN];ll ans;
vector<int> mjy;
template<class T>inl void ylmin(T &a,T b){a=min(a,b);}
template<class T>inl void ylmax(T &a,T b){a=max(a,b);}
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
struct _01trie{
	int Nodecnt=0,root,ls[MAXN*LOG],rs[MAXN*LOG];
	inl void insert(int &u,int k,int dep){
		if(!u) u=++Nodecnt;
		if(dep==-1) return ;
		((k>>dep)&1)?insert(rs[u],k,dep-1):insert(ls[u],k,dep-1);
	}
	inl int query(int u,int k,int dep){
		if(dep==-1) return 0;
		if((k>>dep)&1){
			if(rs[u]) return query(rs[u],k,dep-1);
			else return query(ls[u],k,dep-1)+(1<<dep);
		}else {
			if(ls[u]) return query(ls[u],k,dep-1);
			else return query(rs[u],k,dep-1)+(1<<dep);
		}
	}
	inl void clear(){
		rep(i,1,Nodecnt) ls[i]=rs[i]=0;
		Nodecnt=root=0;
	}
}quq;
inl void Solve(vector<int> txdy,int dep){
	if(dep==-1 || size(txdy)==0) return ;
	vector<int> ls,rs;
	for(auto x:txdy) if(x&(1<<dep)) ls.pb(x);else rs.pb(x);
	if(!size(ls)) return Solve(rs,dep-1),void();
	if(!size(rs)) return Solve(ls,dep-1),void();
	quq.clear();
	int res=1<<LOG+1;
	for(auto x:ls) quq.insert(quq.root,x,LOG);
	for(auto x:rs) ylmin(res,quq.query(quq.root,x,LOG));
	ans+=res;
	Solve(ls,dep-1),Solve(rs,dep-1);
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n);
	rep(i,1,n) read(a[i]),mjy.pb(a[i]);
	Solve(mjy,LOG);
	printf("%lld\n",ans);
	return 0;
}