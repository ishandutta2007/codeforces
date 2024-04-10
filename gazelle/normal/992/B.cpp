#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll l,r,x,y;
	cin>>l>>r>>x>>y;
	if(y%x!=0) {
		cout<<0<<endl;
		return 0;
	}
	ll z=y/x;
	ll ans=0;
	for(ll i=1; i*i<=z; i++) {
		if(z%i) continue;
		ll a=i,b=z/i;
		if(gcd(a,b)!=1) continue;
		if(a*x>=l&&a*x<=r&&b*x>=l&&b*x<=r) {
			if(a!=b) ans+=2;
			else ans++;
		}
	}
	cout<<ans<<endl;
}