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

int n,m;
int arr[2005][12];
int mx[2005];
vector<int> proc;

bool vis[4200];
int val[4200];

int ans[4200];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		memset(mx,0,sizeof(mx));
		memset(ans,0,sizeof(ans));
		proc.clear();
		
		cin>>n>>m;
		
		rep(x,0,n) rep(y,0,m){
			cin>>arr[y][x];
			mx[y]=max(mx[y],arr[y][x]);
		}
		
		rep(x,0,m) proc.push_back(x);
		
		sort(all(proc),[](int i,int j){
			return mx[i]>mx[j];
		});
		
		proc.resize(min(n,m));
		
		for (auto &it:proc){
			//cout<<"proc: "<<it<<endl;
			
			memset(vis,false,sizeof(vis));
			memset(val,false,sizeof(val));
			
			rep(x,1,(1<<n)){
				int bm=x;
				
				while (bm){
					val[x]+=arr[it][__builtin_ctz(bm)];
					bm-=bm&-bm;
				}
			}
			
			rep(x,1,(1<<n)) if (!vis[x]){
				int best=0;
				
				rep(zzz,0,n){
					vis[x]=true;
					best=max(best,val[x]);
					
					if (x&1) x|=(1<<n);
					x>>=1;
				}
				
				rep(zzz,0,n){
					val[x]=best;
					
					if (x&1) x|=(1<<n);
					x>>=1;
				}
			}
			
			rep(x,(1<<n),1){
				int bm=x;
				
				while (bm){
					bm=(bm-1)&x;
					
					ans[x]=max(ans[x],ans[bm]+val[x^bm]);
				}
			}
		}
		
		cout<<ans[(1<<n)-1]<<endl;
	}
}