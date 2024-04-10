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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int q,n,a[300005];
map<int,int>dp[300005];
int t[300005];
ll d[300005];
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		repn(i,n) scanf("%d",&a[i]);
		repn(i,n){
			t[i] = INF;
			dp[i].clear();
		}
		for(int i=n-1;i>=1;i--){
			if(a[i] == a[i+1]){
				t[i] = i+1;
				swap(dp[i],dp[i+2]);
				if(i+2 <= n){
					if(dp[i].find(a[i+2]) == dp[i].end()) dp[i][a[i+2]] = i+2;
					else dp[i][a[i+2]] = min(dp[i][a[i+2]],i+2);
				}
			}
			else{
				if(dp[i+1].find(a[i]) == dp[i+1].end()) continue;
				
				int x = dp[i+1][a[i]];
				t[i] = x;
				swap(dp[i],dp[x+1]);
				if(i+2 <= n){
					if(dp[i].find(a[x+1]) == dp[i].end()) dp[i][a[x+1]] = x+1;
					else dp[i][a[x+1]] = min(dp[i][a[x+1]],x+1);
				}
			}
		}
		//for(int i=1;i<=n;i++) cout << t[i] << endl;
		for(int i=n;i>=1;i--){
			if(t[i] > n) d[i] = 0;
			else{
				d[i] = 1;
				if(t[i]+1 <= n) d[i] += d[t[i]+1];
			}
		}
		ll ans = 0;
		repn(i,n) ans += d[i];
		cout << ans << endl;
	}
}