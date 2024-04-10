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
ii arr[800005];
ll ans=0;

priority_queue<ll,vector<ll>,greater<ll> > f;
priority_queue<ll> b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	rep(x,0,n){
		arr[x].fi+=arr[x].se;
	}
	
	b.push(0),f.push(0);
	
	sort(arr,arr+n);
	
	//under this the bottom doesnt get offset, only top
	
	rep(x,0,n){
		//f is f+arr[x].fi;
		
		//cout<<arr[x].fi<<" "<<arr[x].se<<endl;
		
		int offset=arr[x].fi;
		
		if (b.top()<=arr[x].se && arr[x].se<=f.top()+offset){ //middle
			b.push(arr[x].se);
			f.push(arr[x].se-offset);
		}
		else if (arr[x].se<b.top()){ //bottom
			b.push(arr[x].se);
			b.push(arr[x].se);
			
			int temp=b.top(); b.pop();
			ans+=temp-b.top();
			ans+=b.top()-arr[x].se;
			f.push(temp-offset);
		}
		else{ //top
			f.push(arr[x].se-offset);
			f.push(arr[x].se-offset);
			
			int temp=f.top(); f.pop();
			ans+=f.top()-temp;
			ans+=(arr[x].se-offset)-f.top();
			b.push(temp+offset);
		}
	}
	
	cout<<ans<<endl;
}