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
int arr[300005];
int brr[300005];
int w[300005];
int p[300005];
int dist[300005];

set<int> s;
queue<int> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) cin>>brr[x];
	
	memset(w,-1,sizeof(w));
	
	w[n]=0;
	rep(x,0,n) s.insert(x);
	q.push(n);
	
	while (!q.empty()){
		int u=q.front();
		q.pop();
		
		int v=u+brr[u];
		
		while (s.lb(v-arr[v])!=s.end() && *s.lb(v-arr[v])<=v){
			auto it=*s.lb(v-arr[v]);
			w[it]=w[u]+1;
			q.push(it);
			s.erase(it);
			
			p[it]=u;
			dist[it]=it;
		}
	}
	
	//rep(x,0,n+1) cout<<w[x]<<" "; cout<<endl;
	
	if (w[0]==-1){
		cout<<"-1"<<endl;
		return 0;
	}
	
	vector<int> ans;
	int curr=0;
	while (curr!=n){
		ans.pub(dist[curr]);
		curr=p[curr];
	}
	
	reverse(all(ans));
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it<<" "; cout<<endl;
}