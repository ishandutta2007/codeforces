#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
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
ll dp[1000005][3],cnt[1000005];
ll dp2[1000005];
int n;
int ten[6]={1,10,100,1000,10000,100000};
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	scanf("%d",&n);
	repn(i,n){
		int a;scanf("%d",&a);
		cnt[a]++;
	}
	for(int i=999999;i>=0;i--){
		int digit[6];
		int j = i;
		rep(k,6){
			digit[k] = (j%10);
			j /= 10;
		}
		for(int ii=1;ii<64;ii++){
			int sum = 0;
			rep(k,6){
				int x = digit[k];
				if(((ii>>k)&1)) x++;
				if(x != 10) sum += x*ten[k];
				else goto nxt;
			}
			if(__builtin_popcount(ii)%2 == 1){
				rep(g,3) dp[i][g] += dp[sum][g];
			}
			else{
				rep(g,3) dp[i][g] -= dp[sum][g];
			}
			nxt:;
		}
		dp[i][0] += cnt[i];
		dp[i][1] += 1LL*i*i%mod*cnt[i]%mod;
		dp[i][2] += 1LL*i*cnt[i]%mod;
		dp[i][0] = (dp[i][0]%mod+mod)%mod;
		dp[i][1] = (dp[i][1]%mod+mod)%mod;
		dp[i][2] = (dp[i][2]%mod+mod)%mod;
		if(dp[i][0]>=1) dp2[i] += dp[i][1]*modpow(2LL,dp[i][0]-1)%mod;
		if(dp[i][0]>=2) dp2[i] += ((dp[i][2]*dp[i][2])%mod-dp[i][1])%mod*modpow(2LL,dp[i][0]-2)%mod;
		dp2[i] = (dp2[i]%mod+mod)%mod;
	}
	rep(i,1000000){
		int digit[6];
		int j = i;
		rep(k,6){
			digit[k] = (j%10);
			j /= 10;
		}
		for(int ii=1;ii<64;ii++){
			int sum = 0;
			rep(k,6){
				int x = digit[k];
				if(((ii>>k)&1)) x++;
				if(x != 10) sum += x*ten[k];
				else goto nxt2;
			}
			if(__builtin_popcount(ii)%2 == 1){
				dp2[i] -= dp2[sum];
			}
			else{
				dp2[i] += dp2[sum];
			}
			nxt2:;
		}
		dp2[i] = (dp2[i]%mod+mod)%mod;
	}
	ll ans = 0;
	for(int i=999999;i>=0;i--){
		ll add = dp2[i]*1LL*i;
		ans ^= add;
	}
	cout << ans << endl;
}