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

int n;
int arr[4005];
int memo[4005][2005];
vector<int> val;

int dp(int i,int j){
	if (memo[i][j]!=-1) return memo[i][j];
	if (i==sz(val)){
		return (j==0);
	}
	
	bool res;
	if (j<val[i]) res=dp(i+1,j);
	else res=dp(i+1,j)|dp(i+1,j-val[i]);
	
	return memo[i][j]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		val.clear();
		rep(x,0,2*n+5){
			rep(y,0,2005) memo[x][y]=-1;
		}
		
		rep(x,0,2*n) cin>>arr[x];
		
		int curr=0;
		int big=0;
		
		rep(x,0,2*n){
			if (big<arr[x]){
				val.push_back(curr);
				big=arr[x];
				curr=1;
			}
			else{
				curr++;
			}
		}
		val.push_back(curr);
		
		//for (auto &it:val) cout<<it<<" ";cout<<endl;
		
		if (dp(0,n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}