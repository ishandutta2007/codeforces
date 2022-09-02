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
int n;
vector<int>go[2000025];
vector<int>edge[1000005];
int a[1000005],ty[1000005];
int dfs(int v){
	if(edge[v].empty()){
	    assert(ty[v] == -1);
		return a[v];
	}
	if(ty[v] == 3){
		for(int i=0;i<edge[v].size();i++){
			int x = dfs(edge[v][i]);
			go[v*2+1].pb(edge[v][i]*2);
			go[v*2].pb(edge[v][i]*2+1);
			return a[v] = 1-x;
		}
	}
	else{
		vector<int>vec;
		for(int i=0;i<edge[v].size();i++){
			int x = dfs(edge[v][i]);
			vec.pb(x);
		}
		if(ty[v] == 0) a[v] = (vec[0]&vec[1]);
		else if(ty[v] == 1) a[v] = (vec[0]|vec[1]);
		else a[v] = (vec[0]^vec[1]);
		for(int i=0;i<edge[v].size();i++){
			if(i == 0){
				int to;
				if(ty[v] == 0) to = (0&vec[1]);
				else if(ty[v] == 1) to = (0|vec[1]);
				else to = (0^vec[1]);
				go[v*2+to].pb(edge[v][i]*2);
				if(ty[v] == 0) to = (1&vec[1]);
				else if(ty[v] == 1) to = (1|vec[1]);
				else to = (1^vec[1]);
				go[v*2+to].pb(edge[v][i]*2+1);
			}
			else{
				int to;
				if(ty[v] == 0) to = (0&vec[0]);
				else if(ty[v] == 1) to = (0|vec[0]);
				else to = (0^vec[0]);
				go[v*2+to].pb(edge[v][i]*2);
				if(ty[v] == 0) to = (1&vec[0]);
				else if(ty[v] == 1) to = (1|vec[0]);
				else to = (1^vec[0]);
				go[v*2+to].pb(edge[v][i]*2+1);
			}
		}
		return a[v];
	}
}
int ans[1000005];
int rev[1000005];
bool used[2000005];
void DFS(int cur){
	if(used[cur]) return;
	int id = cur/2;
	if(rev[id]){
		int zan = cur%2;
		//cout<<id<<" "<<zan<<endl;
		if(a[id] != zan){
			ans[rev[id]] = 0;
		}
	}
	for(int i=0;i<go[cur].size();i++){
		int to = go[cur][i];
		if(used[to]) continue;
		DFS(to);
	}
}
signed main(){
	scanf("%d",&n);
	int cnt = 1;
	for(int i=1;i<=n;i++){
		char st[10]; scanf("%s",&st);
		if(st[0] == 'I'){
			scanf("%d",&a[i]);
			ty[i] = -1;
			rev[i] = cnt;
			ans[cnt++] = 1;
		}
		else{
			if(st[0] == 'A') ty[i] = 0;
			else if(st[0] == 'O') ty[i] = 1;
			else if(st[0] == 'X') ty[i] = 2;
			else if(st[0] == 'N') ty[i] = 3;
			if(ty[i] == 3){
				int k; scanf("%d",&k);
				edge[i].pb(k);
			}
			else{
				int k; scanf("%d",&k);
				edge[i].pb(k);
				scanf("%d",&k);
				edge[i].pb(k);
			}
		}
	}
	dfs(1);
	DFS(2);
	for(int i=1;i<cnt;i++) printf("%d",ans[i]);
	puts("");
}