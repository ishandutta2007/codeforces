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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=1000000007;

int n;
int arr[200005];
vector<int> al[200005];
set<int> untaken[200005];
set<int> taken[200005];
bool h[200005];
int init=0;

map<int,int> cnt;

void rage(){
	cout<<"0"<<endl;
	exit(0);
}

void dfs(int i,int p){
	bool used=false;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		if (taken[it].count(arr[i])) rage();
		if (untaken[it].count(arr[i])){
			if (used) rage();
			used=true;
			
			init++;
			h[it]=true;
			if (untaken[i].count(arr[i]) || taken[i].count(arr[i])) rage();
			untaken[it].erase(arr[i]);
			taken[i].insert(arr[i]);
		}
		
		if (sz(untaken[i])+sz(taken[i])<sz(untaken[it])+sz(taken[it])){
			swap(untaken[i],untaken[it]);
			swap(taken[i],taken[it]);
		}
		
		//cout<<"??"<<i<<" "<<it<<endl;
		
		for (auto &it2:untaken[it]){
			if (taken[i].count(it2)) rage();
			untaken[i].insert(it2);
		}
		
		for (auto &it2:taken[it]){
			if (untaken[i].count(it2) || taken[i].count(it2)) rage();
			taken[i].insert(it2);
		}
	}
	
	if (!used) untaken[i].insert(arr[i]);
	//cout<<"debug: "<<i<<endl;
}

int ans=0;
void dfs2(int i,int p,int v){
	if (cnt[arr[i]]>=2) v++;
	if (h[i]) v-=2;
	if (v==0) ans++;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs2(it,i,v);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
		
	cin>>n;
	rep(x,1,n+1){
		cin>>arr[x];
		cnt[arr[x]]++;
	}
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	//for (auto &it:untaken[1]) cout<<it<<" "; cout<<endl;
	//for (auto &it:taken[1]) cout<<it<<" "; cout<<endl;
	
	dfs2(1,-1,init);
	
	cout<<ans<<endl;
}