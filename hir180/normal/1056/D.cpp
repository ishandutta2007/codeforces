#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
vector<int>edge[100005];
int cnt[100005],n;
int sum[100005];
int ans[100005];
void dfs(int v){
	if(edge[v].size() == 0){
		cnt[v] = 1;
		return;
	}
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i];
		dfs(to);
		cnt[v] += cnt[to];
	}
	return ;;
}
int main(){
    ios::sync_with_stdio(false); 
	cin>>n;
	repn(i,n-1){
		int x;cin>>x;
		edge[x].pb(i+1);
	}
	dfs(1);
	sort(cnt+1,cnt+n+1);
	for(int i=1;i<=n;i++){
		cout<<cnt[i]<<endl;
	}
}