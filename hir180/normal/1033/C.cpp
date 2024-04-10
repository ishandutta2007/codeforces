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
int a[100005],rev[100005];
int dp[100005],n;
int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		rev[a[i]] = i;
	}
	dp[n] = 1;
	for(int i=n-1;i>=1;i--){
		bool ok;
		int cur = rev[i];
		
		ok = 0;
		for(int x=cur+i;x<=n;x+=i) if(a[x] > i && dp[a[x]] == 1) ok = 1;
		for(int x=cur-i;x>=1;x-=i) if(a[x] > i && dp[a[x]] == 1) ok = 1;
		if(ok) dp[i] = 0;
		else dp[i] = 1;
	}
	for(int i=1;i<=n;i++){
		int x = dp[a[i]];
		if(x == 0) printf("A");
		else printf("B");
	}
	puts("");
}