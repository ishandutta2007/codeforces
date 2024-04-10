#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
int n,m;
string s,t;
ll dp[3001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> s >> t;
	n=s.size();m=t.size();
	reverse(s.begin(),s.end());
	s='?'+s;t='?'+t;
	dp[0]=1;
	for(int i=1; i<=n ;i++){
		int c=i&1;
		int p=c^1;
		for(int j=i; j>=0 ;j--){
			int f=n-(i-j-1);
			if(f<=m && t[f]!=s[i]) dp[j]=0;
			if(j==0){
				if(i<=n-m) dp[0]++;
				break;
			}
			if(j>m || t[j]==s[i]) dp[j]=(dp[j]+dp[j-1])%mod;
		}
	}
	ll ans=0;
	for(int i=0; i<=n ;i++){
		ans=(ans+dp[i])%mod;
	}
	cout << ans << endl;
}