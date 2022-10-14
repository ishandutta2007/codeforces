/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,dp[3001][3001][2],dp2[3001];
vector<pair<int,bool > > each[3003]; 
void dfs(int start,int now,int prev){
	for(auto itw:each[now]){
		int it=itw.FIR,val=itw.SEC;
		if(it!=prev){
			dp[start][it][0]=dp[start][now][0]+val;
			dp[start][it][1]=dp[start][now][0]+val;
			dp[start][it][1]=min(dp[start][it][1],dp[start][now][1]+(val^1));
			dfs(start,it,now);
		}
	}
}
void dfs2(int now,int prev){
	for(auto it:each[now]){
		if(it.FIR!=prev){
			dfs2(it.FIR,now);
			dp2[now]+=dp2[it.FIR]+it.SEC;
		}
	}
}
int res=INF;
void dfs3(int start,int now,int prev,int val){
	res=min(res,val+min(dp[start][now][1],dp[start][now][0])+dp2[now]);
//	cout<<now<<" "<<val<<endl;
	for(auto it:each[now]){
		//it
		if(it.FIR!=prev)
		dfs3(start,it.FIR,now,val+dp2[now]-dp2[it.FIR]-it.SEC); 
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,2,n){
		int u,v;
		cin>>u>>v;
		each[u].PB(II(v,0));
		each[v].PB(II(u,1));
	} 
	rb(i,1,n){
		dp[i][i][0]=0;
		dp[i][i][1]=0;
		dfs(i,i,-1);
	}
	rb(i,1,n){
		rb(j,1,n)
			dp2[j]=0;
		dfs2(i,-1);
		dfs3(i,i,-1,0);
		
	}
	cout<<res<<endl;
	return 0;
}