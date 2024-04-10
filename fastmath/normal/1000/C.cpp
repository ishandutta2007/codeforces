#include <bits/stdc++.h>

using namespace std;

#define int long long
#define l first
#define r second

const int MAXN = 2e5 + 7;
pair <int, int> a[MAXN];

struct Ev {
	bool t;
	int p;
	Ev (bool t_, int p_) {
	 	t = t_;
	 	p = p_;
	}
};

bool comp(Ev a, Ev b) {
	return a.p < b.p;
}

int ans[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	cin >> n;
	vector <Ev> v;
	vector <int> c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].l >> a[i].r;
		v.push_back(Ev(0, a[i].l));
		v.push_back(Ev(1, a[i].r + 1));
		c.push_back(a[i].l);
		c.push_back(a[i].r + 1);
	}

	sort(c.begin(), c.end());
	sort(v.begin(), v.end(), comp);

	int u = 0;
	int b = 0;
	for (int i = 0; i < (int)c.size(); ++i) {
		while (u < v.size() && v[u].p <= c[i]) {
		 	if (!v[u].t) ++b;
		 	else --b;
		 	++u;
		}
		if (i < (int)c.size() - 1) {
			ans[b] += c[i + 1] - c[i];
		}	
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
	cout << '\n';
    return 0;
}