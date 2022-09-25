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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,a,b,da,db;
vector<int> al[100005];

int goal=b;
int dist;

void find(int i,int p,int d){
	if (i==b) dist=d;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		find(it,i,d+1);
	}
}

int diam;
int dfs(int i,int p){
	vector<int> children={0,0};
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		children.push_back(dfs(it,i)+1);
	}
	
	sort(all(children));
	reverse(all(children));
	
	diam=max(diam,children[0]+children[1]);
	
	return children[0];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>a>>b>>da>>db;
		
		rep(x,1,n+1) al[x].clear();
		
		int u,v;
		rep(x,1,n){
			cin>>u>>v;
			
			al[u].push_back(v);
			al[v].push_back(u);
		}
		
		goal=b;
		find(a,-1,0);
		
		diam=0;
		dfs(1,-1);
		
		//cout<<diam<<" "<<dist<<endl;
		if (da*2>=min(db,diam) || dist<=da){
			cout<<"Alice"<<endl;
		}
		else{
			cout<<"Bob"<<endl;
		}
	}
	
}