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

const int MOD=1000000007;
const int INF=1e9;

int n,k;
int arr[5005];
vector<int> hunger[5005];
ii cnt[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	arr[n]=-1; //funny case
	
	int a,b;
	while (k--){
		cin>>a>>b;
		hunger[a].push_back(b);
	}
	
	rep(x,0,5005) sort(all(hunger[x]));
	
	int best=-1;
	int total=0;
	
	rep(p,0,n+1){ 
		//this is the partition
		//the immediate right must be used so double counting does not happen
		int used=(p==n?0:-INF);
		ll curr=1;
		
		memset(cnt,0,sizeof(cnt));
		
		rep(x,0,p) cnt[arr[x]].fi++;
		rep(x,p,n) cnt[arr[x]].se++;
		
		//cout<<cnt[2].fi<<" "<<cnt[2].se<<endl;
		//cout<<cnt[3].fi<<" "<<cnt[3].se<<endl<<endl;
		
		rep(x,0,5005){
			ll val=0;
			if (arr[p]==x){
				bool taken=false;
				for (auto &it:hunger[x]){
					if (it==cnt[x].se) used+=INF+1;
					else if (it<=cnt[x].fi){
						if (!taken){
							taken=true;
							used++;
						}
						val++;
					}
				}
			}
			else{
				if (cnt[x].fi>cnt[x].se) swap(cnt[x].fi,cnt[x].se);
				
				if (sz(hunger[x])>=2 && hunger[x][0]<=cnt[x].fi && hunger[x][1]<=cnt[x].se){
					used+=2;
					int run=0;
					
					for (auto &it:hunger[x]){
						if (it<=cnt[x].fi) val+=run*2;
						else if (it<=cnt[x].se) val+=run;
						
						if (it<=cnt[x].fi) run++;
					}
				}
				else if (sz(hunger[x])>=1 && hunger[x][0]<=cnt[x].se){
					used++;
					
					for (auto &it:hunger[x]){
						if (it<=cnt[x].se) val++;
						if (it<=cnt[x].fi) val++;
					}
				}
			}
			if (val) curr=(curr*val%MOD)%MOD;
		}
		
		//cout<<used<<" "<<curr<<endl;
		if (used>best){
			best=used;
			total=curr;
		}
		else if (used==best){
			total=(total+curr)%MOD;
		}
	}
	
	cout<<best<<" "<<total<<endl;
}