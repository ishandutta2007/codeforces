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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,A,B;
int cnt[50];

int memo[2][4200000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>A>>B;
	int ped=A+B;
	
	rep(x,0,ped){
		cnt[x]=(n+ped-1)/ped;
		n--;
	}
	
	memset(memo,128,sizeof(memo));
	memo[0][0]=0;
	
	int a=0,b=1;
	int af=(1<<22)-1;
	rep(zzz,0,ped){
		memset(memo[b],128,sizeof(memo[b]));
		
		rep(x,0,1<<22){
			int temp=(x<<1)&af;
			memo[b][temp]=max(memo[b][temp],memo[a][x]);
			if (x&(1<<(A-1)) || x&(1<<(B-1))) continue;
			memo[b][temp|1]=max(memo[b][temp|1],memo[a][x]+cnt[zzz]);
		}
		
		swap(a,b);
		
		//rep(x,0,8) cout<<memo[a][x]<<" "; cout<<endl;
	}
	
	int ans=0;
	rep(x,0,1<<22) ans=max(ans,memo[a][x]);
	
	cout<<ans<<endl;
}