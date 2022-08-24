#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int mod = 1000000007;
int key;

int getHash(const string& s) {
	long long res = 0;
	for (char c : s) {
		res = res * key + c;
		res %= mod;
	}
	return res;
}

struct Query {
	int id;
	string s;
	int k;
	int hash;
};

vector<int> degs;

struct Hasher {
	vector<int> h;

	explicit Hasher(const string& s) {
		h = {0};
		long long cur = 0;
		for (char c : s) {
			cur = cur * key + c;
			cur %= mod;
			h.push_back(cur);
		}
	}

	int getSubHash(int l, int r) {
		long long tmp = h[r] - 1ll * h[l] * degs[r - l];
		tmp %= mod;
		if (tmp < 0) {
			tmp += mod;
		}
		return tmp;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;

	key = 239 + rand() % 20 * 2;
	Hasher h(s);
	degs.resize(s.length() + 1);
	degs[0] = 1;
	for (int i = 1; i <= (int)s.size(); ++i) {
		degs[i] = 1ll * degs[i - 1] * key % mod;
	}

	int n = nxt();
	map<int, vector<Query>> M;
	for (int i = 0; i < n; ++i) {
		Query q;
		q.id = i;
		cin >> q.k >> q.s;
		q.hash = getHash(q.s);
		M[q.s.length()].push_back(q);
	}

	vector<int> ans(n, -1);
	for (const auto& [l, v] : M) {
		map<int, int> idx;
		for (int i = 0; i < (int)v.size(); ++i) {
			idx[v[i].hash] = i;
		}
		vector<queue<int>> qs(v.size());

		for (int i = l; i <= (int)s.size(); ++i) {
			int hash = h.getSubHash(i - l, i);
			auto it = idx.find(hash);
			if (it == idx.end()) {
				// cerr << l << ", " << i << ": fail\n";
				continue;
			}
			int id = it->second;
			qs[id].push(i);
			if ((int)qs[id].size() >= v[id].k) {
				// cerr << l << ", " << i << ", " << v[id].s << "\n";
				int tmp = qs[id].back() - qs[id].front() + l;
				if (tmp < ans[v[id].id] || ans[v[id].id] == -1) {
					ans[v[id].id] = tmp;
				}
				qs[id].pop();
			}
		}
	}

	for (int x : ans) {
		printf("%d\n", x);
	}

	return 0;
}