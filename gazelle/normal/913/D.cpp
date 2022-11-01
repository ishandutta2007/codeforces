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
	ll n,T;
	cin>>n>>T;
	vector<pair<P,ll>> a(n);
	REP(i,n) cin>>a[i].first.first>>a[i].first.second;
	REP(i,n) a[i].second=i;
	sort(ALL(a));
	reverse(ALL(a));
	set<P> s;
	ll pos=0;
	ll sum=0;
	ll ans=0;
	for(ll i=n; i>=1; i--) {
		while(pos<n&&a[pos].first.first>=i) {
			sum+=a[pos].first.second;
			s.insert(P(a[pos].first.second,a[pos].second));
			pos++;
		}
		while((ll)s.size()>i) {
			auto ite=s.end();
			ite--;
			sum-=(*ite).first;
			s.erase(ite);
		}
		while(sum>T) {
			auto ite=s.end();
			ite--;
			sum-=(*ite).first;
			s.erase(ite);
		}
		ans=max(ans,(ll)s.size());
	}
	if(ans==0) {
		cout<<0<<endl;
		cout<<0<<endl;
		return 0;
	}
	s.erase(ALL(s));
	pos=0;
	sum=0;
	for(ll i=n; i>=1; i--) {
		while(pos<n&&a[pos].first.first>=i) {
			sum+=a[pos].first.second;
			s.insert(P(a[pos].first.second,a[pos].second));
			pos++;
		}
		while((ll)s.size()>i) {
			auto ite=s.end();
			ite--;
			sum-=(*ite).first;
			s.erase(ite);
		}
		while(sum>T) {
			auto ite=s.end();
			ite--;
			sum-=(*ite).first;
			s.erase(ite);
		}
		if((ll)s.size()==ans) {
			cout<<ans<<endl;
			cout<<ans<<endl;
			vector<ll> answ;
			for(auto x: s) {
				answ.pb(x.second+1);
			}
			DUMP(answ);
			return 0;
		}
	}
}