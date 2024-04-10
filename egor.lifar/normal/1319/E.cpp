#include <bits/stdc++.h>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200228;


int n, m, p;
int a[MAXN], ca[MAXN];
int b[MAXN], cb[MAXN];
int x[MAXN], y[MAXN], z[MAXN];
ll who[3000228];


struct rmq
{
	vector<ll> d;
	vector<ll> mod;
	int ss = 1;
	void init(int n) {
		while (ss < n) {
			ss <<= 1;
		}
		d.resize(2 * ss, 0);
		mod.resize(2 * ss, 0);
	}	
	void push(int v) {
		if (mod[v] != 0) {
			d[v] += mod[v];
			if (v < ss) {
				mod[v * 2] += mod[v];
				mod[v * 2 + 1] += mod[v];
			}
			mod[v] = 0;
		}
	}
	void add(int v, int vl, int vr, int l, int r, ll x) {
		if (l > vr || vl > r || l > r) {
			push(v);
			return;
		}
		if (l <= vl && vr <= r) {
			mod[v] += x;
			push(v);
			return;
		}
		push(v);
		add(v * 2, vl, (vl + vr) / 2, l, r, x);
		add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
		d[v] = max(d[v * 2] + mod[v * 2], d[v * 2 + 1] + mod[v * 2 + 1]);
	}
	ll cur = 0;
	ll get(int v, int vl, int vr, int l, int r) {
		if (vl > r || l > vr) {
			return -1e18;
		}
		if (l <= vl && vr <= r) {
			return d[v] + mod[v] + cur;
		}
		cur += mod[v];
		int ans = max(get(v * 2, vl, (vl + vr) / 2, l, r), get(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
		cur -= mod[v];
		return cur;
	}
} kek;


void add(int i) {
	kek.add(1, 1, kek.ss, y[i] + 1, 1000000, z[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> ca[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i] >> cb[i];
	}	
	for (int i= 0; i < p; i++) {
		cin >> x[i] >> y[i] >> z[i];
	}
	vector<pair<int, int> > st;
	for (int i = 0; i < n; i++) {
		st.pb({a[i], ca[i]});
	}
	sort(all(st));
	for (int i = 1; i <= 3000000; i++) {
		who[i] = 1e18;
	}
	for (int i = 0; i < m; i++) {
		chkmin(who[b[i]], cb[i]);
	}
	vector<pair<int, int> > g;
	for (int i = 0; i < p; i++) {
		g.pb({x[i], i});
	}
	sort(all(g));
	ll ans = -1e18;
	int uk = 0;
	kek.init(1000000);
	for (int i = 1; i <= kek.ss; i++) {
		kek.d[i + kek.ss - 1] = -who[i];
	}
	for (int i = kek.ss - 1; i >= 1; i--) {
		kek.d[i] = max(kek.d[i * 2], kek.d[i * 2 + 1]);
	}
	for (int i = 0; i < n; i++) {
		a[i]= st[i].first;
		ca[i] = st[i].second;
		while (uk < sz(g) && g[uk].first < a[i]) {
			add(g[uk].second);
			uk++;
		}
		ll val = kek.d[1] + kek.mod[1];
		val -= ca[i];
		chkmax(ans, val);
	}
	cout << ans << '\n';
}