#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000009;

map <pii, int> in, id;
set <int> S;
int X[100010], Y[100010];

bool check(pii P) {
	int x = P.fi, y = P.se + 1;
	for (int dx = x - 1; dx <= x + 1; dx++) {
		if (in.count(mp(dx, y)) && in[mp(dx, y)] == 1) return 0;
	}
	return 1;
}

int main () {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		X[i] = x, Y[i] = y;
		in[mp(x, y)] = 0, id[mp(x, y)] = i;
	}
	for (map <pii, int> :: iterator it = in.begin(); it != in.end(); it++) {
		int x = it->fi.fi, y = it->fi.se - 1;
		for (int dx = x - 1; dx <= x + 1; dx++) {
			if (in.count(mp(dx, y))) {
				in[it->fi]++;
			}
		}
	}
	for (map <pii, int> :: iterator it = in.begin(); it != in.end(); it++) {
		if (check(it->fi)) S.insert(id[it->fi]);
	}
	long long ans = 0;
	for (int it = 0; it < n; it++) {
		if (it & 1) {
			int v = *S.begin(); S.erase(S.begin());
			int y = Y[v] + 1;
			id.erase(mp(X[v], Y[v]));
			in[mp(X[v], Y[v])] = 0;
			for (int x = X[v] - 1; x <= X[v] + 1; x++) {
				if (!id.count(mp(x, y))) continue;
				in[mp(x, y)]--;
			}
			y--;
			for (int x = X[v] - 2; x <= X[v] + 2; x++) {
				if (!id.count(mp(x, y))) continue;
				if (check(mp(x, y))) S.insert(id[mp(x, y)]);
				else S.erase(id[mp(x, y)]);
			}
			y--;
			for (int x = X[v] - 2; x <= X[v] + 2; x++) {
				if (!id.count(mp(x, y))) continue;
				if (check(mp(x, y))) S.insert(id[mp(x, y)]);
				else S.erase(id[mp(x, y)]);
			}
			ans = (ans * n + v) % mod;
		} else {
			int v = *(--S.end()); S.erase(--S.end());
			int y = Y[v] + 1;
			id.erase(mp(X[v], Y[v]));
			in[mp(X[v], Y[v])] = 0;
			for (int x = X[v] - 1; x <= X[v] + 1; x++) {
				if (!id.count(mp(x, y))) continue;
				in[mp(x, y)]--;
			}
			y--;
			for (int x = X[v] - 2; x <= X[v] + 2; x++) {
				if (!id.count(mp(x, y))) continue;
				if (check(mp(x, y))) S.insert(id[mp(x, y)]);
				else S.erase(id[mp(x, y)]);
			}
			y--;
			for (int x = X[v] - 2; x <= X[v] + 2; x++) {
				if (!id.count(mp(x, y))) continue;
				if (check(mp(x, y))) S.insert(id[mp(x, y)]);
				else S.erase(id[mp(x, y)]);
			}
			ans = (ans * n + v) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}