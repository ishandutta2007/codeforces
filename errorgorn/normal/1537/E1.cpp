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

const int MOD=1000000007;
const int P=177013;

ll hh[30];

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

int n,k;
string s;
ll val[500005];

ll hval(int m,int l){
	if (l<=m) return val[l];
	else{
		int times=l/m;
		int r=qexp(P,m,MOD);
		return (val[m]*fix(1-qexp(r,times,MOD))%MOD*inv(fix(1-r))
				+qexp(r,times,MOD)*val[l%m])%MOD;
	}
}

bool cmp(int i,int j){
	int lo=0,hi=1e6,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (hval(i,mi)==hval(j,mi)) lo=mi;
		else hi=mi;
	}
	
	return s[lo%i]<s[lo%j];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,30) hh[x]=rng()%MOD;
	
	cin>>n>>k;
	cin>>s;
	
	rep(x,0,n) val[x+1]=(val[x]+qexp(P,x,MOD)*hh[s[x]-'a'])%MOD;
	
	int best=1;
	rep(x,2,n+1){
		if (cmp(x,best)){
			best=x;
		}
	}
	
	rep(x,0,k) cout<<s[x%best];
}