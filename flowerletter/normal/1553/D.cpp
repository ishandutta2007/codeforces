#include <bits/stdc++.h>
using namespace std;
int dp[100005];
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a >> b;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int n=a.size(),m=b.size();
		a=' '+a,b=' '+b+' ';
		int mx=0;
		for(int i=1;i<=n;i++)
		{
			dp[i]=-100000;
			if(i>1) dp[i]=max(dp[i], dp[i-2]);
			if(dp[i-1] >= 0 && b[dp[i-1]+1]==a[i]) dp[i]=max(dp[i], dp[i-1]+1);
			if(dp[i]==m) 
			{
			    mx=m;
			    break;
			}
		}
		if(mx==m)
		{
			cout << "YES\n";
		}else cout << "NO\n";
	}
	return 0;
}