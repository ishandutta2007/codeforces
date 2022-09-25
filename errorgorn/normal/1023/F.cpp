//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct ufds{
	int p[500005];
	
	ufds(){
		rep(x,0,500005) p[x]=x;
	}
	
	int parent(int i){
		return (p[i]==i?i:p[i]=parent(p[i]));
	}
	
	void unions(int i,int j){
		i=parent(i),j=parent(j);
		p[i]=j;
	}
} dsu=ufds();

int n,k,m;
vector<int> al[500005];
int p[500005];
int depth[500005];

void dfs(int i){
	for (auto &it:al[i]){
		if (it==p[i]) continue;
		
		depth[it]=depth[i]+1;
		p[it]=i;
		dfs(it);
	}
}

vector<iii> queries;
vector<ii> dummy;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>m;
	
	int a,b,c;
	rep(x,0,k){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
		
		dsu.unions(a,b);
	}
	
	rep(x,0,m){
		cin>>a>>b>>c;
		
		if (dsu.parent(a)!=dsu.parent(b)){
			al[a].push_back(b);
			al[b].push_back(a);
			
			dsu.unions(a,b);
			
			dummy.push_back(ii(a,b));
		}
		
		queries.push_back(iii(ii(a,b),c));
	}
	
	p[1]=-1;
	dfs(1);
	
	dsu=ufds();
	
	for (auto &it:dummy){
		if (p[it.fi]==it.se){
			dsu.p[it.fi]=it.se;
		}
		else{
			dsu.p[it.se]=it.fi;
		}
	}
	
	int used=0;
	ll ans=0;
	
	for (auto &it:queries){
		a=dsu.parent(it.fi.fi),b=dsu.parent(it.fi.se);
		
		while (a!=b){
			if (depth[a]<depth[b]) swap(a,b);
			
			ans+=it.se;
			dsu.p[a]=p[a];
			a=dsu.parent(a);
			used++;
		}
	}
	
	if (used!=k) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}