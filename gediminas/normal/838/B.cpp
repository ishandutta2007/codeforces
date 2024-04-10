/*input
5 9
1 3 1
3 2 2
1 4 3
3 5 4
5 1 5
3 1 6
2 1 7
4 1 8
2 1 1
2 1 3
2 3 5
2 5 2
1 1 100
2 1 3
1 8 30
2 4 2
2 2 4
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;
int pra[maxn], pab[maxn];
vector<int> gra[maxn];
int n, q;
long long svor[2 * maxn];
int pradzianr[maxn];
int pabaiganr[maxn];
int keisk[2 * maxn];

struct minimumai {
	const long long static inf = 200000000000ll;
	long long val = 0;
	long long lazy = 0;
	int fr, to;
	minimumai *left = NULL, *right = NULL;
	void push() {
		val += lazy;
		right->lazy += lazy;
		left->lazy += lazy;
		lazy = 0;
	}
	minimumai(int fr, int to): fr(fr), to(to) {
		if (fr == to)
			return;

		int vid = (fr + to) / 2;
		left = new minimumai(fr, vid);
		right = new minimumai(vid + 1, to);
	}
	void update(int f, int t, long long l) {
		if (to < f or t < fr)
			return;

		if (f <= fr and to <= t) {
			lazy += l;
			return;
		}

		push();
		right->update(f, t, l);
		left->update(f, t, l);
		val = min(right->val + right->lazy, left->val + left->lazy);
	}
	long long get(int f, int t) {
		if (to < f or t < fr)
			return inf;

		if (f <= fr and to <= t)
			return val + lazy;

		assert(fr != to);
		push();
		long long ret = min(right->get(f, t), left->get(f, t));
		return ret;
	}
} *medis;

int timer = 0;
void dfs(int d, long long kel = 0) {
	pra[d] = ++timer;
	medis->update(timer, timer, kel + svor[pradzianr[d]]);

	for (auto && x : gra[d])
		dfs(x, kel + svor[pabaiganr[x]]);

	pab[d] = timer;
}

long long inline kelias(int x) {
	return medis->get(pra[x], pra[x]) - svor[pradzianr[x]];
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b >> svor[i];
		a--, b--;
		pabaiganr[b] = i;
		keisk[i] = b;
		gra[a].push_back(b);
	}

	for (int i = n - 1; i < 2 * n - 2; i++) {
		int b;
		cin >> keisk[i] >> b >> svor[i];
		keisk[i]--;
		pradzianr[keisk[i]] = i;
	}

	pradzianr[0] = 2 * n - 1;
	svor[2 * n - 1] = 0;

	medis = new minimumai(0, maxn);
	dfs(0);

	for (int i = 0; i < q; i++) {
		int kom, u, v;
		cin >> kom >> u >> v;
		u--;

		if (kom == 1) {
			if (u < n - 1)
				medis->update(pra[keisk[u]], pab[keisk[u]], v - svor[u]);
			else
				medis->update(pra[keisk[u]], pra[keisk[u]], v - svor[u]);

			svor[u] = v;
		}
		else {
			v--;
			long long ku = kelias(u), kv = kelias(v);

			if (pra[u] <= pra[v] and pab[v] <= pab[u])
				cout << kv - ku << "\n";
			else
				cout << medis->get(pra[u], pab[u]) - ku + kv << "\n";
		}
	}

	return 0;
}