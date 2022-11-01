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
#include<cassert>
#include<random>
using namespace std;
using lint = long long;
using ld = long double;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(lint i=n;i<(int)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

vector<lint> transform(vector<lint> a) {
	int n = (int)a.size();
	vector<lint> ret(n);
	vector<pint> b;
	REP(i, n) b.pb({a[i], i});
	sort(ALL(b));
	REP(i, n) ret[b[i].second] = i;
	return ret;
}

template <typename T>
class SegTree {
private:
	int n;
	const function<T(T, T)> op; // 
	const T ie; // 
	vector<T> seq;

public:
	/// op: , ie: 
	SegTree(int _n, function<T(T, T)> op, const T ie) : op(op), ie(ie) {
		n = 1;
		while(n < _n) n *= 2;
		seq.resize(2 * n - 1);
		for(int i = 0; i < 2 * n - 1; i++) seq[i] = ie;
	}

	/// k (0-indexed) e 
	void update(int k, const T e) {
		k += n - 1;
		seq[k] = e;
		while(k > 0) {
			k = (k - 1) / 2;
			seq[k] = op(seq[k * 2 + 1], seq[k * 2 + 2]);
		}
	}

	// k (0-indexed)
	T get(int k) {
		k += n - 1;
		return seq[k];
	}

	/// [a, b) (0-indexed)
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if(r == -1) r = n;
		if(r <= a || b <= l) return ie;
		if(a <= l && r <= b) return seq[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return op(vl, vr);
	}
};
// [Range Sum Query] rsq(n, [] (ll a, ll b) { return a + b; }, 0)
// [Range Max Query] rMq(n, [] (ll a, ll b) { return max(a, b); }, -1e18)
// [Range Min Query] rmq(n, [] (ll a, ll b) { return min(a, b); }, 1e18)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<lint> a(n);
	REP(i, n) cin >> a[i];
	vector<lint> b = transform(a);
	lint ans = 0;
	SegTree<lint> rsq(n + 10, [] (lint a, lint b) { return a + b; }, 0);
	REP(i, n) {
		ans += (((i + 1) * (n - i)) % MOD) * a[i]; ans %= MOD;
	}
	REP(i, n) {
		lint co = (n - i);
		lint s = rsq.query(0, b[i]); s %= MOD;
		ans += ((co * s) % MOD) * a[i]; ans %= MOD;
		rsq.update(b[i], i + 1);
	}
	REP(i, n) rsq.update(i, 0);
	for(int i = n - 1; i >= 0; i--) {
		lint co = i + 1;
		lint s = rsq.query(0, b[i]); s %= MOD;
		ans += ((co * s) % MOD) * a[i]; ans %= MOD;
		rsq.update(b[i], n - i);
	}
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */