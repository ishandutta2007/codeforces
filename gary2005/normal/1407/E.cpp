/*
{By GWj
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=5e5+20;
vector<pair<int,bool > > g[MAXN];
void add_edge(int u,int v,int col){
	if(u==v) return ;
	g[v].PB(II(u,col));
}
int n,m;
int dp[MAXN][2];
int cnt[MAXN];
int main(){
	fastio;
	R2(n,m);
	rb(i,1,m){
		int u,v,c;
		cin>>u>>v>>c;
		add_edge(u,v,c); 
	} 
	memset(dp,63,sizeof(dp));
	dp[n][0]=dp[n][1]=0;
	priority_queue<pair<int,mp> ,vector<pair<int,mp> > ,greater<pair<int,mp> > > q;
	q.push(II(0,II(n,0)));
	q.push(II(0,II(n,1)));
	while(!q.empty()){
		pair<int,mp> now=q.top();
		q.pop();
		int i,j;
		i=now.SEC.FIR;
		j=now.SEC.SEC;
		if(dp[i][j]!=now.FIR) continue;
		cnt[i]++;
		if(cnt[i]==1) continue;
		for(auto it:g[i]){
			if(dp[it.FIR][it.SEC]>dp[i][j]+1){
				dp[it.FIR][it.SEC]=dp[i][j]+1;
				q.push(II(dp[it.FIR][it.SEC],II(it.FIR,it.SEC)));
			}
		}
	}
	cout<<(max(dp[1][0],dp[1][1])!=INF? max(dp[1][0],dp[1][1]):-1)<<endl;
	rb(i,1,n){
		cout<<(dp[i][1]>dp[i][0]? 1:0);
	}cout<<endl;
	return 0;
}