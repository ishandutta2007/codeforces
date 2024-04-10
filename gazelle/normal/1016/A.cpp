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
	REP(i,n) cin>>a[i];
	vector<ll> t(n);
	ll modul=m;
	REP(i,n) {
		if(a[i]<modul) {
			modul-=a[i];
			t[i]=0;
		} else {
			a[i]-=modul;
			modul=m;
			t[i]=1;
			modul=m-a[i]%m;
			t[i]+=a[i]/m;
		}
	}
	DUMP(t);
	return 0;
}