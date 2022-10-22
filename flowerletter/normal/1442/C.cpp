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
const int MAXN = 400010;
const int Mod = 998244353;
const ll inf = 1e18;
int n,m,u,v,pre[MAXN],used[MAXN];
ll dep[MAXN];
vector<int> G[MAXN];
vector<pii> T[MAXN];
struct cmp{
	bool operator()(int a,int b){
		return dep[a]>dep[b];
	}
};
inl void bfs01(int type=0){
	queue<int> Q;
	if(type) rep(i,1,2*n) Q.push(i),used[i]=1; 
	else rep(i,1,n) Q.push(i),used[i]=1;
	while(!Q.empty()){
		int u=Q.front();Q.pop();used[u]=0;
		for(auto v:T[u]) {
			if(dep[v.fir]>dep[u]+v.sec){
				dep[v.fir]=dep[u]+v.sec;
				pre[v.fir]=u;
				if(!used[v.fir]) Q.push(v.fir),used[v.fir]=1;
			}
		}
	}
}
inl int Pow(ll a,ll b,ll ans=1){
	for(;b;b>>=1,a=a*a%Mod) if(b&1) ans=ans*a%Mod;
	return ans;
}
namespace solve1{
	inl int check(){
		rep(i,1,n) T[i].push_back({i+n,1}),T[i+n].push_back({i,1}); 
		rep(i,1,n) for(auto v:G[i]) {
			T[i].push_back({v,0});
			T[v+n].push_back({i+n,0});
		}
		rep(i,1,2*n) dep[i]=inf;
		dep[1]=0;
		bfs01(1);
		ylmin(dep[n],dep[2*n]);
		return dep[n];
	}
	
	inl int work(){
		rep(i,1,2*n) T[i].clear();
		rep(i,1,n) T[i].push_back({i+n,10000000}),T[i+n].push_back({i,10000000}); 
		rep(i,1,n) for(auto v:G[i]) {
			T[i].push_back({v,1});
			T[v+n].push_back({i+n,1});
		}
		ll last=dep[n];
		rep(i,1,2*n) dep[i]=inf;
		dep[1]=0;
		bfs01();ylmin(dep[n],dep[2*n]);
		return (Pow(2,last)-1+dep[n]%Mod-(last*10000000%Mod)+Mod)%Mod;
	}
} 
namespace solve2{
	inl int work(){
		ll ans=inf;
		rep(i,1,n) dep[i]=inf;
		dep[1]=0;
		rep(i,0,17) {
			if(i) rep(j,1,n) dep[j]=dep[j]+Pow(2,i-1);
			rep(j,1,n) T[j].clear();
			if(i&1) rep(j,1,n) for(auto v:G[j]) T[v].push_back({j,1});
			else rep(j,1,n) for(auto v:G[j]) T[j].push_back({v,1});
			bfs01();
			ylmin(ans,dep[n]);
		}
		return ans%Mod;
	}
}
int main(){
//	freopen("in.txt","r",stdin);
	read(n),read(m);
	rep(i,1,m) read(u),read(v),G[u].push_back(v);
	if(solve1::check()>log2(m)) printf("%d\n",solve1::work());
	else printf("%d\n",solve2::work());
	return 0;
}