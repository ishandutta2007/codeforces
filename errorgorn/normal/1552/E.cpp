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
int arr[100005];

bool done[105];
map<int,int> m;
ii ans[105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n*k) cin>>arr[x];
	
	int num=(n+(k-1)-1)/(k-1);
	//cout<<"debug: "<<num<<endl;
	
	int proc=0;
	
	rep(x,0,n*k) if (!done[arr[x]]){
		//cout<<x<<endl;
		
		if (m.count(arr[x])){
			done[arr[x]]=true;
			ans[arr[x]]=ii(m[arr[x]],x);
			proc++;
		}
		else{
			m[arr[x]]=x;
		}
		
		if (proc==num){
			m.clear();
			proc=0;
		}
	}
	
	rep(x,1,n+1) cout<<ans[x].fi+1<<" "<<ans[x].se+1<<endl;
}