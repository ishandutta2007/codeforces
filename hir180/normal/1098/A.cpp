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
int n;
ll a[100005];
ll b[100005];
vector<int>edge[100005];
bool bad = 0;
ll ans;
void dfs(int v){
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i];
		dfs(to);
		b[v] = min(b[v],b[to]);
	}
	if(a[v] >= 0){
		if(a[v] > b[v]){
			bad = 1;
		}
		b[v] = min(b[v],a[v]);
	}
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i];
		if(b[to] <= 1e17){
			ans += b[to]-b[v];
		}
	}
	if(v == 1) ans += b[v];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a; scanf("%d",&a);
		edge[a].pb(i+1);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i] = 1e18;
	}
	dfs(1);
	if(bad) puts("-1");
	else cout<<ans<<endl;}