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
 
const int MOD=998244353;
 
ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}
 
int n,m;
char grid[2005][2005];
 
int w[4005];
vector<int> al[4005];
 
bool vis[4005];
int ss,par,edges;
 
void dfs(int i){
	if (vis[i]) return;
	vis[i]=true;
	
	ss++;
	par^=w[i];
	edges+=sz(al[i]);
	
	for (auto it:al[i]) dfs(it);
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	
	if (n%2>m%2){
	    swap(n,m);
		rep(x,0,2005) rep(y,0,2005) if (x<y) swap(grid[x][y],grid[y][x]);
	}
	
	// rep(x,0,n){
		// rep(y,0,m) cout<<grid[x][y]<<" "; cout<<endl;
	// }
	
	if (n%2==0 && m%2==0){
		int cnt=0;
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='?') cnt++;
		cout<<qexp(2,cnt,MOD)<<endl;
	}
	else if (n%2==0 && m%2==1){
		int cnt0=1,cnt1=1;
		
		rep(x,0,n){
			int val=0;
			int cnt=0;
			rep(y,0,m){
				if (grid[x][y]=='?') cnt++;
				else val^=grid[x][y]-'0';
			}
			if (cnt==0){
				if (val==0) cnt1=0;
				else cnt0=0;
			}
			else{
				cnt0=(cnt0*qexp(2,cnt-1,MOD))%MOD;
				cnt1=(cnt1*qexp(2,cnt-1,MOD))%MOD;
			}
		}
		
		cout<<(cnt1+cnt0)%MOD<<endl;
	}
	else{
		rep(x,0,n) rep(y,0,m){
			if (grid[x][y]!='?'){
				w[x]^=grid[x][y]-'0';
				w[y+n]^=grid[x][y]-'0';
			}
			else{
				al[x].pub(y+n);
				al[y+n].pub(x);
			}
		}
		
		int cnt0=1,cnt1=1;
		
		rep(x,0,n+m) if (!vis[x]){
			ss=0,par=0,edges=0;
			dfs(x);
			edges/=2;
			edges-=ss-1; //extra edge
			
			int mul=qexp(2,edges,MOD);
			
			if (ss%2==0){
				if (par) mul=0;
				cnt0=(cnt0*mul)%MOD;
				cnt1=(cnt1*mul)%MOD;
			}
			else{
				if (par==0){
					cnt0=(cnt0*mul)%MOD;
					cnt1=0;
				}
				else{
					cnt0=0;
					cnt1=(cnt1*mul)%MOD;
				}
			}
		}
		
		cout<<(cnt0+cnt1)%MOD<<endl;
	}
}