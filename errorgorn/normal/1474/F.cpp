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

ll n,k;
ll arr[55];

ll cnt[105];
ll tmp[105];
bool good[105];
int id[105];

vector<vector<ll> > mul(vector<vector<ll> > i, vector<vector<ll> > j,int m){
    vector<vector<ll> > res;
    res.reserve(sz(i));
    for (int x=0;x<i.size();x++){
        res.push_back(vector<ll>(sz(i),0));
        for (int y=0;y<i.size();y++){
            for (int z=0;z<i.size();z++){
                res[x][y]=(res[x][y]+i[x][z]*j[z][y])%m;
            }
        }
    }
    return res;
}

vector<vector<ll> > mexp(vector<vector<ll> > mat,long long p,int m){
    if (p==1) return mat;
    vector<vector<ll> > res=mexp(mat,p>>1,m);
    res=mul(res,res,m);
    if (p&1) res=mul(res,mat,m);
    return res;
}

ll solve(vector<ii> ranges,vector<bool> par){
	vector<ll> uni;
	
	for (auto &it:ranges){
		uni.pub(it.fi);
		uni.pub(it.se);
	}
	
	sort(all(uni));
	uni.erase(unique(all(uni)),uni.end());
	
	// for (auto &it:uni) cerr<<it<<" "; cerr<<endl;
		
	// rep(x,0,sz(uni)){
		// for (auto &it:pos[x]) cout<<it<<" "; cout<<endl;
	// }
	
	ll ans=0;
	rep(x,0,sz(uni)-1){
		tmp[0]=x==0;
		rep(y,0,sz(ranges)){
			tmp[y]=(tmp[y]+cnt[y])%MOD;
			tmp[y+1]=tmp[y];
		}
		
		rep(y,0,sz(ranges)){
			good[y]=(ranges[y].fi<=uni[x] && uni[x]<ranges[y].se);
		}
		
		rep(y,0,sz(ranges)){
			if (good[y]){
				if (par[y]) cnt[y]=tmp[y];
				else cnt[y]=tmp[y-1];
			}
			else cnt[y]=0;
		}
		
		// cout<<uni[x]<<":"<<endl;
		// rep(x,0,sz(ranges)) cout<<cnt[x]<<" "; cout<<endl;
		
		if (uni[x]+1==uni[x+1]) continue;
		//cout<<uni[x+1]-uni[x]-1<<endl;
		
		int IDX=0;
		rep(y,0,sz(ranges)){
			if (good[y]) id[y]=IDX++;
		}
		
		vector<vector<ll> > mat;
		rep(y,0,sz(ranges)) if (good[y]){
			mat.pub(vector<ll>(IDX,0));
			rep(z,0,id[y]+par[y]) mat[id[y]][z]=1;
		}
		
		auto mat2=mexp(mat,uni[x+1]-uni[x]-1,MOD);
		
		// rep(x,0,n+1){
			// rep(y,0,n+1) cout<<mat2[x][y]<<" "; cout<<endl;
		// }
		
		memset(tmp,0,sizeof(tmp));
		rep(y,0,sz(ranges)) if (good[y]){
			rep(z,0,sz(ranges)) if (good[z]){
				tmp[y]=(tmp[y]+mat2[id[y]][id[z]]*cnt[z])%MOD;
			}
		}
		swap(tmp,cnt);
		//rep(x,0,sz(ranges)) cout<<cnt[x]<<" "; cout<<endl;
	}
	
	//rep(x,0,sz(ranges)) cout<<cnt[x]<<" "; cout<<endl;
	
	rep(x,0,sz(ranges)) ans=(ans+cnt[x])%MOD;
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	ll best=0;
	
	rep(x,0,n){
		ll curr=0;
		rep(y,x,n){
			curr+=arr[y];
			best=max(best,curr);
		}
	}
	best++;
	
	if (best==1){ //stupid case
		ll ans=1;
		rep(x,0,n) ans-=arr[x];
		cout<<best<<" "<<ans%MOD<<endl;
		return 0;
	}
	
	int idx=0;
	ll ans=0;
	while (idx<n){
		//cout<<"debug: "<<idx<<endl;
		ll curr=0;
		rep(y,idx,n){
			curr+=arr[y];
		}
		rep(y,n,idx){
			if (curr+1==best){
				curr=0;
				vector<ii> ranges={ii(0,1)};
				vector<bool> par={true};
				
				//cout<<idx<<" "<<y+1<<endl;
				rep(x,idx,y+1){
					if (arr[x]>0){
						ranges.pub(ii(curr+1,curr+arr[x]+1));
						par.pub(true);
						curr+=arr[x];
					}
					else if (arr[x]<0){
						ranges.pub(ii(curr+arr[x],curr));
						par.pub(false);
						curr+=arr[x];
					}
				}
				
				ans=(ans+solve(ranges,par))%MOD;
				
				idx=y+1;
				goto done;
			}
			curr-=arr[y];
		}
		idx++;
		done:;
	}
	
	
	cout<<best<<" "<<ans<<endl;
}