//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

template <class T>
ostream& operator << (ostream& os, const vector<T>& v) {
	for(const T& it : v) {
		os << it << " ";
	}
	return os;
}

struct Range {
	int l, r, i;
	Range(int a, int b, int _i): l(a), r(b), i(_i) {}
	bool operator < (const Range& o) const {
		return l < o.l;
	}
	bool operator > (const Range& o) const {
		return r > o.r;
	}
};

vector<int> convert(const vector<int>& v) {
	vector<int> out(v.size());
	for(int i=0; i<v.size(); i++) {
		out[v[i]-1] = i+1;
	}
	return out;
}

const int N = 1<<18;
int st[2*N], z[2*N];

void push(int i) {
	if(z[i]) {
		st[2*i] += z[i];
		st[2*i+1] += z[i];
		z[2*i] += z[i];
		z[2*i+1] += z[i];
		z[i] = 0;
	}
}

void pull(int i) {
	st[i] = min(st[2*i], st[2*i+1]);
}

void insert(int l, int r, int v, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return;
	if(l<=s && e<=r) {
		st[i] += v;
		z[i] += v;
		return;
	}
	push(i);
	int m = (s+e) / 2;
	insert(l, r, v, 2*i, s, m);
	insert(l, r, v, 2*i+1, m+1, e);
	pull(i);
}

int query(int l, int r, int i=1, int s=0, int e=N-1) {
	if(r<s || e<l) return INF;
	if(l<=s && e<=r) {
		return st[i];
	}
	push(i);
	int m = (s+e) / 2;
	return min(query(l, r, 2*i, s, m), query(l, r, 2*i+1, m+1, e));
}

// TODO
// double-check correctness
// read limits carefully
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	vector<Range> v;
	for(int i=1; i<=n; i++) {
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b, i);
	}

	vector<int> ans;
	sort(v.begin(), v.end());
	set<pair<int,int>> active;
	for(int i=1, j=0; i<=n; i++) {
		while(v[j].l == i) {
			active.insert(make_pair(v[j].r, v[j].i));
			j++;
		}
		ans.push_back(active.begin()->second);
		active.erase(active.begin());
	}

	for(int i=1; i<=n; i++) {
		insert(i, n, 1);
		insert(v[i-1].r, n, -1);
	}
	assert(query(1, n) == 0);

	vector<int> other;
	assert(active.empty());
	for(int i=1, j=0; i<=n; i++) {
		while(v[j].l == i) {
			active.insert(make_pair(v[j].r, v[j].i));
			j++;
		}
		insert(i, n, -1); // remove length
		if(active.size() == 1) {
			insert(active.begin()->first, n, 1);
			other.push_back(active.begin()->second);
			active.erase(active.begin());
		} else {
			int first = active.begin()->first;
			int second = next(active.begin())->first;
			insert(second, n, 1);
			if(query(1, n) == 0) {
				other.push_back(next(active.begin())->second);
				active.erase(next(active.begin()));
			} else {
				insert(second, n, -1);
				insert(first, n, 1);
				other.push_back(active.begin()->second);
				active.erase(active.begin());
			}
		}
		assert(query(1, n) == 0);
	}

	if(ans != other) {
		cout << "NO" << nl;
		cout << convert(ans) << nl;
		cout << convert(other) << nl;
		return 0;
	}

	cout << "YES" << nl;
	cout << convert(ans) << nl;

	return 0;
}