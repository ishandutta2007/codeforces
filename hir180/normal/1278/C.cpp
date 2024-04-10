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
int n;
int a[200005];
int pos[200005];
void solve(){
	scanf("%d",&n);
	repn(i,2*n) scanf("%d",&a[i]);
	rep(i,2*n+3) pos[i] = INF;
	pos[n] = n;
	int cur = n;
	for(int i=2*n;i>=n+1;i--){
		if(a[i] == 2) cur++; else cur--;
		pos[cur] = min(pos[cur],i-n-1);
	}
	int ans = n+pos[n];
	cur = n;
	for(int i=1;i<=n;i++){
		if(a[i] == 1) cur++; else cur--;
		ans = min(ans,n-i+pos[cur]);
	}
	printf("%d\n",ans);
}
int main(){
	int t; cin >> t;
	while(t--)solve();
}