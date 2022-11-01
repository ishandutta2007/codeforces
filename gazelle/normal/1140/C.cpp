#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
#include<bitset>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<pll> s(n);
	REP(i, n) cin >> s[i].second >> s[i].first;
	sort(ALL(s)); reverse(ALL(s));
	ll ans = 0, sum = 0;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	REP(i, n) {
		q.push(s[i].second); sum += s[i].second;
		if((ll)q.size() > k) {
			sum -= q.top();
			q.pop();
		}
		ans = max(ans, sum * s[i].first);
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */