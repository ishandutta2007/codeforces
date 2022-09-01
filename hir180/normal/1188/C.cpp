#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k,a[1005];
ll dp[1005][1005];
ll rui[1005][1005];
int main(){
	cin>>n>>k;
	repn(i,n) cin>>a[i];
	sort(a+1,a+n+1);
	ll ans = 0;
	for(int v=1;v<=100000/(k-1)+5;v++){
		for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = rui[i][j] = 0;
		dp[0][0] = 1;
		rui[0][0] = 1;
		a[0] = -INF;
		int x = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				while(a[i]-a[x] >= v) x++;
				dp[i][j] = (x==0?0:rui[x-1][j-1]);
			}
			for(int j=0;j<=k;j++){
				rui[i][j] = rui[i-1][j]+dp[i][j];
				if(rui[i][j] >= mod) rui[i][j]-=mod;
			}
		}
		ans += rui[n][k]; //cout << v << " " << rui[n][k] << endl;
	}
	cout << (ans%mod+mod)%mod << endl;
}