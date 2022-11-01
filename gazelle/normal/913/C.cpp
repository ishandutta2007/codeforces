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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,l;
	cin>>n>>l;
	vector<ll> c(32,INF*INF);
	REP(i,n) cin>>c[i];
	FOR(i,1,32) {
		REP(j,i) {
			c[i]=min(c[i],(1ll<<(i-j))*c[j]);
		}
	}
	ll ans=INF*INF;
	ll buf=0;
	bitset<32> bi(l);
	for(ll i=31; i>=0; i--) {
		if(bi[i]==0) {
			ans=min(ans,buf+c[i]);
		} else {
			buf+=c[i];
		}
	}
	ans=min(ans,buf);
	cout<<ans<<endl;
}