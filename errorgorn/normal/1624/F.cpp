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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int n;
	cin>>n;
	
	int l=1,r=n-1;
	
	bool flag=true;
	int curr=0;
	int add=0;
	
	while (l!=r){
		int m=(r-l+1)>>1;
		if (flag){
			cout<<"+ "<<m<<endl;
			add+=m;
			
			int temp;
			cin>>temp;
			if (temp==curr){
				r-=m;
			}
			else{
				l=r-m+1;
				curr++;
				flag=false;
			}
		}
		else{
			cout<<"+ "<<n-m<<endl;
			add+=n-m;
			
			int temp;
			cin>>temp;
			if (temp==curr){
				r=l+m-1;
				flag=true;
			}
			else{
				l+=m;
				curr++;
			}
		}
	}
	
	cout<<"! "<<l+add<<endl;
}