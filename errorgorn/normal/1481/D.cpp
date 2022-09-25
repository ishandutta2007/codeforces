// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

int n,k;
string grid[1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		rep(x,0,n) cin>>grid[x];
		
		if (k%2==1){
			cout<<"YES"<<endl;
			rep(x,0,k+1) cout<<x%2+1<<" "; cout<<endl;
		}
		else{
			rep(x,0,n) rep(y,x+1,n) if (grid[x][y]==grid[y][x]){
				cout<<"YES"<<endl;
				
				rep(z,0,k+1){
					if (z%2==0) cout<<x+1<<" ";
					else cout<<y+1<<" ";
				}
				cout<<endl;
				
				goto done;
			}
			
			if (n>=3){
				rep(x,0,3) if (grid[(x+1)%3][x]==grid[x][(x+2)%3]){
					cout<<"YES"<<endl;
					rep(z,k/2+1,1){
						if (z%2==1) cout<<(x+1)%3+1<<" "; 
						else cout<<x+1<<" ";
					}
					rep(z,0,k/2+1){
						if (z%2==1) cout<<(x+2)%3+1<<" ";
						else cout<<x+1<<" ";
					}
					cout<<endl;
					break;
				}
			}
			else{
				cout<<"NO"<<endl;
			}
			
			done:;
		}
	}
}