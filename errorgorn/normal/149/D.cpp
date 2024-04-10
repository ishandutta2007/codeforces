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

const int MOD=1000000007;

string s;
int part[705];
ll memo[705][705][3][3];

ll dp(int l,int r,int c1,int c2){
	if (r<l) return 1;
	if (memo[l][r][c1][c2]!=-1) return memo[l][r][c1][c2];
	//cout<<l<<" "<<r<<" "<<c1<<" "<<c2<<endl;
	
	ll res=0;
	if (part[l]==r){
		rep(c,1,3){
			if (c!=c1) res=(res+dp(l+1,r-1,c,0))%MOD;
			if (c!=c2) res=(res+dp(l+1,r-1,0,c))%MOD;
		}
	}
	else{
		rep(c,1,3){
			if (c!=c1) res=(res+dp(l+1,part[l]-1,c,0)*dp(part[l]+1,r,0,c2))%MOD;
			res=(res+dp(l+1,part[l]-1,0,c)*dp(part[l]+1,r,c,c2))%MOD;
		}
	}
	
	return memo[l][r][c1][c2]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(memo,-1,sizeof(memo));
	
	cin>>s;
	
	vector<int> stk;
	rep(x,0,sz(s)){
		if (s[x]=='(') stk.push_back(x);
		else{
			part[stk.back()]=x;
			stk.pop_back();
		}
	}
	
	cout<<dp(0,sz(s)-1,0,0)<<endl;
}