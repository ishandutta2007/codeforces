/*













*/

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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int grid[35][35];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n){
			rep(y,0,m) cin>>grid[x][y];
		}
		
		int ans=0;
		rep(x,0,(n+m-1)/2){
			int cnt=0,tot=0;
			
			rep(y,0,n){
				if (0<=x-y && x-y<m){
					//cout<<y<<" "<<x-y<<endl;
					cnt+=grid[y][x-y];
					tot++;
				}
				if (0<=(n+m-2)-x-y && (n+m-2)-x-y<m){
					//cout<<y<<" "<<(n+m-2)-x-y<<endl;
					cnt+=grid[y][(n+m-2)-x-y];
					tot++;
				}
			}
			
			//cout<<"debug: "<<cnt<<" "<<tot<<endl;
			ans+=min(cnt,tot-cnt);
		}
		
		cout<<ans<<endl;
	}
}