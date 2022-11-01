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
#include<time.h>
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

void primer(ll x, vector<ll>& prim) {
	while(x>1) {
		bool upd=false;
		for(ll i=2; i*i<=x; i++) {
			if(x%i==0) {
				prim.pb(i);
				x/=i;
				upd=true;
				break;
			}
		}
		if(!upd) {
			prim.pb(x);
			break;
		}
	}
	sort(ALL(prim));
	prim.erase(unique(ALL(prim)),prim.end());
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll x;
	cin>>x;
	ll ans=INF*INF;
	vector<ll> prim;
	primer(x,prim);
	REP(roop,(ll)prim.size()) {
		ll p=prim[roop];
		ll l=x-p+1,r=x;
		FOR(i,l,r+1) {
			if(i<3) continue;
			vector<ll> tmp;
			primer(i,tmp);
			if(tmp[0]==i) continue;
			REP(j,(ll)tmp.size()) {
				ans=min(ans,max(3ll,i-tmp[j]+1));
			}
		}
	}
	cout<<ans<<endl;
}