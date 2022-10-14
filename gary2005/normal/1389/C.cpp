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
int t;
int dp[2];
int main(){
	fastio;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int best=0;
		
		rb(i,0,9)
			rb(j,0,9){
				dp[0]=dp[1]=-INF;
				dp[1]=0;
				rep(k,n){
					int l0,l1;
					l0=dp[0];
					l1=dp[1];
					if(s[k]=='0'+i){
						dp[0]=max(dp[0],l1+1);
					}
					if(s[k]=='0'+j){
						dp[1]=max(dp[1],l0+1);
					}
				}
				best=max(best,dp[1]);
			}
		int res=n-best;
		int cnt[10]={0};
		rep(i,n)
			cnt[s[i]-'0']++;
		rb(i,0,9)
			res=min(res,n-cnt[i]);
		cout<<res<<endl;
	}	
	return 0;
}