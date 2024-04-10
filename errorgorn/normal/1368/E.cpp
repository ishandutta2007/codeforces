/*













*/

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
vector<int> al[200005];
int state[200005];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		
		rep(x,1,n+1){
			al[x].clear();
			state[x]=0;
		}
		ans.clear();
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].push_back(b);
		}
		
		rep(x,1,n+1){
			if (state[x]==0){
				for (auto &it:al[x]) if (state[it]==0){
					state[it]=1;
				}
			}
			else if (state[x]==1){
				for (auto &it:al[x]) if (state[it]!=2){
					state[it]=2;
					ans.push_back(it);
				}
			}
		}
		
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it<<" ";
		cout<<endl;
	}
	
}