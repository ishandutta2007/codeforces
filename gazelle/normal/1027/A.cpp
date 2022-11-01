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
	ll t;
	cin>>t;
	REP(testcase,t) {
		ll n;
		cin>>n;
		string s;
		cin>>s;
		bool d=true;
		REP(i,n/2) {
			char a=s[i],b=s[n-1-i];
			if(!(a==b||a+1==b-1||a-1==b+1)) d=false;
		}
		if(d) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}