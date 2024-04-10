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

const float TAU=4*acos(0);

int n,k;
ii arr[100005];

int test(float r){
	r*=2;
	
	vector<float> f,b;
	
	int stupid=0;
	
	rep(x,0,n){
		float dist=arr[x].fi*arr[x].fi+arr[x].se*arr[x].se;
		
		if (dist==0) stupid++;
		else if (r*r<dist) ;
		else{
			float span=acos(sqrt(dist)/r);
			float angle=atan((float)arr[x].se/arr[x].fi);
			if (arr[x].fi<0) angle+=TAU/2;
			
			f.pub(angle-span),b.pub(angle+span);
			f.pub(angle-span+TAU),b.pub(angle+span+TAU);
		}
	}
	
	sort(all(f)),sort(all(b));
	reverse(all(f));
	
	int res=0;
	int curr=0;
	for (auto &it:b){
		while (!f.empty() && f.back()<it) curr++,f.pob();
		res=max(res,curr);
		curr--;
	}
	
	return res+stupid;
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
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	long double lo=0,hi=2e5,mi;
	while (hi-lo>9.9e-5){
		mi=(hi+lo)/2;
		
		if (test(mi)<k) lo=mi;
		else hi=mi;
	}
	
	cout<<hi<<endl;
	
}