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

int n,s,m,k;
int arr[1505];
int pref[1505];
vector<int> ranges[1505];

ll memo[2][1505];

bool can(int i){
	rep(x,1,n+1) pref[x]=pref[x-1]+(arr[x]<=i);
	
	int a=0,b=1;
	memset(memo,0,sizeof(memo));
	
	rep(zzz,0,m){
		memset(memo[b],0,sizeof(memo[b]));
		vector<ii> v={ii(0,0)};
		
		rep(x,1,n+1){
			ii temp=ii(x,memo[a][x]-pref[x]);
		 	while (!v.empty() && v.back().se<=temp.se) v.pop_back();
		 	v.push_back(temp);
			
			memo[b][x]=memo[b][x-1];
			for (auto &it:ranges[x]){
				memo[b][x]=max(memo[b][x],(*lower_bound(all(v),ii(it-1,-1e9))).se+pref[x]);
			}
		}
		
		swap(a,b);
	}
	
	return memo[a][n]>=k;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>s>>m>>k;
	rep(x,1,n+1){
		cin>>arr[x];
	}
	
	int a,b;
	rep(x,0,s){
		cin>>a>>b;
		ranges[b].push_back(a);
	}
	
	int lo=0,hi=1e9+10,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) hi=mi;
		else lo=mi;
	}
	
	if (hi==1e9+10) cout<<"-1"<<endl;
	else cout<<hi<<endl;
}