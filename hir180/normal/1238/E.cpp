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
int n,m;
string s;
int dp[(1<<20)],cnt[(1<<20)];
int main(){
	cin >> n >> m >> s;
	for(int i=1;i<n;i++){
		int x = s[i-1]-'a';
		int y = s[i]-'a';
		cnt[(1<<x)|(1<<y)] ++;
	}
	rep(i,m) rep(j,(1<<m)){
		if(((j>>i)&1)) cnt[j] += cnt[j^(1<<i)];
	}
	rep(i,(1<<m)) dp[i] = INF;
	dp[0] = 0;
	rep(i,(1<<m)){
		rep(j,m){
			if(((i>>j)&1)) continue;
			int add = n-1;
			add -= cnt[i+(1<<j)] + cnt[(1<<m)-1-(i+(1<<j))];
			dp[i+(1<<j)] = min(dp[i+(1<<j)], dp[i] + add);
		}
	}
	cout << dp[(1<<m)-1] << endl;
}