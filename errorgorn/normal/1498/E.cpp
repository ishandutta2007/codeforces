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
#define iii pair<ll,ii>
#define fi first
#define se second
//#define endl '\n'
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

int n;
int arr[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	vector<iii> v;
	rep(x,1,n+1){
		rep(y,x+1,n+1){
			int a=x,b=y;
			if (arr[a]>arr[b]) swap(a,b);
			v.pub(iii(abs(arr[b]-arr[a]),ii(a,b)));
		}
	}
	
	sort(all(v));
	reverse(all(v));
	
	for (auto &it:v){
		int a=it.se.fi,b=it.se.se;
		
		cout<<"? "<<b<<" "<<a<<endl;
		string s;
		cin>>s;
		
		if (s=="Yes"){
			cout<<"! "<<a<<" "<<b<<endl;
			return 0;
		}
	}
	
	cout<<"! 0 0"<<endl;
}