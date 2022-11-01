#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 998244353ll
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
	ll n;
	cin>>n;
	string s;
	cin>>s;
	if(n==1) {
		cout<<"Yes"<<endl;
		return 0;
	}
	vector<ll> c(26,0);
	REP(i,n) c[s[i]-'a']++;
	ll cnt=0;
	REP(i,26) if(c[i]>=2) cnt++;
	if(cnt!=0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}