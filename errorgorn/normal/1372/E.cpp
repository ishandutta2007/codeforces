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
vector<int> v[105];
int memo[105][105];

int dp(int i,int j){
	if (j<i) return 0;
	else if (memo[i][j]!=-1) return memo[i][j];
	
	int arr[105];
	memset(arr,0,sizeof(arr));
	
	rep(x,0,n){
		int lo=*lower_bound(all(v[x]),i);
		int hi=*--upper_bound(all(v[x]),j+1);
		
		//cout<<lo<<" "<<hi<<endl;		
		if (hi<lo) continue;
		
		arr[lo]++;
		arr[hi]--;
	}
	
	rep(x,0,m) arr[x+1]+=arr[x];
	
	int res=0;
	rep(x,i,j+1){
		res=max(res,dp(i,x-1)+dp(x+1,j)+arr[x]*arr[x]);
	}
	
	//cout<<i<<" "<<j<<" "<<res<<endl;
	return memo[i][j]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memo,-1,sizeof(memo));
	
	cin>>n>>m;
	
	rep(x,0,n){
		int t;
		cin>>t;
		rep(y,0,t){
			int a,b;
			cin>>a>>b;
			
			v[x].push_back(a-1);
		}
		v[x].push_back(m);
	}
	
	cout<<dp(0,m-1)<<endl;
}