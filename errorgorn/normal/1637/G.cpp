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

int n;

multiset<int> s;
vector<ii> ans;
void solve(int i,int mul){ //solve [1..n] with multiplier mul
	if (i==0) return;
	int j=1<<(31-__builtin_clz(i));
	
	for (int x=1;x<=i-j;x++){
		ans.pub({mul*(j-x),mul*(j+x)});
		s.insert(mul*(2*j));
	}
	s.insert(j*mul);
	
	solve(j*2-i-1,mul);
	solve(i-j,mul*2);
}

void op(int i,int j){
	s.erase(s.find(i));
	s.erase(s.find(j));
	ans.pub({i,j});
	s.insert(i+j);
	s.insert(abs(i-j));
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		if (n==2){
			cout<<"-1"<<endl;
			continue;
		}
		
		s.clear();
		ans.clear();
		solve(n,1);
		
		for (auto it:s) if (s.count(it)>=2){
			op(it,it);
			break;
		}
		
		int lim=*prev(s.end());
		
		vector<int> v(all(s));
		for (auto it:v){
			if (it){
				while (it<lim){
					op(0,it);
					op(it,it);
					it*=2;
				}
			}
		}
		for (auto it:v){
			if (it==0){
				op(0,lim);
			}
		}
		
		cout<<sz(ans)<<endl;
		for (auto it:ans) cout<<it.fi<<" "<<it.se<<endl;
	}
}