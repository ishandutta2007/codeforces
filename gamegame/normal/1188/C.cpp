#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int mid=300;
int n,k;
int a[100001];
ll dp[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1; i<=100000/(k-1) ;i++){
		int l=0;
		for(int j=1; j<=n ;j++){
			while(l<j && a[j]-a[l+1]>=i) l++;
			for(int x=1; x<=k ;x++){
				dp[j][x]=dp[j-1][x]+dp[l][x-1]+(x==1);
				if(dp[j][x]>=mod) dp[j][x]-=mod;
			}
		}
		ans+=dp[n][k];
	}
	cout << ans%mod << endl;
}