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

int a[300005];
int b[300005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	a[0]=1,a[1]=1;
	rep(x,2,300005) a[x]=(a[x-1]+(x-1)*a[x-2])%MOD;
	
	int curr=1;
	rep(x,0,300005) if (x%4==0){
		if (x) curr=(curr*(x/2-1))%MOD;
		b[x]=curr;
		curr=(curr*2)%MOD;
	}
	
	// rep(x,1,11) cout<<a[x]<<" "; cout<<endl;
	// rep(x,1,11) cout<<b[x]<<" "; cout<<endl;
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		cin>>n;
		
		int ans=0;
		rep(x,0,n+1) if (x%4==0){
			//n-x/2 things, choose x/2 things
			
			ans=(ans+nCk(n-x/2,x/2)*a[n-x]%MOD*b[x])%MOD;
		}
		
		cout<<ans<<endl;
	}
	
}