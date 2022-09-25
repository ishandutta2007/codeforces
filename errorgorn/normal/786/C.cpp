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
#define int long long
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

int fen[100005];

void upd(int i,int j){
	while (i<100005){
		fen[i]+=j;
		i+=i&-i;
	}
}

int que(int i){
	int res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

int n;
int arr[100005];
int nxt[100005];
int occ[100005];

priority_queue<ii,vector<ii>,greater<ii> > pq;
int ans[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	memset(occ,-1,sizeof(occ));
	
	rep(x,n+1,1){
		nxt[x]=occ[arr[x]];
		occ[arr[x]]=x;
		
		if (nxt[x]!=-1) upd(nxt[x],-1);
		upd(x,1);
	}
	
	rep(x,1,n+1) pq.push({1,x});
	rep(x,1,n+1) ans[x]=1;
	
	//rep(x,1,n+1) cout<<nxt[x]<<" "; cout<<endl;
	
	rep(x,1,n+1){
		while (!pq.empty() && pq.top().fi==x){
			int u=pq.top().se; pq.pop();
			
			if (que(n)<=u) continue;
			
			int lo=0,hi=100004,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (que(mi)<=u) lo=mi;
				else hi=mi;
			}
			
			pq.push({hi,u});
			ans[u]++;
		}
		
		upd(x,-1);
		if (nxt[x]!=-1) upd(nxt[x],1);
	}
	
	rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
}