#include<bits/stdc++.h>
using namespace std;
#define N 500050
typedef long long ll;
string s[N];
vector<int> dp[N],pre[N];
int n,m;
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]=' '+s[i];
		pre[i]=vector<int>(m+1);
		dp[i]=vector<int>(m+1);	
	}
	int mx[2]={0,0};
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			dp[i][j]=(s[i][j]=='1');
			if(j>=3){
				dp[i][j]+=pre[i][j-2];
			}
			pre[i][j]=dp[i][j];
			if(i>=2&&j>=2)pre[i][j]=max(pre[i][j],pre[i-1][j-1]);
			if(i<n&&j>=2)pre[i][j]=max(pre[i][j],pre[i+1][j-1]);
			mx[(i+j)&1]=max(mx[(i+j)&1],dp[i][j]);
		}	
	}
	cout<<mx[0]+mx[1]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}