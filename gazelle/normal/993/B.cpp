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
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
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

ll match(P p1, P p2) {
	if(p1.first==p2.first&&p1.second!=p2.second) return p1.first;
	if(p1.first==p2.second&&p1.second!=p2.first) return p1.first;
	if(p1.second==p2.first&&p1.first!=p2.second) return p1.second;
	if(p1.second==p2.second&&p1.first!=p2.first) return p1.second;
	else return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<P> p1(n);
	vector<P> p2(m);
	REP(i,n) cin>>p1[i].first>>p1[i].second;
	REP(i,m) cin>>p2[i].first>>p2[i].second;
	set<ll> num;
	REP(i,n) {
		set<ll> sum;
		ll pos=-1;
		REP(j,m) {
			ll buf=match(p1[i],p2[j]);
			if(buf!=-1) {
				sum.insert(buf);
				pos=buf;
			}
		}
		if((ll)sum.size()>1) {
			cout<<-1<<endl;
			return 0;
		}
		if((ll)sum.size()==1) num.insert(pos);
	}
	REP(i,m) {
		set<ll> sum;
		ll pos=-1;
		REP(j,n) {
			ll buf=match(p2[i],p1[j]);
			if(buf!=-1) {
				sum.insert(buf);
				pos=buf;
			}
		}
		if((ll)sum.size()>1) {
			cout<<-1<<endl;
			return 0;
		}
		if((ll)sum.size()==1) num.insert(pos);
	}
	if((ll)num.size()>1) cout<<0<<endl;
	else {
		auto ite=num.begin();
		cout<<*ite<<endl;
	}
}