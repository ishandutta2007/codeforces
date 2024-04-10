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

struct FEN{
	int arr[1000005];
	
	void upd(int i,int k){
		i++;
		while (i<1000005){
			arr[i]+=k;
			i+=i&-i;
		}
	}
	
	int query(int i){
		i++;
		
		int res=0;
		while (i){
			res+=arr[i];
			i-=i&-i;
		}
		return res;
	}
	
	int query(int i,int j){
		return query(j)-query(i-1);
	}
} fen;

int n,m,q;
set<int> s;
string grid[1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	rep(x,0,n) cin>>grid[x];
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='*'){
		s.insert(x+y*n);
		fen.upd(x+y*n,1);
	}
	
	int a,b;
	while (q--){
		cin>>a>>b;
		a--,b--;
		
		if (s.count(a+b*n)){
			s.erase(a+b*n);
			fen.upd(a+b*n,-1);
		}
		else{
			s.insert(a+b*n);
			fen.upd(a+b*n,1);
		}
		
		//for (auto it:s) cout<<it<<" "; cout<<endl;
		cout<<sz(s)-fen.query(sz(s)-1)<<endl;
	}
	
}