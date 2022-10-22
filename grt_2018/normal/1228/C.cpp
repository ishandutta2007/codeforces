#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int mod = 1e9+7;
int x;
ll n;
vi primes;

ll fast(int a, ll b) {
	int w = 1;
	ll p = a;
	while(b>0) {
		if(b&1) w=(ll)w*p%mod;
		p = (ll)p*p%mod;
		b/=2;
	}
	return w;
}

int ans = 1;

int main() {_
	cin>>x>>n;
	int y = x;
	for(int i=2; i*i<=x; i++) {
		if(y%i==0) primes.PB(i);
		while(y%i==0) {
			y/=i;
		}
	}
	if(y>1) primes.PB(y);
	for(int p:primes) {
		ll r = p;
		//ll s = 0;
		while(r<=n) {
			//s+=r/p;
			ans = (ll)ans*(fast(p,n/r))%mod;
			if(r>(n-1)/p+1) break;
			r*=p;
		}
		//s = n/(r/p) * s;
		//cout<<p<<" "<<s<<"\n";
	}
	cout<<ans;
			
}