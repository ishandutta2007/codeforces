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

int n,q;
int arr[105];
map<string,int> m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
	
	string s;
	rep(x,0,q){
		cin>>s;
		m[s]++;
	}
	
	vector<int> v;
	for (auto [a,b]:m) v.pub(b);
	
	sort(all(v));
	reverse(all(v));
	
	sort(arr,arr+n);
	
	int a=0;
	rep(x,0,sz(v)) a+=arr[x]*v[x];
	int b=0;
	reverse(arr,arr+n);
	rep(x,0,sz(v)) b+=arr[x]*v[x];
	
	cout<<a<<" "<<b<<endl;
}