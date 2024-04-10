#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1e18;
const int C=1e5;
int n,a[N],b[N];
ll dp[N];
vector<int> G[N];
struct Line{
	ll k,b;
	Line(ll _k=inf,ll _b=inf){k=_k,b=_b;}
	ll Val(int x){return 1LL*k*x+b;}
};
class LiChao_Tree{
	int cnt;
	struct node{
		int ch[2];
		Line p;
	}t[N<<5];
public:
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	int rt[N];
	void Insert(int &u,int L,int R,Line z){
		if(!u){
			t[u=++cnt].p=z;
			return;
		}
		if(t[u].p.Val(L)<=z.Val(L)&&t[u].p.Val(R)<=z.Val(R))return;
		if(t[u].p.Val(L)>=z.Val(L)&&t[u].p.Val(R)>=z.Val(R)){
			t[u].p=z;return;
		}
		int mid=L+(R-L+1)/2;
		if(t[u].p.k<z.k){
			if(t[u].p.Val(mid)>z.Val(mid)){
				Insert(rs,mid+1,R,t[u].p);t[u].p=z;
			}
			else{
				Insert(ls,L,mid,z);
			}
		}
		else{
			if(t[u].p.Val(mid)>z.Val(mid)){
				Insert(ls,L,mid,t[u].p);t[u].p=z;
			}
			else{
				Insert(rs,mid+1,R,z);
			}
		}
	}
	ll Query(int u,int L,int R,int x){
		if(!u)return inf;
		int mid=L+(R-L+1)/2;
		ll mn=t[u].p.Val(x);
		mn=min(mn,x<=mid?Query(ls,L,mid,x):Query(rs,mid+1,R,x));
		return mn;
	}
	void Merge(int &u,int v,int L,int R){
		if(!u||!v){u|=v;return;}
		Insert(u,L,R,t[v].p);
		int mid=L+(R-L+1)/2;
		Merge(ls,t[v].ch[0],L,mid);
		Merge(rs,t[v].ch[1],mid+1,R);
	}
}T;
void dfs(int u,int fa){
	for(auto v:G[u]){
		if(v==fa)continue;
		dfs(v,u);
		T.Merge(T.rt[u],T.rt[v],-C,C);
	}
	if(T.rt[u])dp[u]=T.Query(T.rt[u],-C,C,a[u]);
	T.Insert(T.rt[u],-C,C,Line(b[u],dp[u]));	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i){
		cout<<dp[i]<<' ';
	}
	return 0;
}