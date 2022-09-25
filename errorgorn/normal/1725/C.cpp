//
//
//
//

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

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

int n,m;
int arr[600005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) arr[x+n]=arr[x];
	
	int dist=0;
	rep(x,0,n) dist+=arr[x];
	
	int tot=0,l=0;
	int p=0;
	rep(x,0,n){
		while (tot<dist/2) tot+=arr[l++];
		if (tot*2==dist) p++;
		tot-=arr[x];
	}
	
	p/=2;
	
	//cout<<p<<endl;
	
	int ans=0;
	
	rep(x,0,p+1){
		int rem=m-x;
		if (rem<0) break;
		
		ans=(ans+
			nCk(m,x)%MOD*fac[x]%MOD*nCk(p,x)%MOD*qexp(rem*(rem-1)%MOD,p-x,MOD)%MOD*qexp(rem,n-2*p,MOD)%MOD
		)%MOD;
	}
	
	cout<<ans<<endl;
}