#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
ll dp[405][410];
int n;
int main(){
	cin>>n;
	dp[1][1] = 1;
	dp[1][0] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=5+n;j++){
			for(int k=0;k<=6+n-j;k++){
				if(dp[i][j]==0 || dp[i][k]==0) continue;
				ll x = (dp[i][j]%mod)*(dp[i][k]%mod)%mod;
				if(j+k<=5+n){
					dp[i+1][j+k] += x;
				}
				if(j+k+1<=5+n){
					dp[i+1][j+k+1] += x;
				}
				if(j+k<=5+n){
					dp[i+1][j+k] += x*(j+k)*2LL%mod;
				}
				if(0<=j+k-1 && j+k-1<=5+n){
					dp[i+1][j+k-1] += x*(j+k)*(j+k-1)%mod;
				}
			}
		}
	}
	//cout<<dp[2][1]<<endl;
	cout<<dp[n][1]%mod<<endl;
}