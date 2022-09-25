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
int arr[100005];
int brr[100005];
ii ff[200005];

vector<int> pos[100005];
queue<int> proc;
bool used[200005];

vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	rep(x,1,n+1){
		cin>>arr[x];
	}
	
	rep(x,0,m){
		cin>>ff[x].fi>>ff[x].se;
		brr[ff[x].fi]++,brr[ff[x].se]++;
		pos[ff[x].fi].push_back(x);
		pos[ff[x].se].push_back(x);
	}
	
	rep(x,1,n+1) if (arr[x]>=brr[x]){
		proc.push(x);
	}
	
	while (!proc.empty()){
		int curr=proc.front();
		proc.pop();
		
		for (auto &it:pos[curr]) if (!used[it]){
			ans.push_back(it);
			used[it]=true;
			brr[ff[it].fi]--;
			brr[ff[it].se]--;
			
			if (arr[ff[it].fi]==brr[ff[it].fi]) proc.push(ff[it].fi);
			if (arr[ff[it].se]==brr[ff[it].se]) proc.push(ff[it].se);
		}
	}
	
	if (sz(ans)!=m){
		cout<<"DEAD"<<endl;
	}
	else{
		cout<<"ALIVE"<<endl;
		reverse(all(ans));
		for (auto &it:ans) cout<<it+1<<" ";
	}
}