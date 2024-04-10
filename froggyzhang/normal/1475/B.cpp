#include<bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const int n=1e6;
bool dp[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0]=1;
	for(int j=2020;j<=2021;++j){
		for(int i=j;i<=n;++i){
			dp[i]|=dp[i-j];
		}
	}
	int T;
	cin>>T;
	while(T--){
		int x;
		cin>>x;
		cout<<(dp[x]?"Yes\n":"No\n");
	}
	return 0;
}