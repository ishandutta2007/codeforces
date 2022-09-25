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

int n,a,b;
int arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>a>>b;
		
		if (a+b>n-2){
			cout<<"-1"<<endl;
			continue;
		}
		if (abs(a-b)>1){
			cout<<"-1"<<endl;
			continue;
		}
		
		int l=1,r=n;
		bool flag=false;
		
		int c=a+b;
		rep(x,0,n){
			if (c){
				if (flag) arr[x]=l++;
				else arr[x]=r--;
				flag^=true;
				c--;
			}
			else{
				if (flag) arr[x]=l++;
				else arr[x]=r--;
			}
		}
		
		if (a>b) rep(x,0,n) arr[x]=n+1-arr[x];
		rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
	}
}