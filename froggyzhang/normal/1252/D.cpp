#include<bits/stdc++.h>
using namespace std;
#define N 500005
typedef long long ll;
const ll inf=1e18;
int n,siz[N];
ll ans,dp[N];
vector<int> G[N];
struct Line{
	ll k,b;
	Line(ll _k=0,ll _b=0){k=_k,b=_b;}
	ll val(int x){return k*x+b;}
};
class LiChao_tree{
	int cnt;
	struct node{
		int ch[2];
		Line p;
	}t[N<<1];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
public:
	int rt[N];
	void Insert(int &u,int L,int R,Line z){
		if(!u){u=++cnt;t[u].p=z;return;}
		if(z.val(L)<=t[u].p.val(L)&&z.val(R)<=t[u].p.val(R)){t[u].p=z;return;}
		if(z.val(L)>=t[u].p.val(L)&&z.val(R)>=t[u].p.val(R)){return;}
		int mid=(L+R)>>1;
		if(t[u].p.k<z.k){
			if(z.val(mid)<t[u].p.val(mid)){
				Insert(rs,mid+1,R,t[u].p);t[u].p=z;
			}
			else{
				Insert(ls,L,mid,z);
			}
		}
		else{
			if(z.val(mid)<t[u].p.val(mid)){
				Insert(ls,L,mid,t[u].p);t[u].p=z;
			}
			else{
				Insert(rs,mid+1,R,z);
			}
		}
	}
	ll Query(int u,int L,int R,int x){
		if(!u)return inf;
		ll mn=t[u].p.val(x);
		int mid=(L+R)>>1;
		mn=min(mn,x<=mid?Query(ls,L,mid,x):Query(rs,mid+1,R,x));
		return mn;
	}
}T;
void dfs(int u,int fa){
	siz[u]=1;
	//n^2 - 2nx - 2ny -n +x +y +x^2 +y^2 +2xy
	T.Insert(T.rt[u],1,n,Line(0LL,0LL));
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	dp[u]=1LL*siz[u]*(siz[u]-1)/2;
	for(auto v:G[u]){
		if(v==fa)continue;
		dp[u]=min(dp[u],dp[v]+1LL*(siz[u]-siz[v])*(siz[u]-siz[v]-1)/2);
		ans=min(ans,1LL*n*n-n+T.Query(T.rt[u],1,n,siz[v])+1LL*siz[v]*siz[v]+siz[v]-2LL*n*siz[v]+2LL*dp[v]);
		T.Insert(T.rt[u],1,n,Line(2LL*siz[v],-2LL*n*siz[v]+1LL*siz[v]*siz[v]+siz[v]+2LL*dp[v]));
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);	
	}
	ans=inf;
	dfs(1,0);
	cout<<1LL*n*(n-1)-ans/2<<'\n';
	return 0;
}