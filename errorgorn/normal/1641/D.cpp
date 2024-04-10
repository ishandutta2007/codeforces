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

#define int unsigned int
#define ll unsigned long long
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

#define rep(x,start,end) for(auto x=start;x<end;x++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int arr[100005][5];
int arr2[100005][5];
int w[100005];
int w2[100005];

ll bm[500005];

bool bad[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n){
		rep(y,0,m) cin>>arr[x][y];
		cin>>w[x];
	}
	
	vector<int> uni;
	rep(x,0,n) rep(y,0,m) uni.pub(arr[x][y]);
	
	sort(all(uni));
	rep(x,0,n) rep(y,0,m) arr[x][y]=lb(all(uni),arr[x][y])-uni.begin();
	
	vector<int> idx;
	rep(x,0,n) idx.pub(x);
	sort(all(idx),[](int i,int j){
		return w[i]<w[j];
	});
	
	rep(x,0,100005) w2[x]=2e9+5;
	rep(x,0,n){
		rep(y,0,m) arr2[x][y]=arr[idx[x]][y];
		w2[x]=w[idx[x]];
	}
	
	swap(arr,arr2);
	swap(w,w2);
	
	int ans=2e9+5;
	for (int z=0;z<n;z+=64){
		rep(x,z,min(z+64,n)){
			rep(y,0,m) bm[arr[x][y]]|=(1LL<<(x-z));
		}
		
		rep(x,0,n){
			ll ok=0;
			rep(y,0,m) ok|=bm[arr[x][y]];
			
			ok=~ok;
			if (ok==0) continue;
			int pos=z+__builtin_ctzll(ok);
			ans=min(ans,w[x]+w[pos]);
		}
		
		rep(x,z,min(z+64,n)){
			rep(y,0,m) bm[arr[x][y]]=0;
		}
	}
	
	if (ans==2e9+5) cout<<"-1"<<endl;
	else cout<<ans<<endl;
}