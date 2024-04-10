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
long long arr[1000005]; //initialize to 0, this is 1-indexed
void update(int i,long long j){ //adds j to ith term
    while (i<1000005){
        arr[i]=(arr[i]+j)%MOD;
        i+=(i&(-i));
    }
}
void update(int i,int j,int k){
	update(i,k);
	update(j+1,MOD-k);
}
long long query(int i){ //calculate the sum of the 1-i terms
    long long k=0;
    while (i>0){
        k=(k+arr[i])%MOD;
        i-=(i&(-i));
    }
    return k;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int hf=inv(2);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) arr[x]=0;
		update(n,n,1);
		
		rep(x,n+1,3){
			int curr=query(x);
			update(x/2+1,x-1,curr);
		}
		
		rep(x,1,n+1) cout<<query(x)*qexp(hf,n-(x/2+1),MOD)%MOD<<" "; cout<<endl;
	}
}