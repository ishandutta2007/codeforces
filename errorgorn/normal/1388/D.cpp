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

int n;
ll arr[200005];
vector<int> al[200005];
vector<int> trail[200005];
bool par[200005];

ll ans=0;
deque<int> fin;

void dfs(int i,int p){
	for (auto &it:al[i]) if (it!=p){
		dfs(it,i);
		arr[i]+=arr[it];
		
		if (sz(trail[i])<sz(trail[it])) swap(trail[i],trail[it]);
		
		for (auto &it2:trail[it]){
			trail[i].push_back(it2);
		}
	}
	
	trail[i].push_back(i);
	ans+=arr[i];
	
	if (arr[i]<0){
		arr[i]=0;
		reverse(all(trail[i]));
		for (auto &it:trail[i]){
			fin.push_front(it);
		}
		trail[i].clear();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1){
		int t;
		cin>>t;
		
		if (t!=-1) al[t].push_back(x);
		else par[x]=true;
	}
	
	rep(x,1,n+1) if (par[x]){
		dfs(x,-1);
		
		reverse(all(trail[x]));
		for (auto &it:trail[x]){
			fin.push_front(it);
		}
	}
	
	cout<<ans<<endl;
	for (auto &it:fin) cout<<it<<" ";
}