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
	vector<ll> a(n);
	REP(i,n) cin>>a[i];
	map<ll,ll> m;
	for(ll i=n-1; i>=0; i--) {
		if(m.count(a[i]+1)) m[a[i]]=max(m[a[i]],m[a[i]+1]+1);
		else m[a[i]]=1;
	}
	ll ans=0;
	for(auto x : m) {
		ans=max(ans,x.second);
	}
	ll pivo=-1;
	for(auto x : m) {
		if(x.second==ans) pivo=x.first;
	}
	vector<ll> v;
	REP(i,n) {
		if(a[i]==pivo) {
			v.pb(i+1);
			pivo++;
		}
	}
	cout<<ans<<endl;
	DUMP(v);
}