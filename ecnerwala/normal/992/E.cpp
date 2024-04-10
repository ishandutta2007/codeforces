#include <iostream>
#include <set>
#include <vector>
#include <cassert>
using namespace std;

typedef long long ll;

const int MAXN = 3e5;
int N;
ll A[MAXN];

ll bit[MAXN];
ll bit_query(int a) {
	ll res = 0;
	for (; a; a -= a & (-a)) {
		res += bit[a];
	}
	return res;
}
void bit_update(int a, ll v) {
	for (++a; a <= N; a += a & (-a)) {
		bit[a] += v;
	}
}

int get_bucket(int a) {
	return a ? __builtin_clz(unsigned(a)) : (__builtin_clz(unsigned(1))+1);
}

const int MAXB = 40;
const int B = get_bucket(0)+1;
set<int> inds[MAXB];
vector<pair<int, ll>> v[MAXB];

void update_bucket(int b) {
	auto it = inds[b].begin();
	v[b].clear();
	for (int z = 0; z < 2 && it != inds[b].end(); z++, it++) {
		int p = *it;
		v[b].emplace_back(p, bit_query(p));
	}
}

void do_update(int p, ll x) {
	bit_update(p, x-A[p]);
	for (int b = 0; b < B; b++) {
		for (auto &it : v[b]) {
			if (p < it.first) {
				it.second += x-A[p];
			}
		}
		for (const auto &it : v[b]) {
			assert(it.second == bit_query(it.first));
		}
	}
	inds[get_bucket(A[p])].erase(p);
	inds[get_bucket(x)].insert(p);
	update_bucket(get_bucket(A[p]));
	update_bucket(get_bucket(x));
	A[p] = x;
	for (int b = 0; b < B; b++) {
		assert(v[b].size() == min(size_t(2), inds[b].size()));
	}
}

int do_query() {
	for (int b = 0; b < B; b++) {
		for (const auto &it : v[b]) {
			if (A[it.first] == it.second) {
				return it.first;
			}
		}
	}
	return -1;	
}

int main() {
	int Q;
	ios_base::sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		A[i] = 0;
		inds[get_bucket(A[i])].insert(i);
	}
	update_bucket(get_bucket(0));
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		do_update(i, a);
	}
	for (int i = 0; i < Q; i++) {
		int p, x; cin >> p >> x;
		p--;
		do_update(p, x);
		int res = do_query();
		if (res >= 0) res ++;
		cout << res << '\n';
	}
	return 0;
}