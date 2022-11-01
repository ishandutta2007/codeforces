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
	ll n,k;
	cin>>n>>k;
	string t;
	cin>>t;
	string s="";
	string tmp=t;
	REP(i,n-1) {
		bool d=true;
		REP(j,i+1) {
			if(t[j]==t[n-1-i+j]) ;
			else {
				d=false;
			}
		}
		if(d) {
			tmp=t.substr(0,n-(i+1));
		}
	}
	REP(i,k-1) s+=tmp;
	s+=t;
	cout<<s<<endl;
}