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

const ll INF=1e18;

int n,m;
ll arr[10005];
ll memo[10005][1005];
ll g,r;

deque<ii> dq; //0-1 bfs time owo

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	rep(x,0,m) cin>>arr[x];
	cin>>g>>r;
	
	sort(arr,arr+m);
	
	memset(memo,1,sizeof(memo));
	
	memo[0][0]=0;
	dq.push_front(ii(0,0));
	
	int node,state;
	int nstate;
	while (!dq.empty()){
		node=dq.front().fi,state=dq.front().se;
		dq.pop_front();
		
		if (node!=0){
			nstate=state+arr[node]-arr[node-1];
			
			if (nstate<g && memo[node-1][nstate]>memo[node][state]){
				memo[node-1][nstate]=memo[node][state];
				dq.push_front(ii(node-1,nstate));
			}
			else if (nstate==g && memo[node-1][0]>memo[node][state]+1){
				memo[node-1][0]=memo[node][state]+1;
				dq.push_back(ii(node-1,0));
			}
		}
		if (node!=m-1){
			nstate=state+arr[node+1]-arr[node];
			
			if (nstate<g && memo[node+1][nstate]>memo[node][state]){
				memo[node+1][nstate]=memo[node][state];
				dq.push_front(ii(node+1,nstate));
			}
			else if (nstate==g && memo[node+1][0]>memo[node][state]+1){
				memo[node+1][0]=memo[node][state]+1;
				dq.push_back(ii(node+1,0));
			}
		}
	}
	
	ll ans=INF;
	
	rep(x,0,g) if (memo[m-1][x]!=72340172838076673){
		if (x==0) ans=min(ans,memo[m-1][x]*(g+r)-r);
		else ans=min(ans,memo[m-1][x]*(g+r)+x);
	}
	
	cout<<(ans==INF?-1:ans)<<endl;
}