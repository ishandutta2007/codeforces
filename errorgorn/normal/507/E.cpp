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

int n,m;
int w1[100005];
int w2[100005];
int pa[100005];

vector<ii> al[100005];
vector<iii> edges;
vector<iii> ans;

set<ii> bad;

queue<int> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		
		al[a].push_back(ii(b,c));
		al[b].push_back(ii(a,c));
		edges.push_back(iii(ii(a,b),c));
	}
	
	memset(w1,63,sizeof(w1));
	
	w1[1]=0;
	q.push(1);
	while (!q.empty()){
		int node=q.front();
		q.pop();
		
		for (auto &it:al[node]){
			if (w1[it.fi]>w1[node]+1){
				w1[it.fi]=w1[node]+1;
				w2[it.fi]=w2[node]+it.se;
				pa[it.fi]=node;
				q.push(it.fi);
			}
			else if (w1[it.fi]==w1[node]+1 && w2[it.fi]<w2[node]+it.se){
				w2[it.fi]=w2[node]+it.se;
				pa[it.fi]=node;
			}
		}
	}
	
	int curr=n;
	while (curr!=1){
		bad.insert(ii(curr,pa[curr]));
		bad.insert(ii(pa[curr],curr));
		curr=pa[curr];
	}
	
	for (auto &it:edges){
		if (bad.count(it.fi)){
			if (it.se==0) ans.push_back(it);
		}
		else{
			if (it.se==1) ans.push_back(it);
		}
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans){
		cout<<it.fi.fi<<" "<<it.fi.se<<" "<<(it.se^1)<<endl;
	}
}