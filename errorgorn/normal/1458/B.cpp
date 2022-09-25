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

int n,m;
int arr[105];
int brr[105];

int memo[2][105][10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	int tot=0;
	rep(x,0,n){
		cin>>arr[x]>>brr[x];
		tot+=brr[x];
	}
	
	memset(memo,128,sizeof(memo));
	memo[0][0][tot]=0;
	
	int a=0,b=1;
	rep(x,0,n){
		memset(memo[b],128,sizeof(memo[b]));
		
		rep(y,0,n){
			rep(z,0,10005) if (memo[a][y][z]>=0){
				memo[b][y][z]=max(memo[b][y][z],memo[a][y][z]);
				int rem=(arr[x]-brr[x])*2;
				
				int nz=z-brr[x];
				int val;
				if (nz>=0) val=brr[x]*2+min(nz,rem);
				else val=z*2-nz;
				
				int temp=max(0,z-brr[x]-rem);
				
				//cout<<x<<" "<<y<<" "<<z<<" "<<nz<<" "<<rem<<" "<<val<<endl;
				
				memo[b][y+1][temp]=max(memo[b][y+1][temp],memo[a][y][z]+val);
			}
		}
		
		swap(a,b);
	}
	
	rep(x,1,n+1){
		int ans=0;
		rep(y,0,10005) ans=max(ans,memo[a][x][y]);
		
		cout<<fixed<<setprecision(12)<<(long double)ans/2<<" ";
	}
}