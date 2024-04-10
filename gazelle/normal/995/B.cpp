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

ll N = 110;
ll bit[110];
void add(ll a, ll w) {
	for (ll x = a; x <= N; x += x & -x) bit[x] += w;
}
ll sum(ll a) {
	ll ret = 0;
	for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> a(2*n);
	REP(i,2*n) cin>>a[i];
	REP(i,2*n) a[i]--;
	ll ans=0;
	vector<ll> wariate(n,-1);
	ll cnt=0;
	REP(i,2*n) {
		if(wariate[a[i]]==-1) {
			wariate[a[i]]=cnt+1;
			cnt++;
		}
	}
	for(ll i=2*n-1; i>=0; i--) {
		if(wariate[a[i]]!=1) ans+=sum(wariate[a[i]]-1);
		add(wariate[a[i]],1);
	}
	cout<<ans<<endl;
}