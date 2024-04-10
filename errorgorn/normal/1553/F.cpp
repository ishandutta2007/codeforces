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

int n;
int arr[200005];

struct fen1{
	long long arr[300005]; //initialize to 0, this is 1-indexed
	void update(int i,long long j){ //adds j to ith term
	    while (i<300005){
	        arr[i]+=j;
	        i+=(i&(-i));
	    }
	}
	void update(int i,int j,ll k){
		update(i,k);
		update(j+1,-k);
	}
	long long query(int i){ //calculate the sum of the 1-i terms
	    long long k=0;
	    while (i>0){
	        k+=arr[i];
	        i-=(i&(-i));
	    }
	    return k;
	}
} sub;

struct fen2{
	long long arr[300005]; //initialize to 0, this is 1-indexed
	void update(int i,long long j){ //adds j to ith term
	    while (i<300005){
	        arr[i]+=j;
	        i+=(i&(-i));
	    }
	}
	long long query(int i){ //calculate the sum of the 1-i terms
	    long long k=0;
	    while (i>0){
	        k+=arr[i];
	        i-=(i&(-i));
	    }
	    return k;
	}
	long long query(int i,int j){
		return query(j)-query(i-1);
	}
} cnt,val;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	ll ans=0;
	
	rep(x,0,n){
		ans+=val.query(1,arr[x]);
		ans+=cnt.query(arr[x],300004)*arr[x];
		
		ans+=cnt.query(1,arr[x])*arr[x];
		ans-=sub.query(arr[x]);
		
		cnt.update(arr[x],1);
		val.update(arr[x],arr[x]);
		for (int y=1;arr[x]*y<300004;y++){
			int l=arr[x]*y,r=min(arr[x]*(y+1)-1,300004);
			
			sub.update(l,r,arr[x]*y);
			ans+=val.query(l,r);
			ans-=cnt.query(l,r)*arr[x]*y;
		}
		
		cout<<ans<<" ";
	}
}