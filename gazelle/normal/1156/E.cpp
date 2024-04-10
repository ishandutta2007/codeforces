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

vector<int> idx(202020);

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

int n;
vector<int> p;
SegTree<int> rMq(202020, [] (int a, int b) { return max(a, b); }, -1e9);

lint divconq(lint l, lint r) {
	if(r - l <= 2) return 0;
	int M = rMq.query(l, r);
	lint ret = 0;
	int pos = idx[M];
	if(pos - l < r - pos - 1) {
		for(int i = l; i < pos; i++) {
			if(idx[M - p[i]] > pos && idx[M - p[i]] < r) ret++;
		}
	} else {
		for(int i = pos + 1; i < r; i++) {
			if(idx[M - p[i]] < pos && idx[M - p[i]] >= l) ret++;
		}
	}
	ret += divconq(l, pos);
	ret += divconq(pos + 1, r);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	p.resize(n);
	REP(i, n) cin >> p[i];
	REP(i, n) idx[p[i]] = (int)i;
	REP(i, n) rMq.update((int)i, p[i]);
	lint ans = divconq(0, n);
	cout << ans << endl;
	return 0;
}
/* --------------------------------------- */