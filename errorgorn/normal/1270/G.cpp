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
int arr[1000005];
vector<int> al[1000005];
bool vis[1000005];

vector<int> ans;
int dfs(int i){
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (!vis[it]){
			int temp=dfs(it);
			if (temp==1){
				if (ans.front()==i) temp=2;
				else ans.push_back(i);
			}
			
			if (temp) return temp;
		}
		else{
			ans.push_back(it);
			ans.push_back(i);
			return 1;
		}
	}
	
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,0,n){
			al[x].clear();
			vis[x]=false;	
		}
		
		bool ok=false;
		
		rep(x,0,n){
			cin>>arr[x];
			if (!ok && arr[x]==0){
				cout<<1<<endl<<x+1<<endl;
				ok=true;
			}
			
			arr[x]=x-arr[x];
			
			al[x].push_back(arr[x]);
		}
		
		if (ok) continue;
		
		ans.clear();
		dfs(1);
		
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it+1<<" ";
		cout<<endl;
	}
}