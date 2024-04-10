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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	vector<ll> next(n,-1);
	vector<ll> sum(n);
	ll buf1=n;
	ll buf2=0;
	for(ll i=n-1; i>=0; i--) {
		if(a[i]!=1) {
			buf1=i;
			buf2=0;
		} else {
			next[i]=buf1;
			buf2++;
			sum[i]=buf2;
		}
	}
	ll ans=0;
	REP(i,n) {
		ll prd=1;
		ll s=0;
		ll pos=i;
		while(pos<n&&a[pos]<=INF*INF/(ld)prd) {
			if(a[pos]!=1) {
				prd*=a[pos];
				s+=a[pos];
				if(prd%s==0&&prd/s==k) ans++;
				pos++;
			} else {
				if(prd%k==0&&prd/k>s&&prd/k<=s+sum[pos]) ans++;
				s+=sum[pos];
				pos=next[pos];
			}
		}
	}
	cout<<ans<<endl;
}