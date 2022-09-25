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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> al[100005];
int num[100005];

vector<ii> edges;
vector<int> al2[100005];
bool vis[100005];

vector<int> extra;

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
	}
	
	if (p!=-1){
		if (num[i]==2 || num[p]==2){
			edges.pub(ii(i,p));
		}
		else{
			num[i]++;
			num[p]++;
			
			al2[i].pub(p);
			al2[p].pub(i);
		}
	}
}

void dfs2(int i){
	vis[i]=true;
	if (sz(al2[i])==1) extra.pub(i);
	if (sz(al2[i])==0) extra.pub(i),extra.pub(i);
	
	for (auto &it:al2[i]) if (!vis[it]) dfs2(it);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,0,n+5){
			al[x].clear();
			al2[x].clear();
			num[x]=0;
			vis[x]=false;
		}
		edges.clear();
		extra.clear();
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		dfs(1,-1);
		rep(x,1,n+1) if (!vis[x]) dfs2(x);		
		
		cout<<sz(edges)<<endl;
		rep(x,0,sz(edges)){
			cout<<edges[x].fi<<" "<<edges[x].se<<" "<<extra[x*2+1]<<" "<<extra[x*2+2]<<endl;
		}
	}
}