// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
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

int n,m,q;
bool has[13][13];
int lca[13][13];
int memo[8192][13];

int dp(int bm,int i){
	rep(x,0,13) if (bm&(1<<x)){
		if (lca[x][i]!=-1 && lca[x][i]!=i) return 0;
	}
	if (bm==0) return 1;
	if (memo[bm][i]!=-1) return memo[bm][i];
	
	int ans=0;
	for (int bm2=bm;bm2;bm2=(bm2-1)&bm){
		if ((bm2&(bm&-bm))==0) continue;
		
		int com=bm^bm2;
		
		bool ok=true;
		rep(x,0,13) rep(y,0,13) if ((bm2&(1<<x)) && (com&(1<<y))){
			if (lca[x][y]!=-1 && lca[x][y]!=i) ok=false;
			if (has[x][y]) ok=false;
		}
		
		rep(x,0,13) rep(y,0,13) if ((bm2&(1<<x)) && (bm2&(1<<y))){
			if (lca[x][y]!=-1 && (bm2&(1<<lca[x][y]))==0) ok=false;
		}
		
		int r=-1;
		rep(x,0,13) if (bm2&(1<<x) && has[x][i]){
			if (r!=-1) ok=false;
			r=x;
		}
		
		if (!ok) continue;
		
		if (r!=-1) ans=(ans+dp(bm2^(1<<r),r)*dp(com,i));
		else{
			rep(x,0,13) if (bm2&(1<<x)){
				ans=(ans+dp(bm2^(1<<x),x)*dp(com,i));
			}
		}
	}
	
	return memo[bm][i]=ans;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b;
		a--,b--,c--;
		has[a][b]=has[b][a]=true;
	}
	
	memset(lca,-1,sizeof(lca));
	rep(x,0,q){
		cin>>a>>b>>c;
		a--,b--,c--;
		if (a==b && a!=c){
			cout<<0<<endl;
			return 0;
		}
		if (lca[a][b]!=-1 && lca[a][b]!=c){
			cout<<0<<endl;
			return 0;
		}
		lca[a][b]=lca[b][a]=c;
	}
	
	memset(memo,-1,sizeof(memo));
	cout<<dp((1<<n)-2,0)<<endl;
}