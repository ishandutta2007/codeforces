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
ll arr[100][100];
ii val[100];
vector<int> minion;

vector<int> ans;
ll best;

bool used[100];

void test(int i){
	memset(arr,254,sizeof(arr));
	arr[0][0]=0;
	
	rep(x,0,n){
		arr[x+1][0]=arr[x][0];
		rep(y,1,k){
			if (minion[x]==i) arr[x+1][y]=arr[x][y];
			else arr[x+1][y]=max(arr[x][y],arr[x][y-1]-(k-y)*val[minion[x]].se+val[minion[x]].fi);
		}
	}
	
	vector<int> res;
	
	int curr=k-1;
	rep(x,n,0){
		if (arr[x+1][curr]!=arr[x][curr]){
			curr--;
			res.push_back(minion[x]);
		}
	}
	
	reverse(all(res));
	res.push_back(i);
	
	if (arr[n][k-1]+val[i].fi>best){
		best=arr[n][k-1]+val[i].fi;
		ans=res;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		minion.clear();
		
		cin>>n>>k;
		
		ll extra=0;
		rep(x,1,n+1){
			cin>>val[x].fi>>val[x].se;
			minion.push_back(x);
			extra+=val[x].se;
		}
		
		sort(all(minion),[](int i,int j){
			return val[i].se<val[j].se; 
		});
		
		best=-1e18;
		rep(x,1,n+1) test(x);
		
		memset(used,false,sizeof(used));
		
		for (auto &it:ans) used[it]=true;
		
		cout<<n*2-k<<endl;
		rep(x,0,sz(ans)-1) cout<<ans[x]<<" ";
		rep(x,1,n+1) if (!used[x]) cout<<x<<" "<< -x<<" ";
		cout<<ans[sz(ans)-1]<<endl;
	}
}