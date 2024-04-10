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

struct UFDS{
	int p[100005];
	int s[100005];
	
	UFDS(){
		rep(x,0,100005){
			p[x]=x;
			s[x]=1;
		}
	}
	
	int par(int i){
		if (p[i]==i) return i;
		else return p[i]=par(p[i]);
	}
	
	int unions(int i,int j){
		i=par(i),j=par(j);
		int res=s[i]*s[j]%MOD;
		p[i]=j;
		s[j]+=s[i];
		return res;
	}
} ufds;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int n; cin>>n;
	
	int ans=1;
	
	rep(x,1,n) ans=ans*(2*x-1)%MOD;
	
	rep(x,1,n){
		int a,b;
		cin>>a>>b;
		
		int temp=ufds.unions(a,b);
		ans=ans*temp%MOD*temp%MOD;
	}
	
	cout<<ans<<endl;
}