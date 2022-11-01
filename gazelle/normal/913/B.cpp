#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<vector<ll>> adj(n);
	REP(i,n-1) {
		ll a;
		cin>>a;
		a--;
		adj[i+1].pb(a);
		adj[a].pb(i+1);
	}
	vector<bool> leaf(n,false);
	REP(i,n) {
		if((ll)adj[i].size()==1) leaf[i]=true;
	}
	REP(i,n) {
		if(leaf[i]) continue;
		ll cnt=0;
		REP(j,(ll)adj[i].size()) {
			if(leaf[adj[i][j]]) cnt++;
		}
		if(cnt<3) {
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}