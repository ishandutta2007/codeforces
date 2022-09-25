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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int arr[200005];
ii edges[200005];
vector<int> pos[200005];
int brr[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,0,m) cin>>edges[x].fi>>edges[x].se;
		sort(edges,edges+m);
		
		vector<int> uni(arr+1,arr+n+1);
		sort(all(uni));
		rep(x,1,n+1) arr[x]=lb(all(uni),arr[x])-uni.begin();
		//rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		
		rep(x,0,n) pos[x].clear();
		rep(x,1,n+1) pos[arr[x]].pub(x);
		
		rep(x,1,n+1) brr[x]=-1;
		
		int idx=0;
		multiset<int> s;
		int mx=-1;
		int lim=1e9;
		rep(x,1,n+1){
			while (idx<m && edges[idx].fi==x){
				s.insert(edges[idx].se);
				idx++;
			}
			
			if (!s.empty()){
				int y=*s.rbegin();
				//cout<<"debug: "<<x<<" "<<y<<endl;
				int val=ub(all(pos[arr[x]]),y)-pos[arr[x]].begin()-1;
				int val2=lb(all(pos[arr[x]]),x)-pos[arr[x]].begin();
				if (val!=-1 && x!=pos[arr[x]][val]){
					//cout<<"debug: "<<x<<" "<<pos[arr[x]][val]<<endl;
					brr[x+1]=max(brr[x+1],pos[arr[x]][val]);
					mx=max(mx,x);
					lim=min(lim,pos[arr[x]][val2+1]);
				}
			}
			
			while (!s.empty() && *s.begin()==x) s.erase(s.begin());
		}
		
		if (lim==1e9){
			cout<<0<<endl;
			continue;
		}
		
		int ans=1e9;
		rep(x,1,lim+1){
			//cout<<x<<" "<<mx<<endl;
			mx=max(mx,brr[x]);
			ans=min(ans,mx-x+1);
		}
		
		cout<<ans<<endl;
	}
}