#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define all(c) (c).begin(), (c).end()
 
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5 + 100;

vector<pii> ans;
vector<int> g[N];

void dfs(int v, int par, int t) {
	ans.pb(mp(v, t));
	int ret = t;
	int maxT = sz(g[v]);
	bool swapped = false;
	int todo = sz(g[v]) - 1;
	for(int to : g[v]) {
		if (to != par) {
			if (!swapped && t + 1 > maxT) {
				ans.pb(mp(v, ret - 1 - todo));
				t = ret - 1 - todo;
				swapped = true;
			} 
			t++;
			dfs(to, v, t);
			todo--;
			ans.pb(mp(v, t));
		}
	}
	if (v && t != ret - 1) {
		ans.pb(mp(v, ret - 1));
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(0, 0, 0);
	cout << sz(ans) << '\n';
	for(auto p : ans) {
		cout << p.fst + 1 << " " << p.snd << '\n';
	}
	
    return 0;
}