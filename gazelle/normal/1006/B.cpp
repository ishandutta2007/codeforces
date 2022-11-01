#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	vector<P> a(n);
	REP(i,n) cin>>a[i].first;
	REP(i,n) a[i].second=i;
	sort(ALL(a));
	reverse(ALL(a));
	vector<ll> b;
	ll ans=0;
	REP(i,k) {
		ans+=a[i].first;
		b.pb(a[i].second);
	}
	sort(ALL(b));
	cout<<ans<<endl;
	ll pos=0;
	REP(i,k) {
		if(i==k-1) break;
		cout<<b[i]-pos+1;
		cout<<" ";
		pos=b[i]+1;
	}
	cout<<(n-1)-pos+1<<endl;
	return 0;
}