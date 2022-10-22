#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

map<pll, vector<ll>> q;

const ll M = 10004205361450474;
const ll K = 1e4;

ll init(ll left = 1, int cnt = 4) {
	if (cnt == 1) {
		return left + min(left, K);
	}

	vector<ll> cur;
	ll first = left;
	for (int i = 0; i < min(left, K); i++) {
		ll mid = init(first, cnt-1);
		cur.push_back(mid);
		first = mid+1;
	}
	ll right = init(first, cnt-1);
	q[pll(left, right-1)] = cur;

	return right;
}

int answer() {
	int in;
	cin >> in;
	assert(in != -2);
	return in;
}

int normal(int r, ll left, ll right, vector<ll>& query) {
	query.clear();

	ll diff = 1;
	for (int i = 1; i < r; i++) {
		diff = diff*(K+1);
	}

	int k = min(left, K) + 1;
	ll cur = left-1 + diff;
	for (int i = 1; i < k && cur <= right; i++) {
		query.push_back(cur);
		cur += diff;
	}

	cout << query.size() << " ";
	for (const ll& it : query) {
		cout << it << " ";
	}
	cout << endl;

	return answer();
}

int guess(int i, ll left, ll right, vector<ll>& query) {
	query.clear();

	if (i == 1) {
		query = { init() };
		cout << 1 << " " << query[0] << endl;
		return answer();
	}

	if (left + min(left, K) >= right) {
		cout << min(left, K) << " ";
		for (ll i = 0; i < min(left, K); i++) {
			cout << left+i << " ";
		}
		cout << endl;

		return answer();
	}

	assert(q.count(pll(left, right)));
	query = q[pll(left, right)];

	cout << query.size() << nl;
	for (const ll& it : query) {
		cout << it << " ";
	}
	cout << endl;

	return answer();
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	ll left = 1;
	ll right = M;
	vector<ll> query;

	for (int i = 1; i <= 5; i++) {
		int res = guess(i, left, right, query);
		if (res == -1) {
			return 0;
		} else if (res == 0) {
			right = query.front()-1;
		} else if (res == query.size()) {
			left = query.back()+1;
		} else {
			left = query[res-1]+1;
			right = query[res]-1;
		}

		if (i == 1 && left != 1) {
			break;
		}
	}

	for (int i = 4; i > 0; i--) {
		int res = normal(i, left, right, query);
		if (res == -1) {
			return 0;
		} else if (res == 0) {
			right = query.front()-1;
		} else if (res == query.size()) {
			left = query.back()+1;
		} else {
			left = query[res-1]+1;
			right = query[res]-1;
		}
	}

	assert(false);

	return 0;
}