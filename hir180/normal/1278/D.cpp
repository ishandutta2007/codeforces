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
vector<P>vec;
map<int,int>M;
vector<int>edge[500005];
bool used[500005];
void dfs(int v){
	if(used[v]) return ; used[v] = 1;
	rep(i,edge[v].size()){
		int to = edge[v][i];
		if(!used[to]) dfs(to);
	}
}
int main(){
	scanf("%d",&n);
	repn(i,n){
		int a,b; scanf("%d%d",&a,&b); vec.pb(P(a,b));
	}
	sort(vec.begin(),vec.end());
	int cnt = 0;
	rep(i,n){
		for(auto it=M.lower_bound(-vec[i].sc);it!=M.end();it++){
			int a = -1*(*it).fi;
			if(a < vec[i].fi) break;
			cnt++;
			if(cnt == n){
				puts("NO"); return 0;
			}
			edge[i].pb((*it).sc);
			edge[(*it).sc].pb(i);
			//cout << (*it).sc << " " << i << endl;
		}
		M[-vec[i].sc] = i;
	}
	if(cnt != n-1) {puts("NO"); return 0;}
	dfs(0);
	rep(i,n){
		if(!used[i]){ puts("NO"); return 0;}
	}
	puts("YES");
}