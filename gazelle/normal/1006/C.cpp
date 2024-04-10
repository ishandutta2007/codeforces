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
	ll n;
	cin>>n;
	vector<ll> d(n);
	REP(i,n) cin>>d[i];
	ll ans=0;
	ll r=n-1;
	ll sum1=0;
	ll sum3=0;
	REP(i,n) {
		sum1+=d[i];
		if(sum3>sum1) continue;
		else if(sum3==sum1) ans=sum1;
		else {
			while(sum3<sum1) {
				sum3+=d[r];
				r--;
			}
			if(r<i) break;
			if(sum3==sum1) ans=sum1;
		}
	}
	cout<<ans<<endl;
	return 0;
}