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

ll fac[400005];
ll ifac[400005];

int nCk(int i,int j){
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int calc(int i,int j){
	return (nCk(i+j,j)+MOD-1)%MOD;
}

string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fac[0]=1;
	rep(x,1,400005) fac[x]=fac[x-1]*x%MOD;
	rep(x,0,400005) ifac[x]=inv(fac[x]);
	
	cin>>s;
	
	int open=0;
	int close=0;
	
	rep(x,0,sz(s)) if (s[x]==')') close++;
	
	ll ans=0;
	rep(x,0,sz(s)){
		if (s[x]=='('){
			open++;
			
			//cout<<open<<" "<<close<<" "<<calc(open,close)-calc(open-1,close)<<endl;
			ans=(ans+calc(open,close)-calc(open-1,close)+MOD)%MOD;
		}
		if (s[x]==')') close--;
	}
	
	cout<<ans<<endl;
}