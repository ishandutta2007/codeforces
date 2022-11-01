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
#define EPS 1e-8
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;
typedef vector<P> vp;
typedef vector<vector<P> > vpp;
ll gcd(ll a, ll b) {		// 
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll extgcd(ll a, ll b, ll& x, ll& y) {		// 
	ll d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int resa=-1,resb=-1;
	ld maxi=0;
	FOR(i,1,n) {
		int a=(int)i;
		int b=(int)(n-i);
		if(a>=b) continue;
		if(gcd(a,b)!=1) continue;
		if(a/(ld)b>maxi) {
			maxi=a/(ld)b;
			resa=a;
			resb=b;
		}
	}
	cout<<resa<<" "<<resb<<endl;
}