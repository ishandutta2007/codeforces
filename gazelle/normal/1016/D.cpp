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
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n);
	vector<ll> b(m);
	REP(i,n) cin>>a[i];
	REP(i,m) cin>>b[i];
	ll xor1=0,xor2=0;
	REP(i,n) xor1^=a[i];
	REP(i,m) xor2^=b[i];
	if(xor1!=xor2) {
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	vector<vector<ll>> ans(n,vector<ll>(m));
	REP(i,n-1) {
		ans[i][0]=a[i];
		b[0]^=a[i];
	}
	REP(i,m) ans[n-1][i]=b[i];
	REP(i,n) DUMP(ans[i]);
	return 0;
}