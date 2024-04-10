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
int num;
bool bad;

void split(int i){
	if (s.find(i)!=s.end()){
		s.erase(s.find(i));
		return;
	}
	if (i==1 || num==n){
		bad=true;
		return;
	}
	num++;
	split(i/2);
	split((i+1)/2);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		
		cin>>n;
		
		int a;
		int tot=0;
		rep(x,0,n){
			cin>>a;
			s.insert(a);
			tot+=a;
		}
		
		num=0;
		bad=false;
		split(tot);
		
		if (!bad) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}