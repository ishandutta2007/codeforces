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

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;

double MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
  int n = int(cost.size());

  // construct dual feasible solution
  VD u(n);
  VD v(n);
  for (int i = 0; i < n; i++) {
    u[i] = cost[i][0];
    for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
  }
  for (int j = 0; j < n; j++) {
    v[j] = cost[0][j] - u[0];
    for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
  }
  
  // construct primal solution satisfying complementary slackness
  Lmate = VI(n, -1);
  Rmate = VI(n, -1);
  int mated = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (Rmate[j] != -1) continue;
      if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
		Lmate[i] = j;
		Rmate[j] = i;
		mated++;
		break;
      }
    }
  }
  
  VD dist(n);
  VI dad(n);
  VI seen(n);
  
  // repeat until primal solution is feasible
  while (mated < n) {
    
    // find an unmatched left node
    int s = 0;
    while (Lmate[s] != -1) s++;
    
    // initialize Dijkstra
    fill(dad.begin(), dad.end(), -1);
    fill(seen.begin(), seen.end(), 0);
    for (int k = 0; k < n; k++) 
      dist[k] = cost[s][k] - u[s] - v[k];
    
    int j = 0;
    while (true) {
      
      // find closest
      j = -1;
      for (int k = 0; k < n; k++) {
		if (seen[k]) continue;
		if (j == -1 || dist[k] < dist[j]) j = k;
      }
      seen[j] = 1;
      
      // termination condition
      if (Rmate[j] == -1) break;
      
      // relax neighbors
      const int i = Rmate[j];
      for (int k = 0; k < n; k++) {
		if (seen[k]) continue;
		const double new_dist = dist[j] + cost[i][k] - u[i] - v[k];
		if (dist[k] > new_dist) {
		  dist[k] = new_dist;
		  dad[k] = j;
		}
      }
    }
    
    // update dual variables
    for (int k = 0; k < n; k++) {
      if (k == j || !seen[k]) continue;
      const int i = Rmate[k];
      v[k] += dist[k] - dist[j];
      u[i] -= dist[k] - dist[j];
    }
    u[s] += dist[j];
    
    // augment along path
    while (dad[j] >= 0) {
      const int d = dad[j];
      Rmate[j] = Rmate[d];
      Lmate[Rmate[j]] = j;
      j = d;
    }
    Rmate[j] = s;
    Lmate[s] = j;
    
    mated++;
  }
  
  double value = 0;
  for (int i = 0; i < n; i++)
    value += cost[i][Lmate[i]];
  
  return value;
}


int n,d;
string s[1035];

VVD costs;

bool vis[1035];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>d>>n;
	rep(x,0,n) cin>>s[x];
	
	rep(x,0,n){
		costs.pub(VD());
		rep(x,0,n) costs.back().pub(1e9);
	}
	
	rep(x,0,n) rep(y,0,n) if (x!=y){
		bool can=true;
		int tot=0;
		
		rep(z,0,d){
			if (s[x][z]=='1' && s[y][z]=='0') can=false;
			if (s[x][z]=='1') tot++;
		}
		
		if (can) costs[x][y]=-tot;
	}
	
	vector<int> vl,vr;
	auto temp=MinCostMatching(costs,vl,vr);
	
	//for (auto &it:vl) cout<<it<<" "; cout<<endl;
	
	string ans="";
	
	rep(x,0,n) if (costs[x][vl[x]]==1e9 && !vis[vl[x]]){
		int curr=vl[x];
		string str=string(d,'0');
		
		while (true){
			rep(z,0,d) if (str[z]=='0' && s[curr][z]=='1'){
				ans+=to_string(z);
			}
			
			if (costs[curr][vl[curr]]==1e9) break;
			str=s[curr];
			curr=vl[curr];
		}
		ans+='R';
	}
	
	cout<<sz(ans)-1<<endl;
	
	rep(x,0,sz(ans)-1)
		cout<<ans[x]<<" ";
}