#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;
const int N = 100005;
int dp[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] == 'm' || s[i] == 'w'){
			cout<<0<<endl;
			return 0;
		}
	}
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		if(s[i] == 'u' && s[i-1] == 'u'){
			dp[i] = dp[i-1] + ((i >= 2)?dp[i-2]:1);
			if(dp[i] >= mod)dp[i] -= mod; 
		}else if(s[i] == 'n' && s[i-1] == 'n'){
			dp[i] = dp[i-1] + ((i >= 2)?dp[i-2]:1);
			if(dp[i] >= mod)dp[i] -= mod;
		}else{
			dp[i] = dp[i-1];
		}
		// cout<<dp[i]<<" ";
	}
	cout<<dp[n-1]<<endl;


	return 0;
}