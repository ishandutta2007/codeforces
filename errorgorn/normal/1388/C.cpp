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

int n,m;
ll p[100005];
ll h[100005];
ll ps[100005];
ll v[100005];
ll tv[100005];
ll par[100005];
vector<int> al[100005];

void dfs(int i,int pa){
	par[i]=pa;
	ps[i]=p[i];
	for (auto &it:al[i]){
		if (it==pa) continue;
		
		dfs(it,i);
		ps[i]+=ps[it];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,n+1) al[x].clear();
		
		rep(x,1,n+1) cin>>p[x];
		rep(x,1,n+1) cin>>h[x];
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			
			al[a].push_back(b);
			al[b].push_back(a);
		}
		
		dfs(1,-1);
		
		rep(x,1,n+1){
			v[x]=ps[x]-h[x];
		}
		
		bool can=true;
		rep(x,1,n+1){
			if (v[x]%2!=0 || v[x]<0) can=false;
			v[x]/=2;
			//cout<<v[par[x]]-v[x]<<" "<<p[par[x]]-p[x]<<endl;
		}
		
		//our ammo is from people in current node and value of children
		rep(x,1,n+1) tv[x]=p[x];
		rep(x,1,n+1) if (x!=1) tv[par[x]]+=v[x];
		
		rep(x,1,n+1) if (tv[x]<v[x]) can=false;
		
		
		if (can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}