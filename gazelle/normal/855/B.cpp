#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,p,q,r;
	cin>>n>>p>>q>>r;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> dp_max1(n);
	vector<ll> dp_min1(n);
	vector<ll> dp_max2(n);
	vector<ll> dp_min2(n);
	dp_max1[n-1]=a[n-1];
	dp_min1[n-1]=a[n-1];
	dp_max2[0]=a[0];
	dp_min2[0]=a[0];
	for(ll i=n-2; i>=0; --i) {
		if(a[i]>dp_max1[i+1]) dp_max1[i]=a[i];
		else dp_max1[i]=dp_max1[i+1];
		if(a[i]<dp_min1[i+1]) dp_min1[i]=a[i];
		else dp_min1[i]=dp_min1[i+1];
	}
	for(ll i=1; i<n; ++i) {
		if(a[i]>dp_max2[i-1]) dp_max2[i]=a[i];
		else dp_max2[i]=dp_max2[i-1];
		if(a[i]<dp_min2[i-1]) dp_min2[i]=a[i];
		else dp_min2[i]=dp_min2[i-1];
	}
	ll x=-(1ll<<63);
	REP(i,n) {
		ll buf=q*a[i];
		if(p<0) buf+=p*dp_min2[i];
		else buf+=p*dp_max2[i];
		if(r<0) buf+=r*dp_min1[i];
		else buf+=r*dp_max1[i];
		x=max(x,buf);
	}
	cout<<x<<endl;
}