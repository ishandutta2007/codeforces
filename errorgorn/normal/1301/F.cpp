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

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m,k;
vector<ii> pos[45];

int grid[1005][1005];
int w[45][1005][1005];
deque<ii> dq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(w,63,sizeof(w));
	
	cin>>n>>m>>k;
	rep(x,0,n){
		rep(y,0,m){
			cin>>grid[x][y];
			pos[grid[x][y]].push_back(ii(x,y));
		}
	}
	
	rep(layer,1,k+1){
		w[layer][1002][layer]=0;
		dq.push_back(ii(1002,layer));
		
		while (!dq.empty()){
			int px=dq.front().fi,py=dq.front().se;
			//cout<<layer<<" "<<px<<" "<<py<<" "<<w[layer][px][py]<<endl;
			dq.pop_front();
			
			if (px==1002){
				for (auto &it:pos[py]){
					if (w[layer][it.fi][it.se]>w[layer][px][py]+1){
						w[layer][it.fi][it.se]=w[layer][px][py]+1;
						dq.push_back(it);
					}
				}
			}
			else{
				rep(z,0,4){
					int x=px+dx[z],y=py+dy[z];
					
					if (x<0 || n<=x || y<0 || m<=y) continue;
					if (w[layer][x][y]>w[layer][px][py]+1){
						w[layer][x][y]=w[layer][px][py]+1;
						dq.push_back(ii(x,y));
					}
				}
				
				if (w[layer][1002][grid[px][py]]>w[layer][px][py]){
					w[layer][1002][grid[px][py]]=w[layer][px][py];
					dq.push_front(ii(1002,grid[px][py]));
				}
			}
		}
	}
	
	/*
	rep(layer,1,k+1){
		rep(x,0,n){
			rep(y,0,m) cout<<w[layer][x][y]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	*/
	
	
	int q,a,b,c,d;
	cin>>q;
	while (q--){
		cin>>a>>b>>c>>d;
		a--,b--,c--,d--;
		int ans=abs(a-c)+abs(b-d);
		
		rep(x,1,k+1){
			ans=min(ans,w[x][a][b]+w[x][c][d]-1);
		}
		
		cout<<ans<<endl;
	}
}