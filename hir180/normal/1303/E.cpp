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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int t;
string a,b;
int dp[405];
void solve(){
	cin >> a >> b;
	int n = a.size(), m = b.size();
	for(int i=0;i<=m;i++){
		int x = i, y = m-i;
		rep(a,x+2) dp[a] = -INF;
		dp[0] = 0;
		rep(pt,n){
			for(int p=x;p>=0;p--){
			    if(dp[p] < 0) continue;
			    if(p < x && b[p] == a[pt]) dp[p+1] = max(dp[p+1],dp[p]);
			    if(dp[p] < y && b[x+dp[p]] == a[pt]) dp[p] ++;
			}
		}
		if(dp[x] == y){
			puts("YES"); return ;
		}
	}
	puts("NO");
}
int main(){
	cin>>t;
	while(t--) solve();
}