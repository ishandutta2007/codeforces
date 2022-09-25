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

const int MOD=998244353;

int n;
string s;

#define si pair<string,int>

si solve(int i){
	if (i>=(1<<(n-1))){
		return {s.substr(i,1),1};
	}
	else{
		si r1=solve(i<<1),r2=solve(i<<1|1);
		
		string res=s.substr(i,1);
		
		if (r1.fi==r2.fi){
			res+=r1.fi+r2.fi;
			return {res,r1.se*r2.se%MOD};
		}
		else{
			if (r1.fi>r2.fi) swap(r1.fi,r2.fi);
			res+=r1.fi+r2.fi;
			return {res,r1.se*r2.se*2%MOD};
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	cin>>s;
	
	s="$"+s;
	
	cout<<solve(1).se<<endl;
}