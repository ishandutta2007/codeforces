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
int n,k_;
string s,t;
LL dp[202][202][202];
int main(){
	cin>>n>>k_>>s>>t;
	s='&'+s;
	t='$'+t;
	memset(dp,-63,sizeof(dp));
	dp[0][0][0]=0;
	rep(i,n)
	{
		rb(j,0,i)
		{
			rb(k,0,min(i,k_)){
				if(dp[i][j][k]!=dp[0][0][1]){
					rep(l,26){
						char c='a'+l;
						check_max(dp[i+1][j+(c==t[1])][k+(s[i+1]!=c)],dp[i][j][k]+j*(c==t[2]));
//						cout<<i+1<<" "<<j+(c==t[1])<<" "<<k+(s[i]!=c)<<" "<<dp[i][j][k]+j*(c==t[2])<<endl;
					}
				}
			}
		}
	}
	LL rest=-INF;
		rb(j,0,n)
			rb(k,0,k_)
				rest=max(rest,dp[n][j][k]);
	cout<<rest<<endl;
	return 0;
}