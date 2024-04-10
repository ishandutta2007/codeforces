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

int query(int i,int j){
	int res=0;
	cout<<"and "<<i<<" "<<j<<endl;
	cout<<"or "<<i<<" "<<j<<endl;
	
	int temp;
	cin>>temp;
	res+=temp;
	cin>>temp;
	res+=temp;
	return res;
}

int n,k;
int arr[10005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	int a=query(1,2);
	int b=query(2,3);
	int c=query(1,3);
	
	arr[1]=(a+c-b)/2;
	arr[2]=(a+b-c)/2;
	arr[3]=(b+c-a)/2;
	
	rep(x,4,n+1) arr[x]=query(1,x)-arr[1];
	
	sort(arr+1,arr+n+1);
	cout<<"finish "<<arr[k]<<endl;
	
}