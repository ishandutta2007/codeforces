/**
 *    author:  gary
 *    created: 01.09.2021
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+1;
vector<int> g[MAXN];
int n;
int dp[MAXN][2];
set<pair<int,int> > se[MAXN];
void dfs(int now,int pre){
	for(auto it:g[now]) if(it!=pre) dfs(it,now);
	dp[now][1]=g[now].size()-(pre!=0);
	dp[now][0]=-INF;
	if(pre&&g[now].size()==2){
		for(auto it:g[now]) if(it!=pre){
			dp[now][0]=dp[it][1]+1;
		}
	}
	int sz=dp[now][1];
	--sz;
	if(sz<0) return ;
	for(auto it:g[now]) if(it!=pre){
		check_max(dp[now][1],max(dp[it][1],dp[it][0])+sz);
		se[now].insert(II(max(dp[it][1],dp[it][0]),it));
	}
}
int answer=0;
void wrk(int now,int pre){
	dp[now][1]=g[now].size()-(pre!=0);
	dp[now][0]=-INF;
	if(pre&&g[now].size()==2){
		for(auto it:g[now]) if(it!=pre){
			dp[now][0]=dp[it][1]+1;
		}
	}
	int sz=dp[now][1];
	--sz;
	if(sz<0) return ;
	check_max(dp[now][1],prev(se[now].end())->FIR+sz);
}
void chg(int now,int pre){
	check_max(answer,dp[now][1]);
	for(auto it:g[now]) if(it!=pre){
		int tmp[2];
		tmp[0]=dp[it][0];
		tmp[1]=dp[it][1];
		auto T=II(max(dp[it][0],dp[it][1]),it);
		se[now].erase(T);
		wrk(now,it);
		se[it].insert(II(max(dp[now][0],dp[now][1]),now));
		wrk(it,0);
		chg(it,now);
		se[now].insert(T);
		dp[it][0]=tmp[0];
		dp[it][1]=tmp[1];
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	chg(1,0);
	cout<<answer<<endl;
	return 0;
}