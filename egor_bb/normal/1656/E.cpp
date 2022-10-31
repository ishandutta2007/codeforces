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

vi g[N];
ll coeffS[N], coeffW[N];

void clear(int n) {
	forn(i, n) {
		g[i].clear();
		coeffS[i] = 0;
		coeffW[i] = 0;
	}
}


void dfs(int v, int p, ll upW, ll upS, ll sizeW, ll sizeS) {
	int nC = sz(g[v]);
	if (v != p) {
		nC--;
	}
/*	cerr << "IN " << v + 1 << " : nC " << nC << '\n';
	cerr << "IN " << v + 1 << " : up " << upW << ", " << upS << '\n';
	cerr << "IN " << v + 1 << " : size " << sizeW << ", " << sizeS << '\n';*/
/*	if (p == v) {
		coeffS[v] = 0;
		coeffW[v] = 1;
	} else {*/
	coeffW[v] = sizeW - nC * upW;
	coeffS[v] = sizeS - nC * upS;
/*	cerr << "IN " << v + 1 << " : coeff " << coeffW[v] << ", " << coeffS[v] << '\n';
	cerr << '\n';*/
//	}
	for(int to : g[v]) {
		if (to != p) {
			dfs(
				to, v, 
				upW * (nC - (p == v)) + coeffW[v],
				upS * (nC - (p == v)) + coeffS[v],
				sizeW - coeffW[v] - (nC - 1) * upW,
				sizeS - coeffS[v] - (nC - 1) * upS
			);
		}
	}
}

bool tryMatch(int n, ll w, ll s) {
	forn(i, n) {
		ll val = coeffS[i] * s + coeffW[i] * w;
		if (val == 0 || abs(val) > 1e5) {
			return false;
		}	
	}
	forn(i, n) {
		cout << coeffS[i] * s + coeffW[i] * w;
		if (i != n - 1) cout << " ";
	}
	cout << '\n';
	return true;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		clear(n);
		forn(i, n - 1) {
			int v, u;
			cin >> v >> u;
			v--, u--;
			g[v].pb(u);
			g[u].pb(v);
		}
		dfs(0, 0, 0, 1, 1, sz(g[0]));
/*		forn(i, n) {
			cout << i + 1 << ": " << coeffS[i] << ", " << coeffW[i] << '\n';
		}*/
		forn(w, 100000) {
			bool ok = 0;
			forn(s, w + 1) {
				if (tryMatch(n, w, s) || tryMatch(n, -w, s)) {
					ok = 1;
					break;
				}
			}
			if (ok) break;
		}
	}  
	return 0;
}