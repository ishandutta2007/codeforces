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

int n,k;
int arr[1100000];
bool has[1100000];

vector<bool> pref[1100000];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,n+1){
		int y=x;
		int curr=arr[x];
		
		while (true){
			int tot=n-1-(y-x);
			int need=k;
			if (x!=1) tot--,need--;
			if (y!=n) tot--,need--;
			
			need=max(need,0LL);
			
			if (need<=tot){
				need=tot-need;
				
				if (pref[tot].empty()){
					pref[tot]={0};
					rep(x,0,tot+1){
						pref[tot].pub(pref[tot].back()^((x&tot)==x));
					}
				}
				
				has[curr]^=pref[tot][need+1];
			}
			
			if (y==n) break;
			y++;
			if (arr[y]>20) break; //sdflkojnsfns
			curr*=1<<arr[y];
			if (curr>=(1<<20)) break;
		}
	}
	
	string s;
	rep(x,1100000,0){
		if (has[x]) s+='1';
		else if (!s.empty()) s+='0';
	}
	
	if (s=="") s="0";
	
	cout<<s<<endl;
}