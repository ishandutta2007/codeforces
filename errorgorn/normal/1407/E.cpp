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

int n,m;
vector<ii> al[500005];
int w[2][500005];
priority_queue<ii,vector<ii>,greater<ii> > pq;

int state[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		al[b].push_back(ii(a,c));
	}
	
	memset(state,-1,sizeof(state));
	memset(w,63,sizeof(w));
	w[0][n]=w[1][n]=0;
	pq.push(ii(max(w[0][n],w[1][n]),n));
	
	int node,weight;
	while (!pq.empty()){
		tie(weight,node)=pq.top(); pq.pop();
		//cout<<weight<<" "<<node<<endl;
		
		if (state[node]!=-1) continue;
		
		state[node]=w[0][node]<w[1][node];
		w[0][node]=max(w[0][node],w[1][node]);
		
		for (auto &it:al[node]){
			if (state[it.fi]!=-1) continue;
			w[it.se][it.fi]=min(w[it.se][it.fi],w[0][node]+1);
			
			int nw=max(w[0][it.fi],w[1][it.fi]);
			if (nw<1e9) pq.push(ii(nw,it.fi));
		}
	}
	
	rep(x,1,n+1) if (state[x]==-1) state[x]=w[0][x]<w[1][x];
	if (max(w[0][1],w[1][1])<1e9) cout<<max(w[0][1],w[1][1])<<endl;
	else cout<<"-1"<<endl;
	rep(x,1,n+1) cout<<state[x];
}