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
#include<bitset>
#include<random>
#include<time.h>
#define INF 1000000000ll
#define MOD 1000000007ll
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
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	vector<ll> t(n);
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>t[i];
	vector<ll> acm(n+1,0);
	FOR(i,1,n+1) {
		if(t[i-1]==0) acm[i]=acm[i-1]+a[i-1];
		else acm[i]=acm[i-1];
	}
	ll ans=0;
	REP(i,n) if(t[i]) ans+=a[i];
	ll maxi=0;
	REP(i,n) {
		if(i+k<=n) maxi=max(maxi,acm[i+k]-acm[i]);
	}
	cout<<ans+maxi<<endl;
}