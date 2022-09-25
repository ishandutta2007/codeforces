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
 
ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}
 
#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
int n;
int arr[100005];
vector<int> al[100005];
 
ll best[100005];
ii memo[100005];
 
vector<ii> path={ii(0,-1)};
vector<ii> nopath={ii(0,-2),ii(0,-2)};
vector<ll> ropes={0,0};
	
ll ans=0;
void dfs(int i,int p){ //pair contains pair of added path and no added path
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
	}
	
	path={ii(0,-1)}; //path means that path that is rooted at that node and there is another path at the bottom
	nopath={ii(0,-2),ii(0,-2)}; //nopath means a path that is rooted at that node
	ropes={0,0}; //rope means some path not containing root
	
	//now we need to combine to find best path, no path and root
	
	for (auto &it:al[i]){
		if (it==p) continue;
 
		best[i]=max(best[i],best[it]);
		
		path.push_back(ii(memo[it].first,it));
		nopath.push_back(ii(memo[it].second,it));
	}
	
	sort(all(path),[](ii i,ii j){return i>j;});
	sort(all(nopath),[](ii i,ii j){return i>j;});
	
	ll pn=arr[i]+path[0].first;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		pn=max(pn,best[it]);
		
		ans=max(ans,arr[i]+best[it]+
			(nopath[0].second==it?0:nopath[0].first)+
			(nopath[1].second==it?0:nopath[1].first)+
			((nopath[0].second==it || nopath[1].second==it)?nopath[2].first:0)
		);
		
		ropes.push_back(best[it]);
		
		pn=max(pn,arr[i]+best[it]+(nopath[0].second==it?nopath[1].first:nopath[0].first));
	}
	
	sort(all(ropes),[](ll i,ll j){return i>j;});
	
	ans=max(ans,ropes[0]+ropes[1]);
	
	if (path[0].second!=nopath[0].second) ans=max(ans,arr[i]+path[0].first+nopath[0].first);
	else ans=MAX(ans,arr[i]+path[0].first+nopath[1].first,arr[i]+path[1].first+nopath[0].first);
	
	best[i]=max(best[i],arr[i]+nopath[0].first+nopath[1].first);
	
	
	
	//cout<<i<<" "<<pn<<" "<<arr[i]+nopath[0].first<<endl;
	memo[i]=ii(pn,arr[i]+nopath[0].first);
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	dfs(1,-1);
	
	cout<<ans<<endl;
}