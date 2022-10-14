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
LL dp[100000+20][20][2];int a[100000+20];
int n;
vector<int> each[100000+20];
void dfs(int now,int prev){
	rep(i,20)
		dp[now][i][(a[now]>>i)&1]=1;
	for(auto it:each[now]){
		if(it!=prev){
			dfs(it,now);
			rep(j,20){	
				int bit=(a[now]>>j)&1;
				dp[now][j][0]+=dp[it][j][0^bit];
				dp[now][j][1]+=dp[it][j][1^bit];
			}
		}
	}
}
LL res=0;
void change_root(int now,int prev){
	rep(i,20)
		res+=(LL)(1<<i)*dp[now][i][1];
	for(auto it:each[now]){
		if(it!=prev){
			rep(j,20){
				int bit=(a[now]>>j)&1;
				dp[now][j][0]-=dp[it][j][0^bit];
				dp[now][j][1]-=dp[it][j][1^bit];
			}
			
			rep(j,20){
				int bit=(a[it]>>j)&1;
				dp[it][j][0]+=dp[now][j][0^bit];
				dp[it][j][1]+=dp[now][j][1^bit];
			}
			change_root(it,now);
			rep(j,20){
				int bit=(a[it]>>j)&1;
				dp[it][j][0]-=dp[now][j][0^bit];
				dp[it][j][1]-=dp[now][j][1^bit];
			}
			rep(j,20){
				int bit=(a[now]>>j)&1;
				dp[now][j][0]+=dp[it][j][0^bit];
				dp[now][j][1]+=dp[it][j][1^bit];
			}
			
		}
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n) cin>>a[i];
	rb(i,2,n)
	{
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u);
	}
	dfs(1,-1);
	change_root(1,-1);
	rb(i,1,n)
		res+=a[i]; 
	cout<<res/2<<endl;
	return 0;
}