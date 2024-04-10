#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const int mxn=5555;
int ti,td,tr,te;
int dp[mxn][mxn];
int prea[mxn][30];
int preb[mxn][30];
int pos[30];
string a,b;int n,m;
inline void solve(){
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	cin>>ti>>td>>tr>>te;
	cin>>a>>b;
	n=a.size(),m=b.size();
	a=" "+a,b=" "+b;
	memset(pos,0,sizeof(pos));
	for(int i=1;i<=n;++i){
		for(int j=0;j<26;++j)prea[i][j]=pos[j];
		pos[a[i]-'a']=i;
	}
	memset(pos,0,sizeof(pos));
	for(int i=1;i<=m;++i){
		for(int j=0;j<26;++j)preb[i][j]=pos[j];
		pos[b[i]-'a']=i;
	}
	for(int i=0;i<=n;++i)for(int j=0;j<=m;++j){
		if(i)dp[i][j]=min(dp[i][j],dp[i-1][j]+td);
		if(j)dp[i][j]=min(dp[i][j],dp[i][j-1]+ti);
		if(i and j){
			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i]!=b[j])*tr);
			int pa=prea[i][b[j]-'a'],pb=preb[j][a[i]-'a'];
			if(pa and pb)dp[i][j]=min(dp[i][j],dp[pa-1][pb-1]+(j-pb-1)*ti+(i-pa-1)*td+te);
		}
	}
	cout<<dp[n][m]<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;T=1;
//	cin>>T;
	for(;T--;)solve();
}