#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll dp[11][705][705][2];
string s;
void init(int digit){
	memset(dp[digit],0LL,sizeof(dp[digit]));
	dp[digit][0][0][1] = 1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<=i;j++){
			if(dp[digit][i][j][0]){
				for(int x=0;x<10;x++){
					dp[digit][i+1][(j+(x>=digit))][0] += dp[digit][i][j][0];
					dp[digit][i+1][(j+(x>=digit))][0] %= mod;
				}
			}
			if(dp[digit][i][j][1]){
				for(int x=0;x<=(s[i]-'0');x++){
					dp[digit][i+1][(j+(x>=digit))][x==(s[i]-'0')] += dp[digit][i][j][1];
					dp[digit][i+1][(j+(x>=digit))][x==(s[i]-'0')] %= mod;
				}
			}
		}
	}
}
ll rec(int digit,int num){
	//digitnum
	ll ret = 0;
	for(int i=num;i<705;i++) for(int j=0;j<2;j++) ret = (ret+dp[digit][s.size()][i][j]+mod-dp[digit+1][s.size()][i][j])%mod;
	return ret;
}
int main(){
	cin>>s;
	ll ans = 0;
	for(int i=1;i<=9;i++){
		init(i);
	}
	for(int i=1;i<=9;i++){
		ll t = 1;
		for(int j=1;j<=s.size();j++){
			ans += 1LL*t*i%mod*rec(i,j)%mod;
			t = t*10LL%mod;
		}
	}
	cout << ans%mod << endl;
}