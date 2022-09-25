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

int n;
vector<int> al[200005];

ii memo[200005][2];
ii dfs(int i,int p,int k){
	if (memo[i][k]!=ii(-1,-1)) return memo[i][k];
	
	ii res;
	if (k) res={1,-sz(al[i])};
	else res={0,0};
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		ii temp={-1,-1};
		rep(x,0,2-k) temp=max(temp,dfs(it,i,x));
		res.fi+=temp.fi,res.se+=temp.se;
	}
	
	return memo[i][k]=res;
}

int ans[200005];

void rec(int i,int p,int k){
	if (k) ans[i]=sz(al[i]);
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		if (k==0){
			if (dfs(it,i,0)>dfs(it,i,1)) rec(it,i,0);
			else rec(it,i,1);
		}
		else{
			rec(it,i,0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	if (n==2){
		cout<<2<<" "<<2<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	
	memset(memo,-1,sizeof(memo));
	
	auto temp=max(dfs(1,-1,0),dfs(1,-1,1));
	
	rep(x,1,n+1) ans[x]=1;
	
	if (dfs(1,-1,0)>dfs(1,-1,1)) rec(1,-1,0);
	else rec(1,-1,1);
	
	cout<<temp.fi<<" "<<(n-temp.fi)-temp.se<<endl;
	rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
}