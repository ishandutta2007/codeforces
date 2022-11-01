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
	string a,b;
	cin>>a>>b;
	ll ans=0;
	REP(i,n) {
		ll p=(n-1)-i;
		if(i==p) {
			if(a[i]!=b[i]) ans+=2;
		} else {
			if(b[i]!=b[p]) {
				if((a[i]==b[i]&&a[p]==b[p])||(a[i]==b[p]&&a[p]==b[i])) ans+=0;
				else if(a[i]==b[i]||a[i]==b[p]||a[p]==b[i]||a[p]==b[p]) ans+=1;
				else ans+=2;
			} else {
				if(a[i]!=a[p]) ans+=1;
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}