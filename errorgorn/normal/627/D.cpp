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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
int arr[200005];
vector<int> al[200005];

bool bad[200005];
int w[200005];
int d[200005];
bool vis[200005];
vector<int> proc;

int ans;
int dfs(int i){
	vis[i]=true;
	
	vector<int> child={0,0};
	for (auto &it:al[i]) if (!bad[it] && !vis[it]){
		child.push_back(dfs(it));
	}
	
	sort(all(child));
	reverse(all(child));
	
	ans=max(ans,w[i]+child[0]+child[1]);
	return child[0]+w[i];
}

bool test(int i){
	ans=0;
	rep(x,1,n+1){
		bad[x]=(arr[x]<i);
		w[x]=1;
		d[x]=sz(al[x]);
		vis[x]=false;
	}
	
	rep(x,1,n+1) if (d[x]==1 && !bad[x]){
		proc.push_back(x);
	}
	
	while (!proc.empty()){
		int node=proc.back();
		proc.pop_back();
		
		for (auto &it:al[node]) if (!bad[it]){
			bad[node]=true;
			w[it]+=w[node];
			d[it]--;
			
			if (d[it]==1){
				proc.push_back(it);
			}
		}
	}
	
	rep(x,1,n+1) if (!bad[x] && !vis[x]){
		dfs(x);
	}
	return ans>=k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	int lo=1,hi=1000005,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (test(mi)) lo=mi;
		else hi=mi;
	}
	
	cout<<lo<<endl;
}