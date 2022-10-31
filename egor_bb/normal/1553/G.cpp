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


const int N = 1e6 + 100;

int minDiv[N];
int par[N];

int p(int v) {
	return par[v] == v ? par[v] : par[v] = p(par[v]);
}

void merge(int v, int u) {
	v = p(v);
	u = p(u);
	par[v] = u;
}

int a[N], comp[N];
vector<int> ps[N];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	forn(i, N) {
		par[i] = i;
	}
	for(int i = 2; i < N; i++) {
		if (minDiv[i]) continue;
		for(int j = i; j < N; j += i) {
			minDiv[j] = i;
		}
	}
	int n, q;
	cin >> n >> q;
	forn(i, n) {
		int x;
		cin >> x;
		a[i] = x;
		while(x != 1) {
			ps[i].pb(minDiv[x]);
			x /= minDiv[x];
		}
		sort(all(ps[i]));
		ps[i].resize(unique(all(ps[i])) - ps[i].begin());
		forn(j, sz(ps[i]) - 1) {
			merge(ps[i][j], ps[i][j + 1]);
		}
	}
	forn(i, n) {
		comp[i] = p(ps[i][0]);
	}
	map<pii, vector<int>> qs;
	vector<int> ans;
	forn(i, q) {
		int s, t;
		cin >> s >> t;
		s--, t--;
		int cs = comp[s], ct = comp[t];
		if (cs > ct) swap(cs, ct);
		qs[mp(cs, ct)].pb(i);
		if (cs == ct) {
			ans.pb(0);
		} else {
			ans.pb(2);
		}
	}
	forn(t, n) {
		int x = a[t] + 1;
		vector<int> comps;
		comps.pb(comp[t]);
		while(x != 1) {
			comps.pb(p(minDiv[x]));
			x /= minDiv[x];
		}
		sort(all(comps));
		comps.resize(unique(all(comps)) - comps.begin());
		forn(i, sz(comps)) {
			forab(j, i + 1, sz(comps)) {
				if (qs.count(mp(comps[i], comps[j]))) {
					for (int ind : qs[mp(comps[i], comps[j])]) {
						ans[ind] = 1;
					}
					qs[mp(comps[i], comps[j])].clear();
				}
			}
		}
	}
	forn(i, q) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}