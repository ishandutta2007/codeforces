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
int T,n,m,k,u,v,du[MAXN],is[MAXN],vis[MAXN];
vector<int> G[MAXN];
struct Node{
	int du,id;
	friend bool operator < (Node a,Node b){
		return a.du>b.du;
	}
};
int main(){
//	freopen("in.txt","r",stdin);
	for(read(T);T;T--){
		read(n),read(m),read(k);
		rep(i,1,m) {
			read(u),read(v);
			G[u].push_back(v);
			G[v].push_back(u);
			du[u]++,du[v]++;
		}
		rep(i,1,n) sort(all(G[i]));
		priority_queue<Node> Q;
		rep(i,1,n) if(du[i]<k) Q.push((Node){du[i],i});
		vector<int> S; int flag=0;
		while(!Q.empty()){
			int u=Q.top().id,d=Q.top().du;Q.pop();
			if(d!=du[u]) continue;
			is[u]=1;
			if(du[u]==k-1 && k*(k-1)/2<=m && flag!=1) {
				S.clear();S.push_back(u);
				flag=1;
				for(auto v:G[u]) if(!is[v]) S.push_back(v);
				for(auto x:S){
					for(auto y:S) {
						if(x!=y && !binary_search(all(G[x]),y)) {
							flag=0;
							break;
						}
					}
					if(!flag) break;
				}
				if(flag==1) {
					puts("2");
					for(auto nw:S) cout<<nw<<' ';puts("");
					break; 
				}
			}
			for(auto v:G[u]){
				if(!is[v]){
					du[v]--;
					if(du[v]<k) Q.push((Node){du[v],v}); 
				}
			}
		}
		if(flag!=1) {
			int cnt=0;
			rep(i,1,n) if(du[i]>=k) cnt++;
			if(cnt){
				printf("1 %d\n",cnt);
				rep(i,1,n) if(!is[i]) printf("%d ",i);
				puts("");
			}
			else puts("-1");
		}
		rep(i,1,n) G[i].clear(),du[i]=0,is[i]=0;
	}
	return 0;
}