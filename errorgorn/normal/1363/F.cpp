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

int TC;

int n;
string s,t;
int scnt[2005][30];
int tcnt[2005][30];

int last[2005][2005][2];
ll memo[2005][2005][2];

ll dp(int i,int j,int real){
	if (i==n) return 0;
	if (j==n) return 1e18;
	if (last[i][j][real]==TC) return memo[i][j][real];
	last[i][j][real]=TC;
	
	ll res;
	if (real==0){
		res=min(dp(i+1,j,0)+1,dp(i,j,1));
	}
	else{
		rep(x,0,26) if (scnt[j][x]>tcnt[i][x]){
			return memo[i][j][real]=1e18;
		}
		if (t[i]==s[j]) res=dp(i+1,j+1,0);
		else res=dp(i,j+1,0);
	}
	
	//cout<<i<<" "<<j<<" "<<real<<" "<<res<<endl;
	return memo[i][j][real]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(last,-1,sizeof(last));
	
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s>>t;
		
		rep(x,0,n){
			rep(y,0,26){
				scnt[x][y]=(x?scnt[x-1][y]:0)+(s[x]-'a'==y);
				tcnt[x][y]=(x?tcnt[x-1][y]:0)+(t[x]-'a'==y);
			}
		}
		
		ll res=dp(0,0,0);
		
		sort(all(s)),sort(all(t));
		
		if (s==t) cout<<res<<endl;
		else cout<<"-1"<<endl;
	}
}