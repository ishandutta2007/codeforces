#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
typedef pair<int,int> P;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
const ll mod = 1000000007;
int n,m;
vector<int>G[2000005];
bool used[2000005];
void dfs(int x){
	if(used[x]) return; used[x] = 1;
	rep(i,G[x].size()){
		int go = G[x][i];
		if(go <= n) go += n; else go -= n;
		dfs(go);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	repn(i,2*n) G[i].clear();
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		if( a== b) continue;
		b += n;
		G[a].pb(b); G[b].pb(a);
	}
	vector<int>vec; vec.resize(n);
	repn(i,n) vec[i-1] = i;
	random_shuffle(vec.begin(),vec.end());
	rep(i,1){
		if(i >= n) break;
		int x = vec[i];
		//human
		repn(i,2*n) used[i] = 0;
		dfs(x);
		vector<int>h,c;
		repn(i,n){
			if(!used[i]) c.pb(i);
			else h.pb(i);
		}
		if(h.size() && c.size()){
			puts("Yes");
			printf("%d %d\n",h.size(),c.size());
			rep(i,h.size()) printf("%d ",h[i]); puts("");
			rep(i,c.size()) printf("%d ",c[i]); puts("");
			return;
		}
		//cat
		repn(i,2*n) used[i] = 0;
		dfs(x+n);
		h.clear(); c.clear();
		repn(i,n){
			if(!used[i+n]) h.pb(i);
			else c.pb(i);
		}
		if(h.size() && c.size()){
			puts("Yes");
			printf("%d %d\n",h.size(),c.size());
			rep(i,h.size()) printf("%d ",h[i]); puts("");
			rep(i,c.size()) printf("%d ",c[i]); puts("");
			return;
		}
	}
	puts("No");
}
int main(){
	int t; scanf("%d",&t);
	while(t--){
		solve();
	}
}