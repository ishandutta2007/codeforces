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

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

const int dx[]={0, 0,1,-1,-1,-1, 1,1};
const int dy[]={1,-1,0, 0,-1, 1,-1,1};

int n,m;
string grid[505];
int deg[505][505];
int w[505][505];

void dfs(int i,int j){
	rep(z,0,8){
		int a=i+dx[z],b=j+dy[z];
		if (a<0 || n<=a || b<0 || m<=b) continue;
		
		if (w[a][b]==-1){
			if (grid[a][b]=='X'){
				if (deg[a][b]!=2 || z>=4) continue;
				a+=dx[z],b+=dy[z];
				if (grid[a][b]!='X' && w[a][b]==-1){
					w[a][b]=w[i][j]^1;
					dfs(a,b);
				}
			}
			else{
				w[a][b]=w[i][j];
				dfs(a,b);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='X') rep(z,0,4){
		if (grid[x+dx[z]][y+dy[z]]=='X') deg[x][y]++;
	}
	
	memset(w,-1,sizeof(w));
	
	w[0][0]=0;
	dfs(0,0);
	
	rep(x,0,n) if (x%2==0){
		rep(y,0,m) w[x][y]^=1;
	}
	
	rep(x,0,n) rep(y,0,m) if (w[x][y]==0) w[x][y]=4;
	
	bool bad=false;
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='X'){
		w[x][y]=0;
		rep(z,0,4) if (grid[x+dx[z]][y+dy[z]]=='.'){
			w[x][y]+=w[x+dx[z]][y+dy[z]];
		}
		if (w[x][y]%5) bad=true;
	}
	
	if (bad){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	
	rep(x,0,n){
		rep(y,0,m) cout<<w[x][y]<<" "; cout<<endl;
	}
	
}