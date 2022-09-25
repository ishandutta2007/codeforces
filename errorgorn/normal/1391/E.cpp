// Super Idol
//    
//  
//    
//  105C
// 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<int> al[500005];
vector<int> depth[500005];
int d[500005];
int p[500005];

int chain;

void dfs(int i){
	depth[d[i]].pub(i);
	if (d[i]>=(n+1)/2) chain=i;
	
	for (auto &it:al[i]){
		if (d[it]==-1){
			d[it]=d[i]+1;
			p[it]=i;
			dfs(it);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		
		rep(x,1,n+1){
			al[x].clear();
			depth[x].clear();
		}
		chain=-1;
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		rep(x,1,n+1) d[x]=-1;
		d[1]=1;
		p[1]=-1;
		
		dfs(1);
		
		if (chain!=-1){
			vector<int> ans={chain};
			while (ans.back()!=1) ans.pub(p[ans.back()]);
			
			cout<<"PATH"<<endl;
			cout<<sz(ans)<<endl;
			for (auto &it:ans) cout<<it<<" "; cout<<endl;
		}
		else{
			cout<<"PAIRING"<<endl;
			vector<ii> ans;
			rep(x,1,n+1){
				while (sz(depth[x])>=2){
					ans.pub({depth[x][sz(depth[x])-2],depth[x][sz(depth[x])-1]});
					depth[x].pob();
					depth[x].pob();
				}
			}
			
			cout<<sz(ans)<<endl;
			for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
		}
	}
}