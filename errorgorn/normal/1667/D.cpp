// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
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

int n;
vector<ii> al[200005];
ii edges[200005];
vector<int> rem[200005];
int cnt[200005];

bool ok;

int dfs(int i,int p,int p2){
	vector<int> v[2];
	
	for (auto it:al[i]){
		if (it.fi==p) continue;
		v[dfs(it.fi,i,it.se)].pub(it.se);
		if (!ok) return 0;
	}
	
	int tot=sz(al[i]);
	int odd=(tot+1)/2,even=tot/2;
	
	int val;
	if (p!=-1){
		if (sz(v[0])==even) v[1].pub(p2),val=1;
		else v[0].pub(p2),val=0;
	}
	
	if (sz(v[0])!=even){
		ok=false;
		return 0;
	}
	
	rep(x,0,tot-1){
		int idx1=x/2,idx2=(x+1)/2;
		
		if (x%2==1) swap(v[0],v[1]);
		rem[v[0][idx2]].pub(v[1][idx1]);
		cnt[v[1][idx1]]++;
		if (x%2==1) swap(v[0],v[1]);
	}
	
	return val;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,1,n+1) al[x].clear();
		rep(x,1,n+1) rem[x].clear();
		rep(x,1,n+1) cnt[x]=0;
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub({b,x});
			al[b].pub({a,x});
			
			edges[x]={a,b};
		}
		
		ok=true;
		dfs(1,-1,-1);
		
		if (ok){
			cout<<"YES"<<endl;
			vector<int> v;
			rep(x,1,n) if (cnt[x]==0) v.pub(x);
			
			while (!v.empty()){
				int u=v.back(); v.pob();
				cout<<edges[u].fi<<" "<<edges[u].se<<endl;
				
				for (auto it:rem[u]){
					cnt[it]--;
					if (cnt[it]==0) v.pub(it);
				}
			}
		}
		else{
			cout<<"NO"<<endl;
		}
	}
}