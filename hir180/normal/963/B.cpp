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
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>edge[200005];
int dep[200005],deg[200005];
bool used[200005];
void dfs(int v,int u,int d){
	dep[v] = d;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,d+1);
	}
}

int main(){
	cin>>n; int r = -1;
	repn(i,n){
		int a; cin>>a;
		edge[a].pb(i);
		edge[i].pb(a);
		if(a==0) r = i;
	}
	if(n%2 == 0){
		puts("NO");
		return 0;
	}
	else{
		puts("YES");
		priority_queue<P>que;
		dfs(0,-1,0);
		for(int i=1;i<=n;i++){
			deg[i] = edge[i].size();
			if(i==r)deg[i]--;
			if(deg[i]%2==0){
				que.push(mp(dep[i],i));
			}
		}
		vector<int>vec;
		while(!que.empty()){
			P p = que.top(); que.pop();
			if(deg[p.sc] <= 0 || deg[p.sc]%2 == 1) continue;
			deg[p.sc]=0; vec.pb(p.sc); used[p.sc] = 1; //cout<<p.sc<<endl;
			for(int i=0;i<edge[p.sc].size();i++){
				int to = edge[p.sc][i];
				deg[to]--;
				if(deg[to]>0 && deg[to]%2==0) que.push(mp(dep[to],to));
			}
		}
		for(int i=1;i<=n;i++) if(!used[i]) vec.pb(i);
		for(int i=0;i<n;i++) printf("%d\n",vec[i]);
	}
}