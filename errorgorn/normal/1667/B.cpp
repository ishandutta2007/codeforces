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

struct node{
	int arr[1001000];
	const int BUF=500500;
	
	node (){
		rep(x,0,1001000) arr[x]=-1e18;
	}
	
	void update(int i,int k){
		i+=BUF;
		
		while (i){
			arr[i]=max(arr[i],k);
			i>>=1;
		}
	}
	
	void set(int i){
		i+=BUF;
		while (i){
			arr[i]=-1e18;
			i>>=1;
		}
	}
	
	int query(int i,int j){
		i+=BUF,j+=BUF+1;
		int res=-1e18;
		
		while (i<j){
			if (i&1){
				res=max(res,arr[i]);
				i++;
			}
			if (j&1){
				j--;
				res=max(res,arr[j]);
			}
			
			i>>=1,j>>=1;
		}
		
		return res;
	}
} root1,root2;

int n;
int arr[500005];
int pref[500005];
int val[500005];

void upd(int i,int k,int pos){
	root1.update(i,k+pos);
	root2.update(i,k-pos);
	val[i]=k;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,500005) val[x]=-1e18;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) pref[x]=pref[x-1]+arr[x];
		
		vector<int> uni;
		rep(x,0,n+1) uni.pub(pref[x]);
		
		sort(all(uni));
		rep(x,0,n+1) pref[x]=lb(all(uni),pref[x])-uni.begin();
		
		upd(pref[0],0,0);
		
		int ans;
		rep(x,1,n+1){
			ans=val[pref[x]];
			
			ans=max(ans,-x+root1.query(pref[x]+1,500005));
			ans=max(ans,x+root2.query(-5,pref[x]-1));
			
			upd(pref[x],ans,x);
		}
		
		rep(x,0,n+1){
			root1.set(x);
			root2.set(x);
			val[x]=-1e18;
		}
		
		cout<<ans<<endl;
	}
}