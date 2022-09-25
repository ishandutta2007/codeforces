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
vector<int> al[70000];
int pos[70000];
bool vis[70000];

int id[70000];

int ans[70000];
int col[70000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,0,(1<<n)) al[x].clear();
		rep(x,0,(1<<n)) vis[x]=false;
		
		int a,b;
		rep(x,0,(1<<(n-1))*n){
			cin>>a>>b;
			
			al[a].pub(b);
			al[b].pub(a);
		}
		
		vis[0]=true;
		pos[0]=0;
		
		rep(x,0,n){
			rep(y,0,(1<<n)) id[y]=-1;
			
			int temp=-1;
			rep(y,0,(1<<n)) if (vis[y]){
				for (auto &it:al[y]) if (!vis[it]){
					id[it]=pos[y];
					temp=it;
				}
			}
			
			vector<int> stk={temp};
			vis[temp]=true;
			while (!stk.empty()){
				int u=stk.back(); stk.pob();
				
				pos[u]=id[u]|(1<<x);
				for (auto &it:al[u]) if (!vis[it] && id[it]!=-1){
					vis[it]=true;
					stk.pub(it);
				}
			}
		}
		
		rep(x,0,(1<<n)) ans[pos[x]]=x;
		
		rep(x,0,(1<<n)) cout<<ans[x]<<" "; cout<<endl;
		if (__builtin_popcount(n)==1){
			rep(x,0,(1<<n)){
				int curr=0;
				rep(y,0,n) if (x&(1<<y)) curr^=y;
				col[ans[x]]=curr;
			}
			
			rep(x,0,(1<<n)) cout<<col[x]<<" "; cout<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	
}