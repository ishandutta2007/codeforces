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
int a[35];
struct edge
{
	int to,cap,rev;
};
vector<edge>G[5005];
bool used[5005];

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0)
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0;
	while(1)
	{ 
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(!f) return flow;
		flow+=f;
	}
}
bool dp[35][65][2005];
int main(){
	cin >> n;
	repn(i,n) cin>>a[i];
	sort(a+1,a+n+1);
	dp[0][0][0] = 1;
	repn(i,n){
		for(int j=0;j<61;j++){
			for(int k=0;k<2005;k++){
				if(!dp[i-1][j][k] && !dp[i][j][k])continue;
				if((j+1)*j/2 > k+a[i]) continue;
				dp[i][j+1][k+a[i]] = 1;
			}
		}
	}
	for(int i=1;i<=61;i++){
		if(dp[n][i][i*(i-1)/2]){//cout<<i<<endl;
			int ans[65][65]={};
			vector<int>vi;
			int up = n,cur = i,cur2 = i*(i-1)/2;
			while(up){
				while(cur && cur2>=a[up] && (dp[up-1][cur-1][cur2-a[up]] || dp[up][cur-1][cur2-a[up]])){
					vi.pb(a[up]);cur--;cur2-=a[up];
					if(!dp[up][cur][cur2]) break;
				}
				up--;
			}
			int A = i;
			int nxt = 2;
			for(int x=0;x<A;x++) for(int y=x+1;y<A;y++){
				add_edge(0,nxt,1);
				add_edge(nxt,2000+x,1);
				add_edge(nxt,2000+y,1);nxt++;
			}
			for(int x=0;x<A;x++) add_edge(2000+x,1,vi[x]);
			assert(max_flow(0,1) == A*(A-1)/2);
			nxt = 2;
			for(int x=0;x<A;x++) for(int y=x+1;y<A;y++){
				for(int j=0;j<G[nxt].size();j++){
					if(G[nxt][j] .to == 2000+x && G[nxt][j].cap == 0){
						ans[x][y] = 1;
					}
					else if(G[nxt][j] .to == 2000+y && G[nxt][j].cap == 0){
						ans[y][x] = 1;
					}
				}
				nxt++;
			}
			cout<<A<<endl;
			for(int i=0;i<A;i++) {for(int j=0;j<A;j++) cout<<ans[i][j]; cout<<endl;}
			return 0;
		}
	}
	cout<<-1<<endl;
}