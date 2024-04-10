/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2000+20; 
int n,m,belong[MAXN],val[MAXN],sum[MAXN],cntBcc,depth[MAXN],low[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
stack<int> s;
void dfs(int now,int pre,int deep=1){
	s.push(now);
	depth[now]=deep;
	vis[now]=1;
	low[now]=deep;
	for(auto it:g[now]){
		if(it!=pre){
			if(!vis[it]){
				dfs(it,now,deep+1); 
				low[now]=min(low[now],low[it]);
			}
			else{
				low[now]=min(low[now],depth[it]);
			}
		}
	}
	if(low[now]==deep){
		cntBcc++;
//		cout<<cntBcc<<"!".<<endl;
		while(!s.empty()){
			int index=s.top();
//			cout<<index<<endl;
			s.pop();
			val[cntBcc]++;
			belong[index]=cntBcc;
			if(index==now) break;
		}
	}
}
int res,cntCc=0,bestValue[MAXN],cntLeaves[MAXN];
vector<int> CC[MAXN];
bool calc[MAXN];
int dp[MAXN];
int ccSize[MAXN];
void dfsCheck(int now,int pre){
	vis[now]=1;
	ccSize[cntCc]++;
	CC[cntCc].PB(now);
	for(auto it:g[now]){
		if(it!=pre){
			dfsCheck(it,now);
		}
	}
}
void dfsInit(int now,int pre){
	sum[now]=1;
	cntLeaves[now]=0;
	int cntChild=0;
	for(auto it:g[now]){
		if(it!=pre){
			cntChild++;
			dfsInit(it,now);
			sum[now]+=sum[it];
			cntLeaves[now]+=cntLeaves[it]; 
		}
	}
	if(!cntChild)
		cntLeaves[now]=1;
}
int dfsDp(int now,int pre){
	if(calc[now]) return dp[now];
	calc[now]=1;
	dp[now]=1;
	for(auto it:g[now]){
		if(it!=pre)
		dp[now]=max(dp[now],dfsDp(it,now)+1); 
	}
	return dp[now];
}
int main(){
	fastio;
	R2(n,m);
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		edges.PB(II(u,v));
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n)
	if(!vis[i]) dfs(i,0);
	res=n-cntBcc;
	rb(i,1,n)
		g[i].clear();
//	rb(i,1,n) cout<<belong[i]<<" ";cout<<endl; 
	rep(i,m){
		int u,v;
		u=edges[i].FIR;
		v=edges[i].SEC;
		if(belong[u]!=belong[v]){
			g[belong[u]].PB(belong[v]);
			g[belong[v]].PB(belong[u]);
		}
	}
	memset(vis,0,sizeof(vis));
	n=cntBcc;
	rb(i,1,n)
		val[i]=1;
	rb(i,1,n){
		if(!vis[i]){
			cntCc++;
			dfsCheck(i,0);
		}
	}
	rb(i,1,cntCc){
		bestValue[i]=INF;
		for(auto it:CC[i]){
			memset(calc,0,sizeof(calc));
			memset(dp,0,sizeof(dp));
			dfsInit(it,0);
			bestValue[i]=min(bestValue[i],sum[it]-dfsDp(it,0)-cntLeaves[it]+1);
		}
	}
	int addition=0;
	rb(i,1,cntCc){
		addition+=bestValue[i];
	}
	cout<<addition+res+cntCc-1<<endl;
	return 0;
}