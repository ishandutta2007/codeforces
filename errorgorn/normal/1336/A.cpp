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

int n,k;
vector<int> al[200005];

int pa[200005];
int depth[200005];
int sz[200005];
void dfs(int i,int p){
	pa[i]=p;
	sz[i]=1;

	for (auto &it:al[i]){
		if (it==p) continue;
		
		depth[it]=depth[i]+1;
		dfs(it,i);
		sz[i]+=sz[it];
	}
}

priority_queue<ii> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfs(1,-1);
	
	pq.push(ii(sz[1]-depth[1]-1,1));
	
	k=n-k;
	
	ll ans=0;
	
	while (k--){
		ans+=pq.top().first;
		int node=pq.top().second;
		pq.pop();
		
		for (auto &it:al[node]){
			if (it==pa[node]) continue;
			
			pq.push(ii(sz[it]-depth[it]-1,it));
		}
	}
	
	cout<<ans<<endl;
}