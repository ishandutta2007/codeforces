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
#define iii pair<ll,ii>
#define fi first
#define se second
//#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

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

int n,k;
vector<ii> al[100005];
int arr[100005];

int memo[40][200005];
int val[40][100005];
int op[40][100005];
int op2[40][100005];

int dfs(int i,int p,int d,int id){
	if (memo[d][id]!=-1) return memo[d][id];
	
	int res=0;
	
	if (val[d][i]!=-1){
		res=val[d][i];
		res^=dfs(op[d][i],i,(d+1)%(2*k),op2[d][i]);
		res^=dfs(p,i,(d+1)%(2*k),id^1);
	}
	else{
		if (d<k) res=arr[i];
		
		op[d][i]=p;
		op2[d][i]=(id^1);
		
		for (auto &it:al[i]) if (it.fi!=p){
			res^=dfs(it.fi,i,(d+1)%(2*k),it.se);
		}
		
		val[d][i]=res;
	}
	
	return memo[d][id]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	int a,b;
	
	int cnt=0;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(ii(b,cnt++));
		al[b].pub(ii(a,cnt++));
	}
	
	rep(x,1,n+1) cin>>arr[x];
	
	memset(memo,-1,sizeof(memo));
	memset(val,-1,sizeof(val));
	
	rep(x,1,n+1){
		int res=0;
		for (auto &it:al[x]) res^=dfs(it.fi,x,(k+1)%(2*k),it.se);
		
		cout<<(!!res)<<" ";
	}
}