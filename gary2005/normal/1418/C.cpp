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
int n;
bool a[200000+20];
int dp[200000+20][2];
void solve()
{
	R(n);
	rb(i,1,n) R(a[i]);
	rb(i,0,n)
		dp[i][0]=dp[i][1]=INF;
	dp[0][1]=0;
	rb(i,1,n){
		rep(j,2){
			int cost=0;
			if(j==0){
				cost+=a[i];
			}
			check_min(dp[i][j],dp[i-1][j^1]+cost);
			if(i!=1){
				if(j==0){
					cost+=a[i-1];
				}	
				check_min(dp[i][j],dp[i-2][j^1]+cost);
			}
		}
	}
	cout<<min(dp[n][0],dp[n][1])<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--) solve();
	return 0;
}