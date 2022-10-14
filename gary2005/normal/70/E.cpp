/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
/*}
*/
int n,k;
const int MAXN=180+2;
int dp2[MAXN],dp[MAXN][MAXN],d[MAXN],depth[MAXN],dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<int> g[MAXN];
int dfs(int now,int best,int pre=0){
	if(vis[now][best]){
		return dp[now][best];
	}
	vis[now][best]=1;
	if(best==now){
		dp[now][best]=k;
	}
	else{
		dp[now][best]=d[dis[now][best]];
	}
	for(auto it:g[now]){
		if(it==pre) continue;
		if(dis[it][best]+1==dis[now][best]) continue; 
		dp[now][best]+=min(dfs(it,best,now),dp2[it]);
	} 
	for(auto it:g[now]){
		//cout<<now<<" "<<best<<" "<<it<<" "<<dis[it][best]<<" "<<dis[now][best]<<" "<<pre<<endl;
		if(it==pre) continue;
		if(dis[it][best]+1==dis[now][best]){
//			cout<<now<<"Yes"<<best<<" "<<it<<endl;
			dp[now][best]+=dfs(it,best,now);	
		} 
	}
	return dp[now][best];
}
int run(int st,int now,int pre=0){
//	cout<<<<now<<"~"<<pre<<endl;
	int res=dfs(st,now,pre);
	for(auto it:g[now]){
		if(depth[it]>depth[now])
		res=min(res,run(st,it,pre));
	} 
	return res;
}
void init(int now,int pre=0){
	depth[now]=depth[pre]+1;
	for(auto it:g[now]){
		if(it==pre) continue;
		init(it,now);
	}
}
void dfs_dis(int st,int now,int pre=0,int dist=0){
	dis[st][now]=dist;
	for(auto it:g[now]){
		if(it==pre) continue;
		dfs_dis(st,it,now,dist+1);
	} 
}
void dfs_help(int now,int pre=0){
	for(auto it:g[now]){
		if(it==pre) continue;
		dfs_help(it,now);
	}
	dp2[now]=run(now,now,pre);
}
int rest[MAXN];
int print2(int now,int pre){
	rb(i,1,n){
		if(depth[i]>=depth[now]&&dis[i][now]==depth[i]-depth[now]&&dp2[now]==dfs(now,i,pre)){
			return i;
		}
	}
	assert(0);
	return now;//That's impossible
} 
void print(int now,int best,int pre){
	rest[now]=best;
	for(auto it:g[now]){
		if(it==pre) continue;
		if(dis[it][best]+1==dis[now][best]) continue; 
		if(dfs(it,best,now)<dp2[it]){
			print(it,best,now);
		}
		else{
			print(it,print2(it,now),now);
		}
	} 
	for(auto it:g[now]){
		if(it==pre) continue;
		if(dis[it][best]+1==dis[now][best]){
			print(it,best,now);
			break;
		}
	}
}
int main(){
	fastio;
	R2(n,k);
	rb(i,1,n-1){
		R(d[i]);
	}
	rb(i,2,n){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	memset(dp2,63,sizeof(dp2));
	init(1);
	rb(i,1,n)
		dfs_dis(i,i);
	dfs_help(1);
	int res=INF;
	rb(i,1,n)
	{
		res=min(dfs(1,i),res);
	}
	cout<<res<<endl;
	rb(i,1,n){
		if(dfs(1,i)==res){
			print(1,i,0);
			break;
		}
	} 
	rb(i,1,n){
		cout<<rest[i]<<" ";
	}cout<<endl;
	return 0;
}