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

ll N = 10101;
ll bit[10101];
void add(ll a, ll w) {
	a++;
	for (ll x = a; x <= N; x += x & -x) bit[x] += w;
}
ll sum(ll a) {
	a++;
	ll ret = 0;
	for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
	return ret;
}
// return the sum of [a, b)
ll sum(ll a, ll b) {
	ll ret = 0;
	if(b == 0) return 0;
	ret += sum(b - 1);
	if(a) ret -= sum(a - 1);
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	vector<ll> l(q), r(q);
	REP(i, q) cin >> l[i] >> r[i];
	REP(i, q) {
		l[i]--;
		r[i]--;
	}
	ll ans = 0;
	vector<ll> summ(n, 0);
	REP(i, q) {
		FOR(j, l[i], r[i] + 1) summ[j]++;
	}
	REP(i, q) {
		REP(j, 10101) bit[j] = 0;
		FOR(j, l[i], r[i] + 1) summ[j]--;
		ll tmp = 0;
		REP(j, n) {
			if(summ[j] >= 1) tmp++;
			if(summ[j] == 1) add(j, 1);
		}
		REP(j, q) {
			if(i == j) continue;
			ans = max(ans, tmp - sum(l[j], r[j] + 1));
		}
		FOR(j, l[i], r[i] + 1) summ[j]++;
	}
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */