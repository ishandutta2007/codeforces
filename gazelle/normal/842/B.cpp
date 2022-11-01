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
#define REP(i, m) for(long long i=0; i<m; ++i)
#define FOR(i, n, m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<ll> vl;
typedef vector<vector<ll> > vll;

int main() {
	ios::sync_with_stdio(false);
	ll r,d;
	cin>>r>>d;
	ll n;
	cin>>n;
	ll c=0;
	REP(i,n) {
		ll x,y,ri;
		cin>>x>>y>>ri;
		if(x*x+y*y>=(ri+(r-d))*(ri+(r-d))&&x*x+y*y<=(r-ri)*(r-ri)) ++c;
	}
	cout<<c<<endl;
}