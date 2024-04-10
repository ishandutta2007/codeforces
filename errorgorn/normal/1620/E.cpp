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

int q;
vector<int> arr;
map<int,int> id;
int p[1000005];
int col[1000005];

int dfs(int i){
	if (col[i]==-1) return col[i]=dfs(p[i]);
	else return col[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>q;
	int IDX=0;
	
	int a,b;
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a;
			if (!id.count(a)) id[a]=IDX++;
			arr.pub(id[a]);
		}
		else{
			cin>>a>>b;
			if (a==b) continue;
			
			if (!id.count(a)) id[a]=IDX++;
			if (!id.count(b)) id[b]=IDX++;
			p[id[a]]=id[b];
			id.erase(a);
		}
	}
	
	memset(col,-1,sizeof(col));
	for (auto [a,b]:id) col[b]=a;
	
	rep(x,0,sz(arr)) cout<<dfs(arr[x])<<" "; cout<<endl;
}