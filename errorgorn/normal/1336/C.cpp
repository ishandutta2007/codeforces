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

const int MOD=998244353;

string s,t;

int memo[3005][3005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s>>t;
	
	rep(x,0,s.size()){
		if (t.size()<=x || t[x]==s[0]) memo[x][x]=2;
		//cout<<x<<" "<<x<<" "<<memo[x][x]<<endl;
	}
	
	rep(x,1,s.size()){
		rep(y,x,s.size()){
			if (t.size()<=y-x || t[y-x]==s[x]) memo[y-x][y]=(memo[y-x][y]+memo[y-x+1][y])%MOD;
			if (t.size()<=y || t[y]==s[x]) memo[y-x][y]=(memo[y-x][y]+memo[y-x][y-1])%MOD;
			//cout<<y-x<<" "<<y<<" "<<memo[y-x][y]<<endl;
		}
	}
	
	int ans=0;
	rep(x,t.size()-1,s.size()) ans=(ans+memo[0][x])%MOD;
	cout<<ans<<endl;
}