//
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
vector<int> al2[500005];

int ans1[500005];
int ans2[500005];

bool vis[500005];
bool used[500005];

int IDX;

void dfs(int i,int p,int rp){
	vis[i]=true;
	vector<int> child;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i,rp);
		if (!used[it]) child.pub(it);
	}
	
	if (!child.empty()){
		if (p==rp) child.pub(rp);
		
		ans1[i]=IDX;
		for (auto &it:child){
			ans2[it]=IDX;
			IDX++;
			ans1[it]=IDX;
		}
		ans2[i]=IDX;
		IDX++;
		
		used[i]=true;
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
		
		rep(x,1,n+1) al[x].clear(),al2[x].clear();
		rep(x,1,n+1) al[x].pub(x);
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		rep(x,1,n+1) sort(all(al[x]));
		
		rep(x,1,n+1) if (sz(al[x])!=n && al2[x].empty()){
			rep(y,0,n){
				if (sz(al[x])<=y || al[x][y]!=y+1){
					al2[x].pub(y+1);
					al2[y+1].pub(x);
					break;
				}
			}
		}
		
		rep(x,1,n+1) swap(al[x],al2[x]);
		
		// rep(x,1,n+1){
			// cout<<x<<": "; for (auto &it:al[x]) cout<<it<<" "; cout<<endl;
		// }
		
		IDX=1;
		rep(x,1,n+1) vis[x]=used[x]=false;
		rep(x,1,n+1) ans1[x]=ans2[x]=-1;
		
		rep(x,1,n+1) if (sz(al[x])==1 && !vis[x]){
			dfs(x,-1,x);
		}
		
		rep(x,1,n+1) if (ans1[x]==-1) ans1[x]=ans2[x]=IDX++;
		
		rep(x,1,n+1) cout<<ans1[x]<<" "; cout<<endl;
		rep(x,1,n+1) cout<<ans2[x]<<" "; cout<<endl;
	}
}