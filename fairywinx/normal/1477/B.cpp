#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 228;
int t[4 * N];
int mod[4 * N];
int sz[4 * N];

void build(int v, int l, int r, string &s) {
	mod[v] = -1;
	if (r - l == 1) {
		t[v] = (s[l] - '0');
		sz[v] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m, s);
	build(v * 2, m, r, s);
	t[v] = t[v * 2 + 1] + t[v * 2];
	sz[v] = sz[v * 2 + 1] + sz[v * 2];
}

void push(int v) {
	if (mod[v] == -1)
		return;
	t[v * 2 + 1] = mod[v] * sz[v * 2 + 1];
	t[v * 2] = mod[v] * sz[v * 2];
	mod[v * 2] = mod[v];
	mod[v * 2 + 1] = mod[v];
	mod[v] = -1;
}

int get(int v, int l, int r, int L, int R) {
	if (r <= L || R <= l)
		return 0;
	if (L <= l && r <= R)
		return t[v];

	push(v);
	int m = (l + r) / 2;
	return get(v * 2 + 1, l, m, L, R) + get(v * 2, m, r, L, R);
}

void update(int v, int l, int r, int L, int R, int type) {
	if (r <= L || R <= l)
		return;
	if (L <= l && r <= R) {
		t[v] = sz[v] * type;
		mod[v] = type;
		return;
	}

	push(v);
	int m = (l + r) / 2;
	update(v * 2 + 1, l, m, L, R, type);
	update(v * 2, m, r, L, R, type);
	t[v] = t[v * 2 + 1] + t[v * 2];
}

void solve() {
	int n, q;
	cin >> n >> q;
	string s;
	string f;
	cin >> s >> f;
	build(1, 0, n, f);
	vector<pair<int, int>> z(q);
	for (int i = 0; i < q; ++i)
		cin >> z[i].first >> z[i].second;
	for (int i = q - 1; i >= 0; --i) {
		int val = get(1, 0, n, z[i].first - 1, z[i].second);
		int len = z[i].second - z[i].first + 1;
		if (val * 2 == len) {
			cout << "NO\n";
			return;
		}
		if (val * 2 > len)
			update(1, 0, n, z[i].first - 1, z[i].second, 1);
		else
			update(1, 0, n, z[i].first - 1, z[i].second, 0);
	}
	for (int i = 0; i < n; ++i) {	
		if (get(1, 0, n, i, i + 1) != (int) (s[i] - '0')) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}