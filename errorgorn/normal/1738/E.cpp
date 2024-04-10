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

int n;
int arr[100005];
int brr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		int sum=0;
		rep(x,1,n+1) sum+=arr[x];
		
		rep(x,1,n+1) brr[x]=brr[x-1]+arr[x];
		
		//rep(x,1,n) cout<<brr[x]<<" "; cout<<endl;
		
		map<int,int> m;
		rep(x,1,n) m[brr[x]]++;
		
		int ans=1;
		for (auto [a,b]:m) if (2*a<=sum){
			if (2*a==sum) ans=ans*qexp(2,b,MOD)%MOD;
			else if (m.count(sum-a)){
				int b1=b,b2=m[sum-a];
				
				int curr=0;
				rep(x,0,min(b1,b2)+1) curr=(curr+nCk(b1,x)*nCk(b2,x))%MOD;
				ans=ans*curr%MOD;
			}
		}
		
		cout<<ans<<endl;
	}
}