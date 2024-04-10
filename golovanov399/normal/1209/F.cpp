#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int mod = 1000000007;

struct Edge {
	int to, len, rem;
};

const int N = 111111;
vector<Edge> a[N];

const int L = 20;

const int H = 3;
const int mods[H] = {998244353, 1000000009, 1000000021};
int keys[H];

int dist[N];
int pr[N][L];
Edge last_edge[N];
long long rem[N];
char used[N];
array<int, H> h[N];

long long deg[8];
long long hd[H][N];

array<long long, H> get_hash(int v, int len) {
	for (int i = L - 1; i >= 0; --i) {
		if (dist[pr[v][i]] >= len) {
			v = pr[v][i];
		}
	}

	int x = last_edge[v].rem;
	for (int i = len; i < dist[v]; ++i) {
		x /= 10;
	}

	array<long long, H> res;
	for (int j = 0; j < H; ++j) {
		res[j] = (h[pr[v][0]][j] * hd[j][len - dist[pr[v][0]]] + x) % mods[j];
	}
	return res;
}

int get_kth(int v, int idx) {
	for (int i = L - 1; i >= 0; --i) {
		if (dist[pr[v][i]] > idx) {
			v = pr[v][i];
		}
	}

	int x = last_edge[v].rem;
	for (int i = idx + 1; i < dist[v]; ++i) {
		x /= 10;
	}
	return x % 10;
}

bool are_eq(int v1, int v2, int len) {
	return get_hash(v1, len) == get_hash(v2, len);
}

int lexcmp(int v1, int v2, int len) {
	int l = 0, r = len + 1;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (are_eq(v1, v2, m)) {
			l = m;
		} else {
			r = m;
		}
	}
	if (l == len) {
		return 0;
	} else {
		return get_kth(v1, l) < get_kth(v2, l) ? -1 : 1;
	}
}

bool is_better(int p1, const Edge& e1, int p2, const Edge& e2) {
	int len1 = dist[p1];
	int len2 = dist[p2];
	int len = min(len1, len2);
	int sign = lexcmp(p1, p2, len);
	if (sign) {
		return sign == -1;
	}
	string digits1 = "", digits2 = "";
	digits1 = to_string(e1.rem);
	reverse(all(digits1));
	while (len1 > len) {
		int np1 = pr[p1][0];
		auto tmp = to_string(last_edge[p1].rem);
		if (dist[np1] < len) {
			tmp = tmp.substr(len - dist[np1]);
		}
		reverse(all(tmp));
		digits1 += tmp;
		len1 = dist[np1];
		p1 = np1;
	}
	reverse(all(digits1));

	digits2 = to_string(e2.rem);
	reverse(all(digits2));
	while (len2 > len) {
		int np2 = pr[p2][0];
		auto tmp = to_string(last_edge[p2].rem);
		if (dist[np2] < len) {
			tmp = tmp.substr(len - dist[np2]);
		}
		reverse(all(tmp));
		digits2 += tmp;
		len2 = dist[np2];
		p2 = np2;
	}
	reverse(all(digits2));

	return digits1 < digits2;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	for (int i = 0; i < H; ++i) {
		keys[i] = 10;
	}

	deg[0] = 1;
	for (int j = 0; j < H; ++j) {
		hd[j][0] = 1;
	}
	for (int i = 1; i < 8; ++i) {
		deg[i] = deg[i - 1] * 10;
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < H; ++j) {
			hd[j][i] = hd[j][i - 1] * keys[j] % mods[j];
		}
	}

	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		int id = i + 1;
		int len = to_string(id).size();
		a[u].push_back({v, len, id});
		a[v].push_back({u, len, id});
	}

	dist[0] = 0;
	for (int i = 1; i < n; ++i) {
		dist[i] = 1e8;
	}
	set<pair<int, int>> S;
	for (int i = 0; i < N; ++i) {
		S.insert({dist[i], i});
	}

	while (!S.empty()) {
		auto [d, v] = *S.begin();
		S.erase(S.begin());
		used[v] = 1;
		for (int i = 1; i < L; ++i) {
			pr[v][i] = pr[pr[v][i - 1]][i - 1];
		}
		for (const auto& e : a[v]) {
			if (used[e.to]) {
				continue;
			}
			if (dist[e.to] > d + e.len || (dist[e.to] == d + e.len && is_better(v, e, pr[e.to][0], last_edge[e.to]))) {
				S.erase({dist[e.to], e.to});
				dist[e.to] = d + e.len;
				pr[e.to][0] = v;
				last_edge[e.to] = e;
				rem[e.to] = (rem[v] * deg[e.len] + e.rem) % mod;

				for (int j = 0; j < H; ++j) {
					h[e.to][j] = (1ll * h[v][j] * hd[j][e.len] + e.rem) % mods[j];
				}
				S.insert({dist[e.to], e.to});
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		printf("%lld\n", rem[i]);
	}

	return 0;
}