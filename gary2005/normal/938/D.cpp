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
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
priority_queue<mp,vector<mp>,greater<mp> > q;
int n,m,a[200000+1],dp[200000+1];
vector<mp> each[200000+1];
signed main(){
	fastio;
	cin>>n>>m;
	rb(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		w<<=1;
		each[u].PB(II(v,w));
		each[v].PB(II(u,w));
	}
	rb(i,1,n) cin>>dp[i],q.push(II(dp[i],i));
	while(!q.empty()){
		mp now=q.top();
		q.pop();
//		cout<<now.SEC<<endl;
		if(dp[now.SEC]!=now.FIR){
			continue;
		}
		for(auto it:each[now.SEC]){
			if(dp[it.FIR]>dp[now.SEC]+it.SEC){
				dp[it.FIR]=dp[now.SEC]+it.SEC;
				q.push(II(dp[it.FIR],it.FIR));
			}
		}
	}
	rb(i,1,n) cout<<dp[i]<<" ";
	return 0;
}