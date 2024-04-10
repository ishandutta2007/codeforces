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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,q;
	cin>>n>>q;
	REP(queri,q) {
		ll x,y;
		cin>>x>>y;
		if(x%2==y%2) {
			cout<<((x-1)*n+y+1)/2<<endl;
		} else {
			cout<<(n*n+1)/2+((x-1)*n+y+1-(((x-1)*n+y+2)/2))<<endl;
		}
	}
}