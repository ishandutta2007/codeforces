#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
const ll mod = 1000000007;
typedef pair<int,int> P;
int n,m;
vector<int>edge[100005];
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
bitset<100005>B;
struct uf{
	int par[100005];
	void init(){ rep(i,100005)par[i]=i; }
	int find(int x){
		if(x==par[x]) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x,int y){
		x = find(x); y = find(y); if(x == y) return;
		par[x] = y;
	}
}kaede;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){int a,b; scanf("%d%d",&a,&b);
	edge[a].pb(b); edge[b].pb(a);}
	P mn = P(1000000,1000000);
	repn(i,n) mn = min(mn,P(edge[i].size(),i));
	repn(i,n) sort(edge[i].begin(),edge[i].end());
	repn(i,n) B[i] = 1;
	int x = mn.sc;
	vector<int>vec;
	for(int i=0;i<edge[x].size();i++){
		vec.pb(edge[x][i]); B[edge[x][i]] = 0;
	}
	//cout << x << endl;
	kaede.init();
	for(int i=0;i<vec.size();i++){
		bitset<100005>xx;
		repn(j,n) xx[j] = 1;
		int k = vec[i]; xx[k] = 0;
		rep(j,edge[k].size()) xx[edge[k][j]] = 0;
		if( (B&xx).count() ) kaede.unite(x,k);
	}
	rep(i,vec.size()) rep(j,vec.size()){
		if(i >= j) continue;
		int a = vec[i], b = vec[j];
		int pt = lower_bound(edge[a].begin(),edge[a].end(),b)-edge[a].begin();
		if(pt < edge[a].size() && edge[a][pt] == b){
		}
		else{
			kaede.unite(a,b);
		}
	}
	int sz = (kaede.find(x) == x);
	rep(i,vec.size()) sz += (kaede.find(vec[i]) == vec[i]);
	cout << sz-1 << endl;
}