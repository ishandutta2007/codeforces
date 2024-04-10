//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

const int C=20;

int n;
ll arr[1000005];
int cnt[2][1000005][20];

#define pc __builtin_popcountll

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	//rep(x,1,n+1) cout<<pc(arr[x])<<" "; cout<<endl;
	
	ll ans=0;
	
	rep(z,0,60/C){
		vector<int> mnstk={ 0 };
		vector<int> mxstk={ 0 };
		memset(cnt,0,sizeof(cnt));
		
		ll curr=0;
		
		rep(x,1,n+1){
			while (sz(mnstk)>=2 && arr[mnstk.back()]>arr[x]){
				//check if the last guy is fully contained in another guy
				int l=mnstk[sz(mnstk)-2]+1;
				int r=mnstk.back();
				
				auto it=lb(all(mxstk),l)-mxstk.begin();
				
				//update other guy
				int len=min(mxstk[it],r)-l+1;
				if (z*C<=pc(arr[r]) && pc(arr[r])<(z+1)*C)
					cnt[1][mxstk[it]][pc(arr[r])-z*C]-=len;
				if (z*C<=pc(arr[x]) && pc(arr[x])<(z+1)*C)
					cnt[1][mxstk[it]][pc(arr[x])-z*C]+=len;
				
				//update yourself if you are fully contained
				if (mxstk[it]>=r){
					memset(cnt[0][r],0,sizeof(cnt[0][r]));
					if (z*C<=pc(arr[mxstk[it]]) && pc(arr[mxstk[it]])<(z+1)*C)
						cnt[0][r][pc(arr[mxstk[it]])-z*C]=r-l+1;
				}
				
				if (z*C<=pc(arr[r]) && pc(arr[r])<(z+1)*C)
					curr-=cnt[0][r][pc(arr[r])-z*C];
				if (z*C<=pc(arr[x]) && pc(arr[x])<(z+1)*C)
					curr+=cnt[0][r][pc(arr[x])-z*C];
				rep(bit,0,C) cnt[0][x][bit]+=cnt[0][r][bit];
				
				mnstk.pob();
			}
			
			while (sz(mxstk)>=2 && arr[mxstk.back()]<arr[x]){
				//check if the last guy is fully contained in another guy
				int l=mxstk[sz(mxstk)-2]+1;
				int r=mxstk.back();
				
				auto it=lb(all(mnstk),l)-mnstk.begin();
				
				//update other guy
				int len=min(mnstk[it],r)-l+1;
				if (z*C<=pc(arr[r]) && pc(arr[r])<(z+1)*C)
					cnt[0][mnstk[it]][pc(arr[r])-z*C]-=len;
				if (z*C<=pc(arr[x]) && pc(arr[x])<(z+1)*C)
					cnt[0][mnstk[it]][pc(arr[x])-z*C]+=len;
				
				//update yourself if you are fully contained
				if (mnstk[it]>=r){
					memset(cnt[1][r],0,sizeof(cnt[1][r]));
					if (z*C<=pc(arr[mnstk[it]]) && pc(arr[mnstk[it]])<(z+1)*C)
						cnt[1][r][pc(arr[mnstk[it]])-z*C]=r-l+1;
				}
				
				if (z*C<=pc(arr[r]) && pc(arr[r])<(z+1)*C)
					curr-=cnt[1][r][pc(arr[r])-z*C];
				if (z*C<=pc(arr[x]) && pc(arr[x])<(z+1)*C)
					curr+=cnt[1][r][pc(arr[x])-z*C];
				rep(bit,0,C) cnt[1][x][bit]+=cnt[1][r][bit];
				
				mxstk.pob();
			}
			
			mnstk.pub(x);
			mxstk.pub(x);
			if (z*C<=pc(arr[x]) && pc(arr[x])<(z+1)*C){
				cnt[0][x][pc(arr[x])-z*C]++;
				cnt[1][x][pc(arr[x])-z*C]++;
				curr++;
			}
			
			// for (auto &it:mnstk) cout<<it<<" "; cout<<endl;
			// for (auto &it:mxstk) cout<<it<<" "; cout<<endl;
			// rep(bits,0,6) cout<<cnt[0][x][bits]<<" "; cout<<endl;
			
			ans+=curr;
		}
	}
	
	
	
	cout<<ans<<endl;
}