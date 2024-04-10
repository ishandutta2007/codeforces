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
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int n, k;
ll a[202020];
int b[202020];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> k;
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	ll l = -1, r = INF * INF;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
		REP(i, n) q.push(make_pair(a[i] / (ld)b[i], i));
		bool ok = true;
		REP(i, k - 1) {
			double t = q.top().first;
			int idx = q.top().second;
			q.pop();
			if(t < i - EPS) {
				ok = false;
			}
			t += m / (ld)b[idx];
			q.push(make_pair(t, idx));
		}
		double t = q.top().first;
		if(t < k - 1 - EPS) ok = false;
		if(ok) r = m;
		else l = m;
	}
	if(r == INF * INF) cout << -1 << endl;
	else cout << r << endl;
	return 0;
}
/* --------------------------------------- */