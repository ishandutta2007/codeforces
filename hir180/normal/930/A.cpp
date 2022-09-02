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
vector<int>edge[100005];
int num[100005];
void dfs(int v,int u,int d){
	num[d]++;
	rep(i,edge[v].size()){
		dfs(edge[v][i],v,d+1);
	}
}
int main(){
	cin>>n;
	repn(i,n-1){
		int x;
		scanf("%d",&x);
		edge[x].pb(i+1);
	}
	dfs(1,-1,0);
	int ans = 0;
	rep(i,100005) ans+=num[i]%2;
	cout<<ans<<endl;
}