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

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

int n;
int arr[1005][505];
bool has[1005];
int occ[505];

int cnt;
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		memset(has,false,sizeof(has));
		cnt=0;
		ans.clear();
		
		cin>>n;
		rep(x,0,2*n) rep(y,0,n) cin>>arr[x][y];
		
		rep(zzz,0,n){
			rep(y,0,n){
				memset(occ,0,sizeof(occ));
				rep(x,0,2*n) if (!has[x]){
					occ[arr[x][y]]++;
				}
				
				int idx=-1;
				rep(x,1,n+1) if (occ[x]==1) idx=x;
				
				if (idx!=-1){
					rep(x,0,2*n) if (!has[x] && arr[x][y]==idx){
						idx=x;
						break;
					}
					
					ans.pub(idx);
					has[idx]=true;
					
					rep(x,0,2*n) if (!has[x]){
						bool bad=false;
						rep(y,0,n) if (arr[x][y]==arr[idx][y]) bad=true;
						if (bad) has[x]=true;
					}
					break;
				}
			}
			
			if (sz(ans)==zzz){
				cnt++;
				int idx=-1;
				rep(x,0,2*n) if (!has[x]){
					idx=x;
				}
				
				ans.pub(idx);
				has[idx]=true;
				
				rep(x,0,2*n) if (!has[x]){
					bool bad=false;
					rep(y,0,n) if (arr[x][y]==arr[idx][y]) bad=true;
					if (bad) has[x]=true;
				}
			}
		}
		
		cout<<qexp(2,cnt,MOD)<<endl;
		for (auto &it:ans) cout<<it+1<<" "; cout<<endl;
	}
}