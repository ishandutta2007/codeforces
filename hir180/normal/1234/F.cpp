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
#define INF 10000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
char s[1000005];
int dp[(1<<20)];
int main(){
	scanf("%s",&s);
	int n = strlen(s);
	for(int i=0;i<n;i++){
		int cur = 0;
		for(int j=i;j<n;j++){
			int c = s[j]-'a';
			if(((cur>>c)&1)) break;
			cur |= (1<<c);
			dp[cur] = j-i+1;
		}
	}
	//cnt[j]... j no submask
	for(int i=0;i<20;i++){
		for(int j=0;j<(1<<20);j++){
			if(((j>>i)&1)) dp[j] = max(dp[j],dp[j^(1<<i)]);
		}
	}
	int ans = 0;
	for(int i=0;i<(1<<20);i++){
		ans = max(ans,dp[i] + dp[(1<<20)-1-i]);
	}
	cout << ans << endl;
}