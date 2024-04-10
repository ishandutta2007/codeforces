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

int n,k;
vector<int> v;
map<int,int> m;

vector<ii> ans1;
vector<int> ans2;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		m.clear();
		ans1.clear();
		ans2.clear();
		
		cin>>n;
		v.resize(n);
		rep(x,0,n) cin>>v[x];
		rep(x,0,n) m[v[x]]++;
		
		bool ok=true;
		for (auto &it:m){
			if (it.se%2) ok=false;
		}
		
		if (!ok){
			cout<<"-1"<<endl;
			continue;
		}
		
		int IDX=0;
		while (!v.empty()){
			int pos=1;
			while (v[0]!=v[pos]) pos++;
			
			rep(x,1,pos) ans1.pub({IDX+pos+x,v[x]});
			
			IDX+=pos*2;
			
			reverse(v.begin()+1,v.begin()+pos);
			v.erase(v.begin()+pos);
			v.erase(v.begin());
			
			ans2.pub(pos*2);
		}
		
		cout<<sz(ans1)<<endl;
		for (auto &it:ans1) cout<<it.fi<<" "<<it.se<<endl;
		cout<<sz(ans2)<<endl;
		for (auto &it:ans2) cout<<it<<" "; cout<<endl;
	}
}