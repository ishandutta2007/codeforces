#include <bits/stdc++.h> 
 
using namespace std;
 
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

vector<int> g[N];

vector<int> a;
vector<int> b;

int mergeSort(string &s, int pos, int l, int r) {
	if (r - l <= 1) {
		return pos;
	}
	int m = (l + r) / 2;
	pos = mergeSort(s, pos, l, m);
	if (pos == -1) return -1;
	pos = mergeSort(s, pos, m, r);
	if (pos == -1) return -1;
	int i = l, j = m, k = l;
	while(i < m && j < r) {
		if (pos == sz(s)) {
			return -1;
		}
		if (s[pos] == '0') {
			g[a[i]].pb(a[j]);
			b[k] = a[i];
//			cerr << i + 1 << " less than " << j + 1 << '\n';
			i++;
		} else {
			g[a[j]].pb(a[i]);
			b[k] = a[j];
//			cerr << j + 1 << " less than " << i + 1 << '\n';
			j++;
		}
		k++;
		pos++;
	}
	while(i < m) {
		b[k] = a[i];
		i++;
		k++;
	}
	while(j < r) {
		b[k] = a[j];
		j++;
		k++;
	}
	forab(p, l, r) {
		a[p] = b[p];
	}
	return pos;
}

vector<int> topsort, used;

void dfs(int v) {
//	cerr << "IN " << v << '\n';
	used[v] = 1;
	for(int to : g[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
	topsort.pb(v);
}

void getAns(int n) {
	vector<int> ans(n);
	topsort.clear();
	used.assign(n, 0);
	forn(i, n) {
		if (!used[i]) {
			dfs(i);
		}
	}
/*	cerr << "TOPSORT:\n";
	forn(i, n) cerr << topsort[i] + 1 << " ";
	cerr << '\n';*/
	forn(i, n) {
		ans[topsort[i]] = n - i;
	}
	cout << n << '\n';
	forn(i, n) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	exit(0);
}

bool check(string &s, int n) {
	forn(i, n) {
		g[i].clear();
	}
	a.assign(n, 0);
	b.assign(n, 0);
	forn(i, n) a[i] = i;
	int res = mergeSort(s, 0, 0, n);
	if (res == sz(s)) {
//		cerr << "GETTING ANS\n";
		getAns(n);
	}
	return res == -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int l = 0, r = 1e5 + 1;
	while(l < r) {
		int m = (l + r) / 2;
		if (check(s, m)) {
			r = m;
		} else {
			l = m;
		}
	}
	assert(0);
	return 0;
}