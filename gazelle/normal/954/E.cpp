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
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
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
	vector<P> w(n);
	REP(i,n) cin>>w[i].first;
	REP(i,n) cin>>w[i].second;
	ll sum1=0,sum2=0;
	REP(i,n) sum1+=w[i].first*w[i].second;
	REP(i,n) sum2+=w[i].first;
	if(sum1==sum2*T) {
		cout<<sum2<<endl;
		return 0;
	}
	if(sum1>sum2*T) {
		vector<P> w1;
		vector<P> w2;
		REP(i,n) {
			if(w[i].second>T) w1.pb(w[i]);
			else w2.pb(w[i]);
		}
		REP(i,w1.size()) swap(w1[i].first,w1[i].second);
		sort(ALL(w1));
		REP(i,w1.size()) swap(w1[i].first,w1[i].second);
		ll num=0,den=0;
		REP(i,w2.size()) {
			num+=w2[i].first*w2[i].second;
			den+=w2[i].first;
		}
		if(den==0) {
			cout<<0<<endl;
			return 0;
		}
		REP(i,w1.size()) {
			if(num+w1[i].first*w1[i].second<=(den+w1[i].first)*T) {
				num+=w1[i].first*w1[i].second;
				den+=w1[i].first;
				continue;
			}
			ld l=0, r=w1[i].first;
			ll c=0;
			while(c<100) {
				ld mid=(l+r)/2;
				if(num+mid*w1[i].second<=(den+mid)*T) l=mid;
				else r=mid;
				c++;
			}
			cout<<fixed<<setprecision(39)<<den+l<<endl;
			return 0;
		}
		cout<<den<<endl;
	} else {
		vector<P> w1;
		vector<P> w2;
		REP(i,n) {
			if(w[i].second>=T) w1.pb(w[i]);
			else w2.pb(w[i]);
		}
		REP(i,w2.size()) swap(w2[i].first,w2[i].second);
		sort(ALL(w2));
		reverse(ALL(w2));
		REP(i,w2.size()) swap(w2[i].first,w2[i].second);
		ll num=0,den=0;
		REP(i,w1.size()) {
			num+=w1[i].first*w1[i].second;
			den+=w1[i].first;
		}
		if(den==0) {
			cout<<0<<endl;
			return 0;
		}
		REP(i,w2.size()) {
			if(num+w2[i].first*w2[i].second>=(den+w2[i].first)*T) {
				num+=w2[i].first*w2[i].second;
				den+=w2[i].first;
				continue;
			}
			ld l=0, r=w2[i].first;
			ll c=0;
			while(c<100) {
				ld mid=(l+r)/2;
				if(num+mid*w2[i].second>=(den+mid)*T) l=mid;
				else r=mid;
				c++;
			}
			cout<<fixed<<setprecision(39)<<den+l<<endl;
			return 0;
		}
		cout<<den<<endl;
	}
}