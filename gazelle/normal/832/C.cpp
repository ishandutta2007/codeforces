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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define REP(i, m) for(long long i=0; i<m; ++i)
#define FOR(i, n, m) for(long long i=n; i<m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<ll> vl;
typedef vector<vector<ll> > vll;

int main() {
	ios::sync_with_stdio(false);
	ll n,s;
	cin>>n>>s;
	vector<P> lp;
	vector<P> rp;
	REP(i,n) {
		ll x,v,t;
		cin>>x>>v>>t;
		if(t==1) lp.pb(P(x,v));
		if(t==2) rp.pb(P(x,v));
	}
	ld lb=1e6,ub=0;
	int c=0;
	while(c<150) {
		ld mid=(lb+ub)/2.0;
		vector<P> l;
		vector<P> r;
		REP(i,lp.size()) {
			ld x=lp[i].first;
			ld v=lp[i].second;
			if((ld)x/(ld)v<=mid) {
				ll lk=0;
				ll rk=1e6;
				l.pb(P(lk,rk));
			} else if((ld)x/(ld)(s+v)<=mid) {
				ll lk=x;
				ll rk=min((ll)1e6,(ll)(((s*s-v*v)*mid+v*x)/(ld)s));
				l.pb(P(lk,rk));
			} else continue;
		}
		REP(i,rp.size()) {
			ld x=1e6-rp[i].first;
			ld v=rp[i].second;
			if((ld)x/(ld)v<=mid) {
				ld lk=0;
				ld rk=1e6;
				r.pb(P(1e6-rk,1e6-lk));
			} else if((ld)x/(ld)(s+v)<=mid) {
				ll lk=x;
				ll rk=min((ll)1e6,(ll)(((s*s-v*v)*mid+v*x)/(ld)s));
				r.pb(P(1e6-rk,1e6-lk));
			} else continue;
		}
		sort(ALL(l));
		sort(ALL(r));
		bool g=false;
		ll roc=0;
		REP(i,l.size()) {
			while(roc<r.size()&&r[roc].first<l[i].first) {
				ld pos=r[roc].second;
				if(pos>=l[i].first) g=true;
				++roc;
			}
			while(roc<r.size()&&r[roc].first<=l[i].second) {
				g=true;
				++roc;
			}
		}
		if(g) lb=mid;
		else ub=mid;
		++c;
	}
	cout<<fixed<<setprecision(100)<<showpoint<<lb<<endl;
}