#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, q;
int a[300007];

struct Tree2 {
	static const int INF = 1e6;
	pair<int, int> t[300007 * 4];
	int p[300007 * 4];

	void build(int v, int vl, int vr) {
		p[v] = 0;
		if (vl == vr) {
			t[v].x = vl + 1 - a[vl];
			if (t[v].x < 0) t[v].x = INF;
			t[v].y = vl;
		} else {
			int vm = (vl + vr) >> 1;
			build(v * 2 + 1, vl, vm);
			build(v * 2 + 2, vm + 1, vr);
			t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}

	void push(int v) {
		if (p[v] != 0) {
			t[v].x += p[v];
			if (v * 2 + 1 < 300007 * 4) p[v * 2 + 1] += p[v];
			if (v * 2 + 2 < 300007 * 4) p[v * 2 + 2] += p[v];
			p[v] = 0;
		}
	}

	pair<int, int> get() {
		push(0);
		return t[0];
	}

	void up(int v, int vl, int vr, int l, int r, int val) {
		push(v);
		if (r < vl || l > vr) return;
		if (vl >= l && vr <= r) {
			p[v] += val;
			push(v);			
		} else {
			int vm = (vl + vr) >> 1;
			up(v * 2 + 1, vl, vm, l, r, val);
			up(v * 2 + 2, vm + 1, vr, l, r, val);
			t[v] = min(t[v * 2 + 1], t[v * 2 + 2]);
		}
	}

} t;


vector<pair<int, int> > create(int vl, int vr) {
	int heh = vr - vl + 1;
	for (int i = vl; i <= vr; ++i) if (i + 1 < a[i]) --heh;
		/*if (vl == 0 && vr == 12) {
			for (int i = vl; i <= vr; ++i) {
				cout << a[i] << ' ' << i + 1 << endl;
			}
		} */
	t.build(0, vl, vr);
	int val = 0;
	vector<pair<int, int> > res;
	int cnt = 0;
	while (cnt < heh) {
		auto [w1, w2] = t.get();
	//	if (vl == 0 && vr == 12) cout << val << ' ' << cnt << ' ' << w1 << ' ' << w2 << ' ' << heh << endl;
		if (w1 <= 0) {
			++cnt;
			t.up(0, vl, vr, w2, vr, -1);
			t.up(0, vl, vr, w2, w2, (int)1e6);
		} else {
			res.pb({val, cnt});
			val += w1;
			t.up(0, vl, vr, vl, vr, -w1);
		}
	}
	res.pb({val, cnt});
	return res;
}

struct Tree {
	vector< pair<int, int> > t[300007 * 4];

	void build(int v, int vl, int vr) {
		t[v] = create(vl, vr);


	//	cout << v << ' ' << vl << ' ' << vr << ": \n";
	//	for (auto [w1, w2] : t[v]) cout << w1 << ' ' << w2 << endl;
	//	cout << endl;

		if (vl != vr) {
			int vm = (vl + vr) >> 1;
			build(v * 2 + 1, vl, vm);
			build(v * 2 + 2, vm + 1, vr);
		}
	}

	int get(int v, int vl, int vr, int l, int r, int have = 0) {
		if (vr < l) return have;
		if (vl > r) return have;
		
		if (vl >= l && vr <= r) {
			int vl = 0, vr = t[v].size();
			while (vl + 1 < vr) {
				int vm = (vl + vr) >> 1;
				if (t[v][vm].x <= have) 
					vl = vm;
				else
					vr = vm;
			}
			return have + t[v][vl].y;
		} else {
			int vm = (vl + vr) >> 1;
			have = get(v * 2 + 1, vl, vm, l, r, have);
			return get(v * 2 + 2, vm + 1, vr, l, r, have);
		}
	}
} tr;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; ++i) cin >> a[i];

	tr.build(0, 0, n - 1);

	while (q--) {
		int w1, w2;
		cin >> w1 >> w2;
		auto now = tr.get(0, 0, n - 1, w1, n - w2 - 1);
		cout << now << "\n";
	}

}