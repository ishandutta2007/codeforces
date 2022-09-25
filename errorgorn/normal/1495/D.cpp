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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=998244353;

int n,m;
int apsp[405][405];
vector<ii> edges;

int cnt[405];

ll ans[405][405];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	memset(apsp,63,sizeof(apsp));
	rep(x,0,405) apsp[x][x]=0;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		apsp[a][b]=1;
		apsp[b][a]=1;
		edges.pub(ii(a,b));
	}
	
	rep(k,1,n+1)
		rep(i,1,n+1)
			rep(j,1,n+1)
				apsp[i][j]=min(apsp[i][j],apsp[i][k]+apsp[k][j]);
				
	rep(x,1,n+1){
		rep(y,1,n+1){
			//cout<<"lol: "<<x<<" "<<y<<endl;
			
			memset(cnt,0,sizeof(cnt));
			int cross=0;
			
			for (auto &it:edges){
				if (apsp[x][it.fi]>apsp[x][it.se]) swap(it.fi,it.se);
				if (apsp[x][it.fi]+1!=apsp[x][it.se]) continue;
				
				if (apsp[y][it.fi]+1==apsp[y][it.se]){
					cnt[it.se]++;
				}
				else if (apsp[y][it.fi]-1==apsp[y][it.se]){
					if (apsp[x][it.fi]+1+apsp[it.se][y]!=apsp[x][y]) continue;
					cross++;
				}
			}
			
			//cout<<cross<<endl;
			//rep(x,1,n+1) cout<<cnt[x]<<" "; cout<<endl;
			
			if (cross!=apsp[x][y]) continue;
			
			ans[x][y]=1;
			rep(z,1,n+1) if (z!=x){
				if (cnt[z]==0){
					if (cross) cross--;
					else ans[x][y]=0;
				}
				else ans[x][y]=(ans[x][y]*cnt[z])%MOD;
			}
		}
	}
	
	rep(x,1,n+1){
		rep(y,1,n+1) cout<<ans[x][y]<<" ";
		cout<<endl;
	}
}