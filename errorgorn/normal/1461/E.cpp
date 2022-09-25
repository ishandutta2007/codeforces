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

ll k,l,r,t,x,y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>k>>l>>r>>t>>x>>y;
	
	if (x>y){
		if (k+y<=r) k+=y;
		k-=x;
		t--;
		
		if (k<l || (t && (k-l)/t<(x-y))) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	else{
		k-=l;
		ll nums=0;
		ll loops=0;
		while (loops<10000000 && nums<t){
			if (k+y<=r-l) k+=y;
			if (k<x){
				cout<<"No"<<endl;
				return 0;
			}
			else{
				nums+=k/x;
				k%=x;
			}
			
			loops++;
		}
		cout<<"Yes"<<endl;
	}
}