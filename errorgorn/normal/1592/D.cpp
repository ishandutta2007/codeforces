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
vector<int> al[1005];

int IDX=1;

int pp[1005];
int pre[1005];

void dfs(int i,int p){
	pp[i]=p;
	pre[IDX++]=i;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
	}
}

int query(vector<int> v){
	set<int> s;
	for (auto &it:v){
		s.insert(it);
		s.insert(pp[it]);
	}
	
	cout<<"? "<<sz(s)<<" "; for (auto &it:s) cout<<it<<" "; cout<<endl;
	
	int temp;
	cin>>temp;
	
	return temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	vector<int> v;
	rep(x,2,n+1) v.pub(pre[x]);
	
	int val=query(v);
	
	while (sz(v)!=1){
		vector<int> l,r;
		
		rep(x,0,sz(v)/2) l.pub(v[x]);
		rep(x,sz(v)/2,sz(v)) r.pub(v[x]);
		
		if (val==query(l)) v=l;
		else v=r;
	}
	
	cout<<"! "<<v[0]<<" "<<pp[v[0]]<<endl;
}