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
	ll n;
	cin>>n;
	vector<ll> x(n);
	vector<ll> y(n);
	REP(i,n) cin>>x[i];
	REP(i,n) cin>>y[i];
	set<ll> s;
	REP(i,n) {
		s.insert(x[i]);
		s.insert(y[i]);
	}
	ll c=0;
	REP(i,n) {
		REP(j,n) {
			if(s.count(x[i]^y[j])!=0) c++;
		}
	}
	if(c%2==1) cout<<"Koyomi"<<endl;
	else cout<<"Karen"<<endl;
}