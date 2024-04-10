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
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; ++i)
#define FOR(i,n,m) for(long long i=n; i<m; ++i)
#define DUMP(n,a) for(long long dump=0; dump<n; ++dump) { cout<<a[dump]; if(dump!=n-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n,k;
	cin>>n>>k;
	set<vector<ll>> s;
	vector<vector<ll>> vec;
	REP(i,n) {
		vector<ll> a(k);
		REP(j,k) cin>>a[j];
		if(s.count(a)==0) {
			vec.pb(a);
			s.insert(a);
		}
	}
	REP(bit,(1<<(int)(vec.size()))) {
		ll cnt=0;
		for(ll i=bit; i>0; i/=2) {
			if(i%2==1) cnt++;
		}
		if(cnt==0) continue;
		ll buf=bit;
		vector<ll> c(k,0);
		REP(i,vec.size()) {
			if(buf%2==1) {
				REP(j,k) {
					c[j]+=vec[i][j];
				}
			}
			buf/=2;
		}
		bool d=true;
		REP(i,k) {
			if(c[i]*2>cnt) d=false;
		}
		if(d) {
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}