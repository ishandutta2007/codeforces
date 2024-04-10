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
int arr[300005];
int brr[300005];

int cnt[300005];
bool vis[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		rep(x,0,n) cin>>arr[x];
		
		rep(x,0,n) cnt[x]=0;
		rep(x,0,n) cnt[(arr[x]-(x+1)+n)%n]++;
		
		vector<int> ans;
		
		rep(x,0,n) if (cnt[x]>=n/3-2){
			//cout<<x<<" "; cout<<endl;
			rep(y,0,n) brr[(y+x)%n]=arr[y];
			
			rep(y,0,n) vis[y]=false;
			
			int curr=n;
			rep(y,0,n) if (!vis[y]){
				curr--;
				
				int c=y;
				do{
					vis[c]=true;
					c=brr[c]-1;
				} while (c!=y);
			}
			
			if (curr<=k) ans.pub((n-x)%n);
		}
		
		sort(all(ans));
		cout<<sz(ans)<<" "; for (auto &it:ans) cout<<it<<" "; cout<<endl;
	}
}