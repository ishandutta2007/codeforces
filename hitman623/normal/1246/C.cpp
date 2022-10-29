#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,dp[2002][2002][2],pre[2002][2002][2],row[2002][2002],col[2002][2002];
string s[2002];
void solve(){
	cin>>n>>m;
	rep(i,0,n) cin>>s[i];
	if(s[n-1][m-1]=='R'){
		cout<<0<<endl;
		return;
	}
	if(n*m==1){
		cout<<1<<endl;
		return;
	}
	rep(i,0,n){
		for(int j=m-1;j>=0;j--){
			row[i][j]=row[i][j+1]+(s[i][j]=='R');
		}
	}
	rep(j,0,m){
		for(int i=n-1;i>=0;i--){
			col[i][j]=col[i+1][j]+(s[i][j]=='R');
		}
	}
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 and j==m-1) dp[i][j][0]=dp[i][j][1]=pre[i][j][0]=pre[i][j][1]=1;
			else{
				int x=n-col[i+1][j];
				int y=m-row[i][j+1];
				dp[i][j][0]=(pre[i+1][j][1]-(x>=i+1?pre[x][j][1]:0)+hell)%hell;
				dp[i][j][1]=(pre[i][j+1][0]-(y>=j+1?pre[i][y][0]:0)+hell)%hell;
				pre[i][j][0]=(pre[i][j+1][0]+dp[i][j][0])%hell;
				pre[i][j][1]=(pre[i+1][j][1]+dp[i][j][1])%hell;				
			}
		}
	}
	cout<<(dp[0][0][0]+dp[0][0][1])%hell<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}