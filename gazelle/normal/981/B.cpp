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
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-10
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	map<ll,ll> m1;
	REP(i,n) {
		ll a,x;
		cin>>a>>x;
		m1[a]=x;
	}
	ll m;
	cin>>m;
	map<ll,ll> m2;
	REP(i,m) {
		ll b,y;
		cin>>b>>y;
		m2[b]=y;
	}
	ll ans=0;
	for(auto tmp: m1) {
		ll a=tmp.first;
		ll x=tmp.second;
		if(!m2.count(a)) ans+=x;
		else {
			if(m2[a]<x) ans+=x;
		}
	}
	for(auto tmp: m2) {
		ll b=tmp.first;
		ll y=tmp.second;
		if(!m1.count(b)) ans+=y;
		else {
			if(m1[b]<=y) ans+=y;
		}
	}
	cout<<ans<<endl;
}