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
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<P> a(n);
	REP(i,n) cin>>a[i].first;
	REP(i,n) a[i].second=i;
	sort(ALL(a));
	vector<P> b(n);
	REP(i,n) {
		b[a[i].second].first=a[i].first;
		b[a[i].second].second=i;
	}
	vector<ll> used(n,-1);
	vector<vector<ll> > res;
	ll num=0;
	REP(i,n) {
		if(used[i]==-1) {
			vector<ll> buf;
			buf.pb(i);
			used[i]=num;
			ll next=b[i].second;
			while(used[next]!=num) {
				buf.pb(next);
				used[next]=num;
				next=b[next].second;
			}
			++num;
			res.pb(buf);
		}
	}
	cout<<res.size()<<endl;
	REP(i,res.size()) {
		cout<<res[i].size()<<" ";
		REP(j,res[i].size()) {
			cout<<res[i][j]+1;
			if(j!=res[i].size()-1) cout<<" ";
			else cout<<endl;
		}
	}
}