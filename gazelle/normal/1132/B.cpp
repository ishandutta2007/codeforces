#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef long double ld;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(int i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	sort(ALL(a));
	ll sum = 0; REP(i, n) sum += a[i];
	ll m;
	cin >> m;
	REP(i, m) {
		ll q;
		cin >> q;
		cout << sum - a[n - q] << endl;
	}
	return 0;
}
/* --------------------------------------- */