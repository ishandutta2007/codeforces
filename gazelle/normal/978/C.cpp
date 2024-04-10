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
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> b(m);
	REP(i,n) cin>>a[i];
	REP(i,m) cin>>b[i];
	vector<ll> acm(n);
	acm[0]=a[0];
	FOR(i,1,n) acm[i]=acm[i-1]+a[i];
	REP(i,m) {
		ll l=-1,r=n;
		while(r-l>1) {
			ll m=(l+r)/2;
			if(acm[m]>=b[i]) r=m;
			else l=m;
		}
		if(r>0) cout<<r+1<<" "<<b[i]-acm[r-1]<<endl;
		else cout<<r+1<<" "<<b[i]<<endl;
	}
}