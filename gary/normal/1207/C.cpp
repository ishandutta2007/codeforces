//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[200000+10][3];
LL n,a,b;
string s;
void solve(){
	memset(dp,127,sizeof(dp));
	cin>>n>>a>>b;
	cin>>s;
	s='$'+s;
	rb(i,1,n){
		if(s[i]=='1'){
			dp[i][2]=dp[i-1][2]+a+b+b;
		}
		else
		{
			dp[i][1]=a+b;
			if(i==1) dp[i][1]+=b;
			else dp[i][1]+=min(dp[i-1][1],dp[i-1][2]+a);
			if(i!=1){
				dp[i][2]=a+b+b;
			
			dp[i][2]+=min(dp[i-1][1]+a,dp[i-1][2]);
			}
			else{
				dp[i][2]=a+a+b+b+b;
			}
		}
	}
	cout<<dp[n][1]<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}