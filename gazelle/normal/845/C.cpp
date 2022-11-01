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
#include<complex>
#include<unordered_map>

#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	int n;
	cin>>n;
	vector<P> p(n);
	REP(i,n) cin>>p[i].first>>p[i].second;
	sort(ALL(p));
	bool d=true;
	priority_queue<ll, vector<ll>, greater<ll> > q;
	REP(i,n) {
		if(q.size()<2) q.push(p[i].second);
		else {
			ll e=q.top();
			q.pop();
			if(e>=p[i].first)d=false;
			q.push(p[i].second);
		}
	}
	if(d) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}