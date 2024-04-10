#include<bits/stdc++.h>
using namespace std;
#define N 105
typedef long long ll;
int n,a[N],b[N];
bitset<N*N> dp;
void Solve(){
	cin>>n;
	int sum=0;
	int ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=a[i]*a[i]*(n-2);
		sum+=a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];
		ans+=b[i]*b[i]*(n-2);
		sum+=b[i];
	}
	dp.reset();
	dp[0]=1;
	for(int i=1;i<=n;++i){
		dp=(dp<<a[i])|(dp<<b[i]);
	}
	for(int i=sum/2;i>=0;--i){
		if(dp[i]){
			ans+=i*i+(sum-i)*(sum-i);
			break;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}