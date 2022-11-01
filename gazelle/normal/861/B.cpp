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
	ll n,m;
	cin>>n>>m;
	vector<P> f(m);
	REP(i,m) cin>>f[i].first>>f[i].second;
	sort(ALL(f));
	set<ll> q;
	FOR(i,1,10001) {
		bool d=true;
		REP(j,m) {
			if(!(f[j].second*i>=f[j].first&&(f[j].second-1)*i<f[j].first)) {
				d=false;
				break;
			}
		}
		if(d) q.insert((n-1)/i+1);
	}
	if(q.size()>1) cout<<-1<<endl;
	else cout<<*(q.begin())<<endl;
}