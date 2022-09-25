#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n;
char s[N];
pair<int,int> dp[N][2];
inline pair<int,int> operator + (const pair<int,int> &a,const pair<int,int> &b){
	return make_pair(a.first+b.first,a.second+b.second);
}
void Solve(){
	cin>>n;
	cin>>(s+1);
	for(int i=1;i<=n;++i){
		int c=s[i]-'0';
		for(int j=0;j<2;++j){
			if(i&1){
				dp[i][j]=min(dp[i-1][0]+make_pair(j^c,j!=0),dp[i-1][1]+make_pair(j^c,j!=1));
			}
			else{
				dp[i][j]=dp[i-1][j]+make_pair(j^c,0);
			}
		}
	}
	auto [a1,a2]=min(dp[n][0],dp[n][1]);
	cout<<a1<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}