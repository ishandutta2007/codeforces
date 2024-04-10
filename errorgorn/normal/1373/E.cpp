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

ll n,k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		
		ll ans=1e18;
		
		rep(x,0,k+1){ //how many carry overs
			rep(y,0,20){ //how many consecutive 9s
				//n=val*(k+1)+k*(k+1)/2-x*((y+1)*9);
				
				ll val=n-k*(k+1)/2+x*((y+1)*9);
				if (val%(k+1)==0 && val>=0) val/=(k+1);
				else continue;
				
				//cout<<x<<" "<<y<<" "<<val<<endl;
				
				ll curr,pow=10,yy;
				
				if (x==0){
					curr=min(val,9-k);
					val-=curr;
					yy=-1;
				}
				else{
					curr=9-(k-x);
					val-=curr;
					yy=y;
				}
				
				while (val>0){
					int temp;
					if (yy<=-1){
						temp=min(val,9LL);
					}
					else if (y==0){
						temp=min(val,8LL);
					}
					else{
						temp=9;
					}
					
					curr+=pow*temp;
					val-=temp;
					
					pow*=10;
					yy--;
				}
				
				if (val<0 || yy>0) continue;
				
				//cout<<"debug: "<<curr<<endl;
				ans=min(ans,curr);
			}
		}
		
		if (ans==1e18) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}