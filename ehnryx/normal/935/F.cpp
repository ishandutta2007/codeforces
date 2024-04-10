#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

inline void srand() { srand(chrono::high_resolution_clock::now().time_since_epoch().count()); }

template <class T, class U>
ostream& operator << (ostream& os, const pair<T,U>& v) {
	os << "(" << v.first << "," << v.second << ")"; return os;
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for (const T& it : v) os << it << " "; return os;
}

template <class T>
ostream& operator << (ostream& os, const set<T>& v) {
	os << "{ "; for (const T& it : v) os << it << " "; os << "}"; return os;
}

template <class T, class U>
ostream& operator << (ostream& os, const map<T,U>& v) {
	os << "{ ";
	for (const pair<T,U>& it : v) os << "{" << it.first << "," << it.second << "} "; 
	os << "}"; return os;
}

template <class T>
inline T sqr(T x) { return x*x; }

const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
//const ld PI = M_PIl;
////////////////////////////////////////////////////////////////////////

typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

// RMQ with teeth
namespace SegTree {
	const int n = 1<<17;
	ll left[2*n], right[2*n], sum[2*n];
	pll rmq[2*n], freq[2*n];

	void build(int len, int a[]) {
		memset(left, 0, sizeof left);
		memset(right, 0, sizeof right);
		memset(sum, 0, sizeof sum);
		memset(rmq, 0, sizeof rmq);
		memset(freq, 0, sizeof freq);
		for (int i = 2; i <= len; i++) {
			left[i+n] = a[i] - a[i-1];
			right[i-1+n] = a[i-1] - a[i];
			sum[i+n] = abs(left[i+n]);
		}
		for (int i = 1; i <= len; i++) {
			rmq[i+n] = pll(min(0LL, left[i+n]) + min(0LL, right[i+n]), i+n);
			if (left[i+n] < 0 && right[i+n] < 0)
				freq[i+n] = pll(1,i+n);
		}
		for (int i = n-1; i > 0; i--) {
			sum[i] = sum[2*i] + sum[2*i+1];
			rmq[i] = max(rmq[2*i], rmq[2*i+1]);
			freq[i].first = freq[2*i].first + freq[2*i+1].first;
			freq[i].second = freq[2*i].first ? freq[2*i].second : freq[2*i+1].second;
		}
	}

	void rmq_update(int x) {
		rmq[x] = pll(min(0LL, left[x]) + min(0LL, right[x]), x);
		if (left[x] < 0 && right[x] < 0)
			freq[x] = pll(1, x);
		else
			freq[x] = pll(0, 0);
		//cerr << "set rmq at " << x-n << " to " << rmq[x] << nl;
		for (int i = x; i > 1; i >>= 1) {
			rmq[i>>1] = max(rmq[i], rmq[i^1]);
			freq[i>>1].first = freq[i].first + freq[i^1].first;
			freq[i>>1].second = freq[i].first ? freq[i].second : freq[i^1].second;
		}
	}

	void left_assign(int x, ll v) {
		x += n;
		left[x] = v;
		sum[x] = abs(left[x]);
		//cerr << "set left at " << x-n << " to " << left[x] << endl;
		for (int i = x; i > 1; i >>= 1) 
			sum[i>>1] = sum[i] + sum[i^1];
		rmq_update(x);
	}

	void right_assign(int x, ll v) {
		x += n;
		right[x] = v;
		//cerr << "set right at " << x-n << " to " << right[x] << endl;
		// no need to update sum because we do a left sum
		rmq_update(x);
	}

	void left_update(int x, ll v) {
		left_assign(x, left[x+n] + v);
	}

	void right_update(int x, ll v) {
		right_assign(x, right[x+n] + v);
	}

	pll get_min(int lx, int rx) {
		pll res = pll(0, -1);
		for (lx += n, rx += n; lx < rx; lx >>= 1, rx >>= 1) {
			if (lx & 1) {
				if (freq[lx].first > 0) {
					res.first += freq[lx].first;
					res.second = freq[lx].second;
				}
				lx++;
			}
			if (rx & 1) {
				--rx;
				if (freq[rx].first > 0) {
					res.first += freq[rx].first;
					res.second = freq[rx].second;
				}
			}
		}
		//cerr << "Freq returns : " << pll(res.first,res.second-n) << endl;
		return res;
	}

	ll query(int lx, int rx, ll v, bool flag = true) {
		ll ans = -INFLL;
		pll res = get_min(lx, rx);
		if (res.first == 1 && flag) {
			ans = abs(left[res.second] + v) - abs(left[res.second]) 
					+ abs(right[res.second] + v) - abs(right[res.second]);
			//cerr << "ans at trench: " << ans << endl;
			ans = max(ans, max(query(lx, res.second-n, v, false), query(res.second-n+1, rx, v, false)));
		}
		else {
			res = pll(-INFLL, -1);
			for (lx += n, rx += n; lx < rx; lx >>= 1, rx >>= 1) {
				if (lx & 1) res = max(res, rmq[lx++]);
				if (rx & 1) res = max(res, rmq[--rx]);
			}
			//cerr << "rmq gives " << pll(res.first,res.second-n) << endl;
			if (res.second == -1)
				ans = max(ans, -INFLL);
			else
				ans = max(ans, abs(left[res.second] + v) - abs(left[res.second]) 
						+ abs(right[res.second] + v) - abs(right[res.second]));
		}
		return ans;
	}

	ll query_sum(int lx, int rx) {
		ll res = 0;
		for (lx += n, rx += n; lx < rx; lx >>= 1, rx >>= 1) {
			if (lx & 1) res += sum[lx++];
			if (rx & 1) res += sum[--rx];
		}
		//cerr << "sum: " << res << endl;
		return res;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	srand();

	int n;
	cin >> n;

	int a[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] *= 2;
	}
	SegTree::build(n, a);

	int q;
	cin >> q;

	int t, l, r, x;
	for (int i = 0; i < q; i++) {
		cin >> t >> l >> r >> x; x *= 2;
		//cerr << endl;

		if (t == 1) {
			//cerr << "QUERY " << l << " -- " << r << " w/ " << x << endl;
			if (l == 1) SegTree::left_assign(l, -x/2);
			if (r == n) SegTree::right_assign(r, -x/2);
			cout << (SegTree::query(l, r+1, x) + SegTree::query_sum(2, n+1))/2 << nl;
		}

		else {
			//cerr << "UPDATE " << l << " -- " << r << " w/ " << x << endl;
			SegTree::left_update(l, x);
			SegTree::right_update(r, x);
			if (l > 1) SegTree::right_update(l-1, -x);
			if (r < n) SegTree::left_update(r+1, -x);
		}
	}

	return 0;
}