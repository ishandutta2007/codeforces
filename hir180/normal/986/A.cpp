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
int dist[100005][105];
bool used[100005][105];
int n,m,k,s;
int a[100005];
vector<int>edge[100005];
int main(){
	cin>>n>>m>>k>>s;
	repn(i,n) scanf("%d",&a[i]);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	rep(i,100005)rep(j,105) dist[i][j] = INF;
	queue<P>que;
	repn(i,n){
		dist[i][a[i]] = 0;
		que.push(mp(i,a[i]));
	}
	while(!que.empty()){
		P p = que.front(); que.pop();
		if(used[p.fi][p.sc]) continue;
		used[p.fi][p.sc] = true;
		rep(i,edge[p.fi].size()){
			int x = edge[p.fi][i];
			if(!used[x][p.sc] && dist[x][p.sc] > dist[p.fi][p.sc]+1){
				dist[x][p.sc] = dist[p.fi][p.sc]+1;
				que.push(mp(x,p.sc));
			}
		}
	}
	for(int i=1;i<=n;i++){
		priority_queue<int>ans;
		int ret = 0;
		for(int j=1;j<=k;j++){
			ret += dist[i][j];
			ans.push(dist[i][j]);
			if(ans.size() > s){
				ret -= ans.top();
				ans.pop();
			}
		}
		printf("%d ",ret);
	}
	cout<<endl;
}