#include <bits/stdc++.h> 
 
using namespace std;
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 1e5 + 100;
const ll INF = 1e18 + 7;

ll treeMin[4 * N], treeMax[4 * N];

ll getMin(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return INF;
	}
	if (l <= vl && vr <= r) {
		return treeMin[v];
	}
	return min(getMin(2 * v, vl, (vl + vr) / 2, l, r), getMin(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

ll getMax(int v, int vl, int vr, int l, int r) {
	if (vr <= l || r <= vl) {
		return -INF;
	}
	if (l <= vl && vr <= r) {
		return treeMax[v];
	}
	return max(getMax(2 * v, vl, (vl + vr) / 2, l, r), getMax(2 * v + 1, (vl + vr) / 2, vr, l, r));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	vi a(n), b(n);
	vector<ll> bal(n + 1, 0);
	forn(i, n) {
		cin >> a[i];
	}
	forn(i, n) {
		cin >> b[i];
	}
	forn(i, n) {
		bal[i + 1] = bal[i] + b[i] - a[i];
	}
/*	forn(i, n + 1) {
		cout << bal[i] << " ";
	}
	cout << '\n';*/
	int tSize = 1;
	while(tSize < n + 1) tSize *= 2;
	forn(i, tSize) {
		if (i < n + 1) {
			treeMin[tSize + i] = treeMax[tSize + i] = bal[i];
		} else {
			treeMin[tSize + i] = INF;
			treeMax[tSize + i] = -INF;
		}
	}
	fornr(i, tSize) {
		treeMin[i] = min(treeMin[2 * i], treeMin[2 * i + 1]);
		treeMax[i] = max(treeMax[2 * i], treeMax[2 * i + 1]);
	}
	forn(i, q) {
		int l, r;
		cin >> l >> r;
		l--;
		ll balBefore = bal[l];
		ll balAfter = bal[r];
		ll balMin = getMin(1, 0, tSize, l, r + 1);
		ll balMax = getMax(1, 0, tSize, l, r + 1);
	//	cerr << l << " " << r << " " << balMin << " " << balMax << '\n';
		if (balBefore != balAfter || balMin < balBefore) {
			cout << -1 << '\n';
			continue;
		}
		ll ans = balMax - balBefore;
		cout << ans << '\n';
	}
	return 0;
}